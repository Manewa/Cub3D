/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 12:17:34 by yschecro          #+#    #+#             */
/*   Updated: 2025/07/21 19:29:12 by namalier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../mlx_linux/mlx.h"
# include <stddef.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <math.h>
# include <fcntl.h>
# include <X11/keysymdef.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include "structs.h"
# include "../libft/libft.h"

/***	launcher_mlx	***/

int			launcher_mlx(t_data *data);

/***	init_structs	***/

t_data		*init_data(void);

/***	ft_error		***/

int			ft_error(char *str, t_data *data);

/**		get_map			***/

char		**get_map(int fd);

/***	rendering	 	***/

int			get_path(t_data *data, char **map);
void		render(t_data *data);
void		img_pixel_put(t_data *data, int x, int y, int color);
void		draw_line(t_data *data, int x, int size, int color);
int			store_floor(char **tab, t_data *data);
int			store_ceiling(char **tab, t_data *data);
int			rgb_convert(int r, int g, int b, t_data *data);
void		cardinal_vector(char c, t_data *data, int i, int j);
int			check_non_valid_char(char **map, char *valid, t_data *data);
int			extract_map(t_data *data);
int			render_walls(t_data *data);
int			print_key(int keycode, void *param);
int			key_hook(int keycode, t_data *param);
int			square(t_data *data);
void		up_n_down(t_data *data, int keycode);
void		left_key(t_data *data);
void		right_key(t_data *data);
void		pan_right(t_data *data);
void		pan_left(t_data *data);
int			check_color(char *color);
int			check_elements(t_data *data);
int			store_sprites(t_data *data);
int			**choose_texture(t_data *data);
void		print_line(int len, int pos, t_data *data, double dist);
void		ft_free_path(t_data *data);
void		draw_minimap(t_data *data);
void		draw_square(t_data *data, int x, int y, int color);
int			keyup(int keycode, t_data *data);
int			keydown(int keycode, t_data *data);
void		handle_movements(t_data *data);
int			checks_map(t_data *data);
int			fog_of_war(int color, double dist, int ratio);
void		handle_pan_left(t_data *data);
void		handle_pan_right(t_data *data);
int			mouse_move(int x, int y, t_data *param);
int			tv_effect(t_data *data);
void		handle_jump(t_data *data);
int			get_color(t_data *data, double y, double dist);
int			ft_min(int a, int b);
int			ft_max(int a, int b);
void		ft_exit_mlx(t_data *data);
void		east_west_vector(char c, t_data *data);
void		handle_speed(t_data *data);
void		handle_crouch(t_data *data);
t_vector	get_deltadist(t_data *data);
t_vector	get_sidedist(t_data *data);
void		avoid_zeros(t_vector *vector);
void		render_ceiling(t_data *data, int x, int y_start);
void		render_wall(t_data *data, int x, int y_start, int y_end);
void		render_floor(t_data *data, int x, int y_end);
int			check_textures(t_data *data);

#endif
