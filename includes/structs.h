/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namalier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 14:21:11 by namalier          #+#    #+#             */
/*   Updated: 2025/07/21 19:31:51 by namalier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include <unistd.h>

typedef struct s_vector
{
	double	x;
	double	y;
}	t_vector;

typedef struct s_path
{
	char	*east;
	char	*west;
	char	*north;
	char	*south;
	int		ceiling;
	int		floor;
}	t_path;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		line_len;
	int		bpp;
	int		endian;
}	t_img;

typedef struct s_data
{
	int			width;
	int			height;
	void		*mlx;
	void		*window;
	t_img		frame;
	t_img		tmp;
	t_path		*path;
	char		**map;
	char		**file;
	int			bin_tmp;
	int			bin_frame;
	int			map_row;
	int			map_height;
	int			**collec;
	int			**tree;
	int			**wall_east;
	int			**wall_west;
	int			**wall_north;
	int			**wall_south;
	int			side;
	int			begin_map;
	int			size_map;
	t_vector	pos;
	t_vector	dir;
	t_vector	raydir;
	t_vector	step;
	t_vector	deltadist;
	int			raypos_y;
	int			raypos_x;
	t_vector	sidedist;
	t_vector	plane;
	t_vector	camera;
	double		movespeed;
	double		rotspeed;
	int			key_up;
	int			key_down;
	int			key_left;
	int			key_right;
	int			key_pan_l;
	int			key_pan_r;
	int			key_space;
	int			key_shift;
	int			key_ctrl;
	int			hovering;
	double		dist;
}				t_data;

#endif
