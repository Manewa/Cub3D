/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_stuff.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 17:20:49 by yschecro          #+#    #+#             */
/*   Updated: 2025/07/21 17:40:16 by yschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	render_ceiling(t_data *data, int x, int y_start)
{
	int	y;

	y = 0;
	while (y < y_start)
	{
		img_pixel_put(data, x, y, data->path->ceiling);
		y++;
	}
}

void	render_wall(t_data *data, int x, int y_start, int y_end)
{
	double	img_step;
	double	j;
	int		y;
	int		size;

	size = ((int)((double)data->height / data->dist));
	img_step = 512.0 / (double)size;
	j = (y_start - data->hovering - (data->height / 2 - size / 2)) * img_step;
	if (j < 0)
		j = 0;
	y = y_start;
	while (y < y_end)
	{
		img_pixel_put(data, x, y,
			fog_of_war(get_color(data, j, data->dist), data->dist, 2));
		j += img_step;
		y++;
	}
}

void	render_floor(t_data *data, int x, int y_end)
{
	int	y;
	int	color;

	y = y_end;
	while (y < data->height)
	{
		color = fog_of_war(data->path->floor,
				((data->height - y) / 3.6) + 20, 20);
		img_pixel_put(data, x, y, color);
		y++;
	}
}
