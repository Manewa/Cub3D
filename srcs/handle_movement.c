/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 16:13:43 by yschecro          #+#    #+#             */
/*   Updated: 2025/07/12 13:20:07 by natgomali        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	handle_up_n_down(t_data *data)
{
	if (data->key_up == 1)
	{
		if (data->map[(int)(data->pos.x + data->dir.x * data->movespeed * 6)]
			[(int)data->pos.y] != '1')
			data->pos.x += data->dir.x * data->movespeed;
		if (data->map[(int)data->pos.x]
			[(int)(data->pos.y + data->dir.y * data->movespeed * 6)] != '1')
			data->pos.y += data->dir.y * data->movespeed;
	}
	if (data->key_down == 1)
	{
		if (data->map[(int)(data->pos.x - data->dir.x * data->movespeed * 6)]
			[(int)data->pos.y] != '1')
			data->pos.x -= data->dir.x * data->movespeed;
		if (data->map[(int)data->pos.x]
			[(int)(data->pos.y - data->dir.y * data->movespeed * 6)] != '1')
			data->pos.y -= data->dir.y * data->movespeed;
	}
}

static void	handle_left_n_right(t_data *data)
{
	t_vector	ort;

	if (data->key_right == 1)
	{
		ort.x = data->dir.y;
		ort.y = -data->dir.x;
		if (data->map[(int)(data->pos.x + ort.x * data->movespeed * 6)]
			[(int)data->pos.y] != '1')
			data->pos.x += ort.x * data->movespeed;
		if (data->map[(int)data->pos.x]
			[(int)(data->pos.y + ort.y * data->movespeed * 6)] != '1')
			data->pos.y += ort.y * data->movespeed;
	}
	if (data->key_left == 1)
	{
		ort.x = data->dir.y;
		ort.y = -data->dir.x;
		if (data->map[(int)(data->pos.x - ort.x * data->movespeed * 6)]
			[(int)data->pos.y] != '1')
			data->pos.x -= ort.x * data->movespeed;
		if (data->map[(int)data->pos.x]
			[(int)(data->pos.y - ort.y * data->movespeed * 6)] != '1')
			data->pos.y -= ort.y * data->movespeed;
	}
}

void	handle_pan_right(t_data *data)
{
	double	olddirx;
	double	oldplanex;

	if (data->key_pan_r == 1)
	{
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
}

void	handle_pan_left(t_data *data)
{
	double	olddirx;
	double	oldplanex;

	if (data->key_pan_l == 1)
	{
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
}

void	handle_movements(t_data *data)
{
	handle_speed(data);
	handle_crouch(data);
	handle_pan_right(data);
	handle_pan_left(data);
	handle_up_n_down(data);
	handle_left_n_right(data);
}
