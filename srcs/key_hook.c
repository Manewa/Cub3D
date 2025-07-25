/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namalier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 15:53:10 by namalier          #+#    #+#             */
/*   Updated: 2025/07/21 16:27:47 by namalier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/* 119	= w
 * 115	= s
 * 97	= a
 * 100	= d
 * 65362= <-
 * 65364= ->
 */

int	key_hook(int keycode, t_data *data)
{
	if (keycode == 65307)
		square(data);
	else if (keycode == 119 || keycode == 115)
		up_n_down(data, keycode);
	else if (keycode == 97)
		left_key(data);
	else if (keycode == 100)
		right_key(data);
	else if (keycode == 65361)
		pan_left(data);
	else if (keycode == 65363)
		pan_right(data);
	return (1);
}

int	keydown(int keycode, t_data *data)
{
	if (keycode == 65307)
		square(data);
	else if (keycode == 119)
		data->key_up = 1;
	else if (keycode == 115)
		data->key_down = 1;
	else if (keycode == 97)
		data->key_left = 1;
	else if (keycode == 100)
		data->key_right = 1;
	else if (keycode == 65361)
		data->key_pan_l = 1;
	else if (keycode == 65363)
		data->key_pan_r = 1;
	else if (keycode == 32)
		data->key_space = 1;
	else if (keycode == 65505)
		data->key_shift = 1;
	else if (keycode == 65507)
		data->key_ctrl = 1;
	return (0);
}

int	keyup(int keycode, t_data *data)
{
	if (keycode == 119)
		data->key_up = 0;
	else if (keycode == 115)
		data->key_down = 0;
	else if (keycode == 97)
		data->key_left = 0;
	else if (keycode == 100)
		data->key_right = 0;
	else if (keycode == 65361)
		data->key_pan_l = 0;
	else if (keycode == 65363)
		data->key_pan_r = 0;
	else if (keycode == 32)
		data->key_space = 0;
	else if (keycode == 65505)
		data->key_shift = 0;
	else if (keycode == 65507)
		data->key_ctrl = 0;
	return (0);
}
