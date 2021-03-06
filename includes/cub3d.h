/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sglossu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 21:28:39 by sglossu           #+#    #+#             */
/*   Updated: 2022/01/28 21:28:41 by sglossu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../mlx/mlx.h"
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>
# include <unistd.h>

# define FORWARD 13
# define BACK 1
# define LEFT 0
# define RIGHT 2
# define ROTATE_LEFT 123
# define ROTATE_RIGHT 124
# define ESC 53
# define M 46

typedef struct s_check {
	int			r;
	int			so;
	int			we;
	int			ea;
	int			no;
	int			c;
	int			f;
	int			done;
}				t_check;

typedef struct s_info {
	int			*size;
	int			*x;
	int			*y;
	double		*luchi_array;
}				t_info;

typedef struct s_data {
	void		*img;
	void		*mlx;
	void		*mlx_win;
	char		*addr;
	int			tex_width;
	int			tex_height;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	char		*path;
}				t_data;

typedef struct s_tex {
	int			floor_color;
	int			ceiling_color;
	t_data		s;
	t_data		w;
	t_data		e;
	t_data		n;
}				t_tex;

typedef struct s_ray {
	double		pdx;
	double		pdy;
	double		pa;
	double		px;
	double		py;
	double		x;
	double		y;
}				t_ray;

typedef struct s_all {
	int			width;
	int			height;
	int			side;
	char		**map;
	int			scale;
	int			minimap_flag;
	int			longer_string;
	int			cnt;
	t_ray		ray;
	t_data		win;
	t_tex		tex;
	t_info		info;
	t_check		check;
}				t_all;

int				get_next_line(int fd, char **line);
void			init_arrays(t_all *all);
void			init_struct(t_all *all);
void			init_checker(t_all *all);
void			draw(t_all *all);
void			draw_floor(t_all *all);
void			draw_3d(t_all *all, int wall, int luchi, double k);
void			refresh_vars(t_all *all);
int				valid_keys(char c, char d);
void			open_map(t_all *all, char *file_name);
void			player_detect(t_all *all, int lines, int i);
void			map_hole_check(t_all *all, int line_max);
void			color_parser(t_all *all, char *s, char c, int i);
void			tex_parser(t_all *all, char *s, int code);
void			tex_parser2(t_all *all, char *s, int code);
void			resolution_parser(t_all *all, char *s);
void			init_map_to_buffer(t_all *all);
int				key_hook(int keycode, t_all *all);
void			isdone(t_all *all);
int				no_clip(t_all *all, int a);
void			no_clip2(t_all *all, int a, double *temppx, double *temppy);
int				check_cub_extension(char *s);
int				check_xpm_extension(char *s);
int				access_symbols(char c);
void			new_image(t_all *all);
void			pxl(t_data *win, int x, int y, int color);
int				get_color(t_data *polar, int x, int y);
double			fix_ang(double f);
int				rgb_to_hex(int r, int g, int b);
size_t			ft_strlen(char *str);
char			*ft_strdup(const char *str);
char			*ft_strdup_modified(t_all *all, const char *str);
int				ft_atoi(const char *str);
int				ft_isdigit(int ch);
void			ft_error(int code);
void			error_check(t_all *all);
int				if_error_open(char *av);

#endif
