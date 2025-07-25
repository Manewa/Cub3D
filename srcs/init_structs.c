/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namalier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 15:16:53 by namalier          #+#    #+#             */
/*   Updated: 2025/07/21 19:24:02 by namalier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	path_new(t_data *data)
{
	data->path = malloc(sizeof(t_path));
	if (!data->path)
		return (0);
	data->path->west = 0;
	data->path->north = 0;
	data->path->south = 0;
	data->path->east = 0;
	data->path->floor = -1;
	data->path->ceiling = -1;
	return (1);
}

static void	init_keys(t_data *data)
{
	data->key_up = 0;
	data->key_down = 0;
	data->key_space = 0;
	data->key_left = 0;
	data->key_right = 0;
	data->key_pan_r = 0;
	data->key_pan_l = 0;
	data->key_shift = 0;
	data->key_ctrl = 0;
}

void	init_mlx_data(t_data *data)
{
	data->file = 0;
	data->mlx = 0;
	data->window = 0;
	data->width = 1080;
	data->height = 720;
	data->dir.x = 1;
	data->dir.y = 0;
	data->raydir.x = 0;
	data->raydir.y = 0;
	data->sidedist.x = 0;
	data->sidedist.y = 0;
	data->tmp.addr = 0;
	data->frame.addr = 0;
	data->bin_tmp = 0;
	data->bin_frame = 0;
}

t_data	*init_data(void)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	if (!path_new(data))
		return (free(data), NULL);
	init_keys(data);
	init_mlx_data(data);
	data->map = 0;
	data->wall_east = 0;
	data->wall_south = 0;
	data->wall_west = 0;
	data->wall_north = 0;
	data->plane.x = 0.;
	data->plane.y = 0.66;
	data->pos.x = 0;
	data->pos.y = 0;
	data->movespeed = 0.03;
	data->rotspeed = 0.007;
	data->side = 0;
	data->hovering = 0;
	return (data);
}
