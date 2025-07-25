/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namalier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 16:20:03 by namalier          #+#    #+#             */
/*   Updated: 2025/07/11 12:51:28 by namalier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	up_n_down(t_data *data, int keycode)
{
	if (keycode == 119)
	{
		if (data->map[(int)(data->pos.x + data->dir.x * data->movespeed)]
				[(int)data->pos.y] != '1')
			data->pos.x += data->dir.x * data->movespeed;
		if (data->map[(int)data->pos.x]
			[(int)(data->pos.y + data->dir.y * data->movespeed)] != '1')
			data->pos.y += data->dir.y * data->movespeed;
	}
	else if (keycode == 115)
	{
		if (data->map[(int)(data->pos.x - data->dir.x * data->movespeed)]
				[(int)data->pos.y] != '1')
			data->pos.x -= data->dir.x * data->movespeed;
		if (data->map[(int)data->pos.x]
			[(int)(data->pos.y - data->dir.y * data->movespeed)] != '1')
			data->pos.y -= data->dir.y * data->movespeed;
	}
}

void	right_key(t_data *data)
{
	t_vector	ort;

	ort.x = data->dir.y;
	ort.y = -data->dir.x;
	if (data->map[(int)(data->pos.x + ort.x * data->movespeed)]
			[(int)data->pos.y] != '1')
		data->pos.x += ort.x * data->movespeed;
	if (data->map[(int)data->pos.x]
		[(int)(data->pos.y + ort.y * data->movespeed)] != '1')
		data->pos.y += ort.y * data->movespeed;
}

void	left_key(t_data *data)
{
	t_vector	ort;

	ort.x = data->dir.y;
	ort.y = -data->dir.x;
	if (data->map[(int)(data->pos.x - ort.x * data->movespeed)]
			[(int)data->pos.y] != '1')
		data->pos.x -= ort.x * data->movespeed;
	if (data->map[(int)data->pos.x]
		[(int)(data->pos.y - ort.y * data->movespeed)] != '1')
		data->pos.y -= ort.y * data->movespeed;
}

void	pan_right(t_data *data)
{
	double	olddirx;
	double	oldplanex;

	olddirx = data->dir.x;
	oldplanex = data->plane.x;
	data->dir.x = data->dir.x * cos((-data->rotspeed))
		- data->dir.y * sin((-data->rotspeed));
	data->dir.y = olddirx * sin((-data->rotspeed))
		+ data->dir.y * cos((-data->rotspeed));
	data->plane.x = data->plane.x * cos((-data->rotspeed))
		- data->plane.y * sin((-data->rotspeed));
	data->plane.y = oldplanex * sin((-data->rotspeed))
		+ data->plane.y * cos((-data->rotspeed));
}

void	pan_left(t_data *data)
{
	double	olddirx;
	double	oldplanex;

	oldplanex = data->plane.x;
	olddirx = data->dir.x;
	data->dir.x = data->dir.x * cos(data->rotspeed)
		- data->dir.y * sin(data->rotspeed);
	data->dir.y = olddirx * sin(data->rotspeed)
		+ data->dir.y * cos(data->rotspeed);
	data->plane.x = data->plane.x * cos(data->rotspeed)
		- data->plane.y * sin(data->rotspeed);
	data->plane.y = oldplanex * sin(data->rotspeed)
		+ data->plane.y * cos(data->rotspeed);
}
