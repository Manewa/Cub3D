/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namalier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 18:18:43 by namalier          #+#    #+#             */
/*   Updated: 2025/07/11 16:27:53 by namalier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	check_xpm(char *str)
{
	size_t	x;

	x = ft_strlen(str);
	if (x > 4)
		x -= 4;
	if (x == 0 || (str[x - 1] && str[x - 1] == '/') || str[x] != '.'
		|| str[x + 1] != 'x' || str[x + 2] != 'p' || str[x + 3] != 'm')
		return (0);
	else
		return (1);
}

int	check_color(char *s)
{
	size_t	i;
	int		count;

	count = 0;
	i = 1;
	while (s[i] && (s[i] == ' ' || s[i] == ',' || (s[i] >= '0' && s[i] <= '9')))
	{
		i = out_of_spaces(i, s);
		if (!s[i] || s[i] == ',')
			return (0);
		if (s[i] && s[i] <= '0' && s[i] >= '9')
			return (0);
		else if (s[i] && s[i] >= '0' && s[i] <= '9')
			count++;
		while (s[i] && s[i] >= '0' && s[i] <= '9')
			i++;
		i = out_of_spaces(i, s);
		if (s[i] && s[i] == ',')
			i++;
		else if (s[i])
			return (0);
	}
	if (count != 3)
		return (0);
	return (1);
}

int	check_elements(t_data *data)
{
	if (!check_xpm(data->path->east) || !check_xpm(data->path->west)
		|| !check_xpm(data->path->north) || !check_xpm(data->path->south))
		return (ft_error("Error\nA wall is not an XPM file\n", data));
	return (1);
}
