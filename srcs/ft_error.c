/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namalier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 15:45:29 by namalier          #+#    #+#             */
/*   Updated: 2025/07/11 13:44:25 by namalier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_free_path(t_data *data)
{
	if (data->path && data->path->east != 0)
		free(data->path->east);
	if (data->path && data->path->west)
		free(data->path->west);
	if (data->path && data->path->south)
		free(data->path->south);
	if (data->path && data->path->north)
		free(data->path->north);
	if (data->path)
		free(data->path);
}

/* Check if each struct exists and free their content and it */

int	ft_error(char *str, t_data *data)
{
	ft_putstr_fd(str, 2);
	if (data->bin_tmp == 1)
		mlx_destroy_image(data->mlx, data->tmp.img);
	ft_exit_mlx(data);
	if (data)
		free(data);
	return (0);
}
