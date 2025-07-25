/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_n_effect.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namalier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 15:57:46 by namalier          #+#    #+#             */
/*   Updated: 2025/07/21 17:18:11 by yschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	get_color(t_data *data, double y, double dist)
{
	float			wall_x;
	unsigned long	tex_x;

	if (data->side == 0)
		wall_x = data->pos.y + dist * data->raydir.y;
	else
		wall_x = data->pos.x + dist * data->raydir.x;
	wall_x -= floor(wall_x);
	tex_x = (int)(wall_x * 512);
	if ((data->side == 0 && data->raydir.x > 0)
		|| (data->side == 1 && data->raydir.y < 0))
		tex_x = 512 - tex_x - 1;
	return (choose_texture(data)[(int)y][tex_x]);
}

int	change_to_tv(int nframe, int y)
{
	int	r;
	int	g;
	int	b;

	b = rand() % 122 + 120 * sin(nframe / 2 + y / 10) / 20 + 50;
	g = b;
	r = g;
	return ((r << 16) | (g << 8) | b);
}

int	tv_effect(t_data *data)
{
	int			x;
	int			y;
	static int	nframe = 0;

	x = 0;
	if (nframe == 180)
		nframe = 0;
	while (x < data->width)
	{
		y = 0;
		while (y < data->height)
		{
			img_pixel_put(data, x, y, change_to_tv(nframe, y));
			y += rand() % 20;
		}
		x++;
	}
	nframe++;
	return (0);
}

int	fog_of_war(int color, double dist, int ratio)
{
	int	r;
	int	g;
	int	b;

	r = (color >> 16) & 0xFF;
	g = (color >> 8) & 0xFF;
	b = color & 0xFF;
	if (dist >= 2)
	{
		r /= dist / ratio;
		g /= dist / ratio;
		b /= dist / ratio;
	}
	return ((r << 16) | (g << 8) | b);
}
