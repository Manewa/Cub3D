/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natgomali <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 17:29:22 by natgomali         #+#    #+#             */
/*   Updated: 2025/07/11 15:59:48 by namalier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	**choose_texture(t_data *data)
{
	if (data->side == 0)
	{
		if (data->raydir.x > 0)
			return (data->wall_south);
		else
			return (data->wall_north);
	}
	else
	{
		if (data->raydir.y > 0)
			return (data->wall_east);
		else
			return (data->wall_west);
	}
}

int	ft_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

void	print_line(int len, int pos, t_data *data, double dist)
{
	double	img_step;
	double	j;
	int		y_start;
	int		y_end;
	int		y;

	img_step = 512.0 / (double)len;
	y_start = ft_max(0, data->height / 2 - len / 2 + data->hovering);
	y_end = ft_min(data->height, data->height / 2 + len / 2 + data->hovering);
	j = (y_start - data->hovering - (data->height / 2 - len / 2)) * img_step;
	if (j < 0)
		j = 0;
	y = y_start;
	while (y < y_end)
	{
		img_pixel_put(data, pos, y,
			fog_of_war(get_color(data, j, dist), dist, 2));
		j += img_step;
		y++;
	}
}
