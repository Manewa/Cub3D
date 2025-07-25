/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_sprites.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natgomali <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 17:23:20 by natgomali         #+#    #+#             */
/*   Updated: 2025/07/22 14:06:27 by namalier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	check_textures(t_data *data)
{
	if (data->path->north == 0 || data->path->south == 0
		|| data->path->east == 0
		|| data->path->west == 0
		|| data->path->floor == -1
		|| data->path->ceiling == -1)
		return (ft_error("Error\nSame texture assigned multiple times.\n",
				data));
	return (1);
}

static int	**parse_sprites(char *pix, t_data **data)
{
	int		i;
	int		j;
	int		k;
	int		**tab;

	i = 0;
	k = 0;
	tab = malloc(sizeof(int *) * 512);
	while (i < 512)
	{
		j = 0;
		tab[i] = malloc(sizeof(int) * 512);
		while (j < 512)
		{
			tab[i][j] = rgb_convert((unsigned char)pix[k + 2],
					(unsigned char)pix[k + 1], (unsigned char)pix[k], *data);
			k += 4;
			j++;
		}
		i++;
	}
	mlx_destroy_image((*data)->mlx, (*data)->tmp.img);
	(*data)->bin_tmp = 0;
	return (tab);
}

static int	**open_sprites(char *path, t_data **data)
{
	int		x;
	int		y;

	(*data)->tmp.img = mlx_xpm_file_to_image((*data)->mlx, path, &x, &y);
	if (!(*data)->tmp.img)
	{
		printf("Error\nFailed to open sprite.\n");
		return (NULL);
	}
	else if (x != 512 || y != 512)
	{
		mlx_destroy_image((*data)->mlx, (*data)->tmp.img);
		printf("Error\nWrong sprite size.\n");
		return (NULL);
	}
	(*data)->bin_tmp = 1;
	(*data)->tmp.addr = mlx_get_data_addr((*data)->tmp.img,
			&(*data)->tmp.bpp, &(*data)->tmp.line_len, &(*data)->tmp.endian);
	return (parse_sprites((*data)->tmp.addr, data));
}

int	store_sprites(t_data *data)
{
	data->width = 1080;
	data->height = 720;
	data->wall_north = open_sprites(data->path->north, &data);
	if (!data->wall_north)
		return (ft_error("", data));
	data->wall_south = open_sprites(data->path->south, &data);
	if (!data->wall_south)
		return (ft_error("", data));
	data->wall_west = open_sprites(data->path->west, &data);
	if (!data->wall_west)
		return (ft_error("", data));
	data->wall_east = open_sprites(data->path->east, &data);
	if (!data->wall_east)
		return (ft_error("", data));
	return (1);
}
