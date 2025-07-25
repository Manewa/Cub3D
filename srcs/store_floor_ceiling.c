/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_floor_ceiling.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namalier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 15:32:32 by namalier          #+#    #+#             */
/*   Updated: 2025/07/21 19:19:23 by namalier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	store_floor(char **tab, t_data *data)
{
	int	r;
	int	g;
	int	b;

	r = 0;
	g = 0;
	b = 0;
	if (tab[1])
		r = ft_atoi(tab[1]);
	if (tab[2])
		g = ft_atoi(tab[2]);
	if (tab[3])
		b = ft_atoi(tab[3]);
	if (r == -1 || g == -1 || b == -1)
		return (ft_error("Error\nA RGB value is higher than 255\n", data));
	data->path->floor = rgb_convert(r, g, b, data);
	return (1);
}

int	store_ceiling(char **tab, t_data *data)
{
	int	r;
	int	g;
	int	b;

	r = 0;
	g = 0;
	b = 0;
	if (tab[1])
		r = ft_atoi(tab[1]);
	if (tab[2])
		g = ft_atoi(tab[2]);
	if (tab[3])
		b = ft_atoi(tab[3]);
	if (r > 255 || g > 255 || b > 255)
		return (ft_error("Error\nA RGB value is higher than 255\n", data));
	data->path->ceiling = rgb_convert(r, g, b, data);
	return (1);
}
