/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jump.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natgomali <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 16:41:49 by natgomali         #+#    #+#             */
/*   Updated: 2025/07/21 17:13:22 by yschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	handle_jump(t_data *data)
{
	if (data->key_space == 1 && data->hovering == 0)
		data->hovering += 3;
	if (data->hovering % 3 == 0 && data->hovering > 0)
		data->hovering += 3;
	if (data->hovering == 81)
		data->hovering = 80;
	if (data->hovering % 3 != 0 && data->hovering > 0)
		data->hovering -= 3;
	if (data->hovering < 0 && data->key_ctrl == 0)
		data->hovering = 0;
}

void	handle_speed(t_data *data)
{
	if (data->key_shift == 1 && data->key_ctrl == 0)
		data->movespeed = 0.06;
	else if (data->key_shift == 0 && data->key_ctrl == 0)
		data->movespeed = 0.03;
}

void	handle_crouch(t_data *data)
{
	if (data->hovering == -1)
		data->hovering = 0;
	if (data->key_ctrl == 1 && data->hovering == 0)
	{
		data->movespeed = 0.01;
		data->hovering = -20;
	}
	if (data->key_ctrl == 0 && data->hovering == -20)
	{
		data->movespeed = 0.03;
		data->hovering = 0;
	}
}
