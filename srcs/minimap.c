/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natgomali <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 12:36:37 by natgomali         #+#    #+#             */
/*   Updated: 2025/07/11 16:12:31 by namalier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	draw_square(t_data *data, int x, int y, int color)
{
	img_pixel_put(data, x, y, color);
	img_pixel_put(data, x + 1, y, color);
	img_pixel_put(data, x + 2, y, color);
	img_pixel_put(data, x + 3, y, color);
	img_pixel_put(data, x, y + 1, color);
	img_pixel_put(data, x + 1, y + 1, color);
	img_pixel_put(data, x + 2, y + 1, color);
	img_pixel_put(data, x + 3, y + 1, color);
	img_pixel_put(data, x, y + 2, color);
	img_pixel_put(data, x + 1, y + 2, color);
	img_pixel_put(data, x + 2, y + 2, color);
	img_pixel_put(data, x + 3, y + 2, color);
	img_pixel_put(data, x, y + 3, color);
	img_pixel_put(data, x + 1, y + 3, color);
	img_pixel_put(data, x + 2, y + 3, color);
	img_pixel_put(data, x + 3, y + 3, color);
}

static void	color_minimap(t_data *data, int i, int j, int color)
{
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == '1' || data->map[i][j] == 'N'
				|| data->map[i][j] == 'E' || data->map[i][j] == 'W'
				|| data->map[i][j] == 'S')
				color = 0xFFFFFF;
			else if (data->map[i][j] == '0')
				color = 0x222222;
			else if (data->map[i][j] == ' ')
			{
				j++;
				continue ;
			}
			else
				color = 0x000000;
			draw_square(data, j * 5, i * 5, color);
			j++;
		}
		i++;
	}
}

void	draw_minimap(t_data *data)
{
	int	i;
	int	j;
	int	color;

	i = 0;
	color = 0;
	j = 0;
	color_minimap(data, i, j, color);
}
