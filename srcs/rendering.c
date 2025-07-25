/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 14:51:22 by yschecro          #+#    #+#             */
/*   Updated: 2025/07/01 17:39:05 by natgomali        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	img_pixel_put(t_data *data, int x, int y, int color)
{
	char	*pixel;

	if (x < data->width && y < data->height && x >= 0 && y >= 0)
	{
		pixel = data->frame.addr + (y * data->frame.line_len + x
				* (data->frame.bpp / 8));
		*(unsigned int *)pixel = color;
	}
}

void	render(t_data *data)
{
	mlx_put_image_to_window(data->mlx, data->window, data->frame.img, 0, 0);
}
