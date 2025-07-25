/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_mouse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 17:29:52 by yschecro          #+#    #+#             */
/*   Updated: 2025/07/21 16:16:41 by namalier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	handle_mouse_right(t_data *data)
{
	double	olddirx;
	double	oldplanex;

	olddirx = data->dir.x;
	oldplanex = data->plane.x;
	data->dir.x = data->dir.x * cos((-data->rotspeed / 2))
		- data->dir.y * sin((-data->rotspeed / 2));
	data->dir.y = olddirx * sin((-data->rotspeed / 2))
		+ data->dir.y * cos((-data->rotspeed / 2));
	data->plane.x = data->plane.x * cos((-data->rotspeed / 2))
		- data->plane.y * sin((-data->rotspeed / 2));
	data->plane.y = oldplanex * sin((-data->rotspeed / 2))
		+ data->plane.y * cos((-data->rotspeed / 2));
}

void	handle_mouse_left(t_data *data)
{
	double	olddirx;
	double	oldplanex;

	oldplanex = data->plane.x;
	olddirx = data->dir.x;
	data->dir.x = data->dir.x * cos(data->rotspeed / 4)
		- data->dir.y * sin(data->rotspeed / 4);
	data->dir.y = olddirx * sin(data->rotspeed / 4)
		+ data->dir.y * cos(data->rotspeed / 4);
	data->plane.x = data->plane.x * cos(data->rotspeed / 4)
		- data->plane.y * sin(data->rotspeed / 4);
	data->plane.y = oldplanex * sin(data->rotspeed / 4)
		+ data->plane.y * cos(data->rotspeed / 4);
}

int	mouse_move(int x, int y, t_data *param)
{
	int	i;

	i = 0;
	(void)y;
	if (x != 540)
	{
		i = 0;
		while (i < abs(540 - x))
		{
			if (540 - x >= 1)
				handle_mouse_left(param);
			else
				handle_mouse_right(param);
			i++;
		}
	}
	return (0);
}
