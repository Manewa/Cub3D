/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cardinal_vector.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namalier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 15:25:13 by namalier          #+#    #+#             */
/*   Updated: 2025/07/21 16:17:05 by namalier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	cardinal_vector(char c, t_data *data, int i, int j)
{
	data->pos.x = i + 0.5;
	data->pos.y = j + 0.5;
	if (c == 'S')
	{
		data->dir.x = 1;
		data->dir.y = 0;
		data->plane.x = 0;
		data->plane.y = 0.66;
	}
	else if (c == 'N')
	{
		data->dir.x = -1;
		data->dir.y = 0;
		data->plane.x = 0;
		data->plane.y = -0.66;
	}
	else
		east_west_vector(c, data);
}

void	east_west_vector(char c, t_data *data)
{
	if (c == 'E')
	{
		data->dir.x = 0;
		data->dir.y = 1;
		data->plane.x = -0.66;
		data->plane.y = 0;
	}
	else if (c == 'W')
	{
		data->dir.x = 0;
		data->dir.y = -1;
		data->plane.x = 0.66;
		data->plane.y = 0;
	}
}
