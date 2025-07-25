/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namalier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 15:42:25 by namalier          #+#    #+#             */
/*   Updated: 2025/07/11 12:50:03 by namalier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/* Check if the map is not empty or full of spaces or \n*/
static int	is_not_empty(char *str, int fd)
{
	size_t	i;

	i = 0;
	while (str && str[i] && (str[i] == '\n' || str[i] == ' '))
		i++;
	if (!str || !str[i])
	{
		printf ("Error\nMap is empty\n");
		close(fd);
		return (0);
	}
	return (1);
}

/* Get every info from the .cub in a double tab
 * check if the fd is not empty */

char	**get_map(int fd)
{
	char	*buffer;
	char	*str;
	char	*tmp;
	char	**map;

	str = malloc(1 * sizeof(char *));
	if (!str)
		return (close(fd), NULL);
	str[0] = 0;
	while (1)
	{
		buffer = get_next_line(fd);
		if (!buffer)
			break ;
		tmp = str;
		str = ft_strjoin(str, buffer);
		free (buffer);
		free (tmp);
		if (!str)
			return (close(fd), free(str), NULL);
	}
	if (!is_not_empty(str, fd))
		return (free(str), NULL);
	map = ft_split((const char *)str, "\n");
	return (free (str), map);
}

int	check_non_valid_char(char **map, char *valid, t_data *data)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			k = 0;
			while (valid[k] && map[i][j] != valid[k])
				k++;
			if (!valid[k])
				return (0);
			j++;
		}
		i++;
	}
	data->size_map = i;
	return (1);
}
