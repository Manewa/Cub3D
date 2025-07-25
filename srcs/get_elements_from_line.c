/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_elements_from_line.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namalier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 13:49:27 by namalier          #+#    #+#             */
/*   Updated: 2025/07/21 19:10:54 by namalier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	rgb_convert(int r, int g, int b, t_data *data)
{
	if (r < 0 || b < 0 || g < 0)
		return (ft_error("Error\nInvalid color value.\n", data), -1);
	return ((r << 16) | (g << 8) | b);
}

int	store_elements(char ***path, t_data *data)
{
	int	i;

	i = 0;
	while (path[i])
	{
		if (ft_strcmp(path[i][0], "NO") == 0 && data->path->north == 0)
			data->path->north = ft_strdup(path[i][1]);
		if (ft_strcmp(path[i][0], "SO") == 0 && data->path->south == 0)
			data->path->south = ft_strdup(path[i][1]);
		if (ft_strcmp(path[i][0], "WE") == 0 && data->path->west == 0)
			data->path->west = ft_strdup(path[i][1]);
		if (ft_strcmp(path[i][0], "EA") == 0 && data->path->east == 0)
			data->path->east = ft_strdup(path[i][1]);
		if (ft_strcmp(path[i][0], "F") == 0 && data->path->floor == -1)
			if (!store_floor(path[i], data))
				return (0);
		if (ft_strcmp(path[i][0], "C") == 0 && data->path->ceiling == -1)
			if (!store_ceiling(path[i], data))
				return (0);
		i++;
	}
	return (1);
}

char	**get_elements_from_line(char *line)
{
	int		i;
	char	**out;

	i = 0;
	while (ft_isspace(line[i]))
		i++;
	if (ft_strncmp("NO ", line + i, 3) == 0
		|| ft_strncmp("SO ", line + i, 3) == 0
		|| ft_strncmp("EA ", line + i, 3) == 0
		|| ft_strncmp("WE ", line + i, 3) == 0)
	{	
		out = ft_split(line, "\t\v\n\r\f ");
		return (out);
	}
	else if (ft_strncmp("C ", line + i, 2) == 0
		|| ft_strncmp("F ", line + i, 2) == 0)
	{
		if (!check_color(line + i))
			return (0);
		out = ft_split(line, "\t\v\n\r\f ,");
		return (out);
	}
	return (0);
}

int	get_path(t_data *data, char **map)
{
	char	***path;
	int		i;
	int		n_r_value;

	i = 0;
	n_r_value = 0;
	path = ft_calloc(sizeof(char **), 7);
	if (!path)
		return (ft_error("Error\nMalloc error.\n", data));
	while (map[i] && n_r_value != 6)
	{
		path[n_r_value] = get_elements_from_line(map[i]);
		if (path[n_r_value])
			n_r_value++;
		else
			free(path[n_r_value]);
		i++;
		data->begin_map = i;
	}
	if (n_r_value != 6)
		return (ft_free_tripletab(path), ft_error("Error\nMap incomplete.\n", \
			data));
	if (!store_elements(path, data) || !check_textures(data))
		return (ft_free_tripletab(path), 0);
	return (ft_free_tripletab(path), 1);
}

int	extract_map(t_data *data)
{
	int	i;

	i = 0;
	if (!check_non_valid_char(data->file + data->begin_map, "01 NSWE", data))
		return (ft_error("Error\nInvalid characters\n", data));
	data->map = ft_calloc(sizeof(char *), data->size_map + 1);
	if (!data->map)
		return (ft_error("Error\nMalloc error\n", data));
	while (i < data->size_map)
	{
		data->map[i] = ft_strdup(data->file[data->begin_map + i]);
		if (!data->map[i])
			return (ft_error("Error\nMalloc error\n", data));
		i++;
	}
	if (!checks_map(data))
		return (0);
	return (1);
}
