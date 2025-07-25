/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launcher_mlx.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namalier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 14:10:47 by namalier          #+#    #+#             */
/*   Updated: 2025/07/11 15:29:51 by namalier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	destroy(t_data *data)
{
	mlx_destroy_window(data->mlx, data->window);
	return (1);
}

static void	ft_free_inttab(int **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return ;
	while (i < 512)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	ft_exit_mlx(t_data *data)
{
	if (data->bin_frame == 1)
		mlx_destroy_image(data->mlx, data->frame.img);
	if (data->window)
		mlx_destroy_window(data->mlx, data->window);
	if (data && data->map)
		ft_free_doubletab(data->map);
	if (data && data->path)
		ft_free_path(data);
	if (data && data->file)
		ft_free_doubletab(data->file);
	if (data->wall_north)
		ft_free_inttab(data->wall_north);
	if (data->wall_south)
		ft_free_inttab(data->wall_south);
	if (data->wall_east)
		ft_free_inttab(data->wall_east);
	if (data->wall_west)
		ft_free_inttab(data->wall_west);
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
}

int	square(t_data *data)
{
	mlx_loop_end(data->mlx);
	return (1);
}

int	launcher_mlx(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		return (ft_error("Error\nMlx init crash.\n", data));
	data->frame.img = mlx_new_image(data->mlx, 1080, 720);
	if (!data->frame.img)
		return (ft_error("Error\nMlx new image crash.\n", data));
	data->bin_frame = 1;
	data->frame.addr = mlx_get_data_addr(data->frame.img, &data->frame.bpp,
			&data->frame.line_len, &data->frame.endian);
	data->window = mlx_new_window(data->mlx, 1080, 720, "CUBUUUUUUUUUUU");
	if (!data->window)
		return (ft_error("Error\nWindow crash.\n", data));
	if (!store_sprites(data))
		return (0);
	mlx_mouse_hide(data->mlx, data->window);
	mlx_hook(data->window, 2, 1L << 0, &keydown, data);
	mlx_hook(data->window, 3, 1L << 1, &keyup, data);
	mlx_hook(data->window, 17, 1L << 17, square, data);
	mlx_hook(data->window, 6, 1L << 6, mouse_move, data);
	mlx_loop_hook(data->mlx, &render_walls, data);
	mlx_loop(data->mlx);
	mlx_mouse_show(data->mlx, data->window);
	ft_exit_mlx(data);
	free(data);
	return (1);
}
