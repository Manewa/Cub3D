/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namalier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 17:47:03 by namalier          #+#    #+#             */
/*   Updated: 2025/07/11 15:25:33 by namalier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	get_map_row_len_with_spaces(char *line)
{
	int	i;
	int	last;

	i = 0;
	last = 0;
	if (!line)
		return (0);
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\n')
			last = i + 1;
		i++;
	}
	return (last);
}

static void	get_row_n_height(t_data *data)
{
	int	i;
	int	row;

	i = 0;
	data->map_row = 0;
	while (data->map[i])
	{
		row = get_map_row_len_with_spaces(data->map[i]);
		if (row > data->map_row)
			data->map_row = row;
		i++;
	}
	data->map_height = i;
}

int	ft_floodfill(t_data *data, int x, int y)
{
	get_row_n_height(data);
	if (y < 0 || y > data->map_row)
		return (0);
	if (x < 0 || x > data->map_height)
		return (0);
	if (!data->map[x] || !data->map[x][y] || data->map[x][y] == ' ')
		return (0);
	if (data->map[x] && data->map[x][y]
		&& (data->map[x][y] == '1' || data->map[x][y] == '2'))
		return (1);
	data->map[x][y] = '2';
	if (!ft_floodfill(data, x + 1, y))
		return (0);
	if (!ft_floodfill(data, x - 1, y))
		return (0);
	if (!ft_floodfill(data, x, y + 1))
		return (0);
	if (!ft_floodfill(data, x, y - 1))
		return (0);
	return (1);
}

int	checks_map(t_data *data)
{
	size_t	i;
	size_t	j;
	int		spawn_point;

	i = 1;
	spawn_point = 0;
	while (data->map[i])
	{
		j = 1;
		while (data->map[i][j] && data->map[i][j] != 'N'
				&& data->map[i][j] != 'S' && data->map[i][j] != 'W'
				&& data->map[i][j] != 'E')
			j++;
		if (data->map[i][j])
		{
			spawn_point++;
			cardinal_vector(data->map[i][j], data, i, j);
		}
		i++;
	}
	if (data->pos.x == 0 || data->pos.y == 0 || spawn_point != 1)
		return (ft_error("Error\nError in spawning point.\n", data));
	if (!ft_floodfill(data, data->pos.x, data->pos.y))
		return (ft_error("Error\nFloodfill failed.\n", data));
	return (1);
}
