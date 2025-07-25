/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 17:25:12 by yschecro          #+#    #+#             */
/*   Updated: 2025/07/21 17:38:14 by yschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_vector	get_deltadist(t_data *data)
{
	data->deltadist.x = fabs(1 / data->raydir.x);
	data->deltadist.y = fabs(1 / data->raydir.y);
	return (data->deltadist);
}

t_vector	get_sidedist(t_data *data)
{
	if (data->raydir.x < 0)
	{
		data->step.x = -1;
		data->sidedist.x = (data->pos.x - data->raypos_x) * data->deltadist.x;
	}
	else
	{
		data->step.x = 1;
		data->sidedist.x = (data->raypos_x + 1.0 - data->pos.x)
			* data->deltadist.x;
	}
	if (data->raydir.y < 0)
	{
		data->step.y = -1;
		data->sidedist.y = (data->pos.y - data->raypos_y) * data->deltadist.y;
	}
	else
	{
		data->step.y = 1;
		data->sidedist.y = (data->raypos_y + 1.0 - data->pos.y)
			* data->deltadist.y;
	}
	return (data->sidedist);
}

void	avoid_zeros(t_vector *vector)
{
	if (vector->x == 0.)
		vector->x = 0.0000000001;
	if (vector->y == 0.)
		vector->y = 0.0000000001;
}
