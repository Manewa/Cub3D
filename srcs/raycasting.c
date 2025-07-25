/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 15:53:16 by yschecro          #+#    #+#             */
/*   Updated: 2025/07/21 17:39:53 by yschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include <math.h>

void	raycast(t_data *data)
{
	double	stepx;
	double	stepy;
	int		hit;

	hit = 0;
	stepx = data->step.x;
	stepy = data->step.y;
	while (hit == 0)
	{
		if (data->sidedist.x < data->sidedist.y)
		{
			data->sidedist.x += data->deltadist.x;
			data->raypos_x += stepx;
			data->side = 0;
		}
		else
		{
			data->sidedist.y += data->deltadist.y;
			data->raypos_y += stepy;
			data->side = 1;
		}
		if (data->map[(int)data->raypos_x][(int)data->raypos_y] == '1')
			hit = 1;
	}
}

double	ddr_algo(t_data *data)
{
	double	dist;

	dist = 0.;
	avoid_zeros(&data->dir);
	avoid_zeros(&data->raydir);
	data->deltadist = get_deltadist(data);
	data->sidedist = get_sidedist(data);
	raycast(data);
	if (data->side == 0)
		dist = (data->sidedist.x - data->deltadist.x);
	else
		dist = (data->sidedist.y - data->deltadist.y);
	if (dist == 0)
		return (0.00000000001);
	return (dist);
}

void	draw_line(t_data *data, int x, int size, int color)
{
	int	i;
	int	y;

	i = 0;
	y = data->height / 2 - size / 2;
	while (i < size)
	{
		img_pixel_put(data, x, y, color);
		i++;
		y++;
	}
}

void	render_walls_utils(t_data *data)
{
	handle_jump(data);
	handle_movements(data);
	draw_minimap(data);
	draw_square(data, data->pos.y * 5 - 2, data->pos.x * 5 - 2,
		0xFF0000);
	tv_effect(data);
	mlx_mouse_move(data->mlx, data->window, data->width / 2, data->height / 2);
	mlx_put_image_to_window(data->mlx, data->window, data->frame.img, 0, 0);
}

int	render_walls(t_data *data)
{
	int		x;
	int		size;
	int		y_start;
	int		y_nd;

	x = 0;
	while (x < data->width)
	{
		data->camera.x = 2 * x / (double)data->width - 1;
		data->raydir.x = data->dir.x - data->plane.x * data->camera.x;
		data->raydir.y = data->dir.y - data->plane.y * data->camera.x;
		data->raypos_x = data->pos.x;
		data->raypos_y = data->pos.y;
		data->dist = ddr_algo(data);
		size = (int)((double)data->height / data->dist);
		y_start = ft_max(0, data->height / 2 - size / 2 + data->hovering);
		y_nd = ft_min(data->height, (data->height + size) / 2 + data->hovering);
		render_ceiling(data, x, y_start);
		render_wall(data, x, y_start, y_nd);
		render_floor(data, x, y_nd);
		x++;
	}
	render_walls_utils(data);
	return (0);
}
