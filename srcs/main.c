/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 12:24:41 by yschecro          #+#    #+#             */
/*   Updated: 2025/07/11 13:48:15 by namalier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	check_cub(char *str)
{
	size_t	x;

	x = ft_strlen(str);
	if (x > 4)
		x -= 4;
	if (x == 0 || (str[x - 1] && str[x - 1] == '/') || str[x] != '.'
		|| str[x + 1] != 'c' || str[x + 2] != 'u' || str[x + 3] != 'b')
	{
		ft_putstr_fd("Error\nMap is not in the right format.\n", 2);
		return (0);
	}
	else
		return (1);
}

int	main(int argc, char **argv)
{
	t_data	*data;
	int		fd;

	if (argc != 2)
	{
		ft_putstr_fd("Error\nNot exactly two arguments\n", 2);
		return (0);
	}
	if (!check_cub(argv[1]))
		return (0);
	data = init_data();
	if (!data)
		return (ft_error("Error\nMalloc error.\n", data));
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (ft_error("Error\nCan not open map file\n", data));
	data->file = get_map(fd);
	close(fd);
	if (!get_path(data, data->file))
		return (1);
	if (!check_elements(data) || !extract_map(data))
		return (1);
	if (!launcher_mlx(data))
		return (1);
	return (1);
}
