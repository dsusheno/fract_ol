/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsusheno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/20 17:33:47 by dsusheno          #+#    #+#             */
/*   Updated: 2016/05/10 11:56:44 by dsusheno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include "libft.h"
# include <stdio.h>
# include <math.h>
# include "get_next_line.h"

typedef struct		s_gener
{
	double long		c_re;
	double long		c_im;
	double long		new_re;
	double long		new_im;
	double long		old_re;
	double long		old_im;
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	char			*pixl;
	int				bpp;
	int				size_line;
	int				endian;
	unsigned int	color;
	double			max_iter;
	int				i;
	int				w;
	int				h;
	int				name;
	double long		pi;
	double long		pr;
	double long		zoom;
	double long		x_zoom;
	double long		y_zoom;
	double long		move_x;
	double long		move_y;
	char			*text;
	int				bpp2;
	char			*pixl2;
	int				endian2;
	int				size_line2;
	void			*win_ptr2;
	void			*img_ptr2;
}					t_gener;

typedef struct		s_fractal
{
	double long y;
	double long x;
}					t_fract;

void				fractal_julia(t_gener *s);
void				fractal_mandelbrot(t_gener *s);
void				fractal_ship(t_gener *s);
void				fractal_biomorph(t_gener *s);
void				fractal_tricorn(t_gener *s);
void				fractal_celtic(t_gener *s);
void				ft_text_put(t_gener *str);
void				ft_image_action(t_gener *s);
void				ft_add_point(t_gener *str, int x, int y);
int					ft_mouse(int button, int x, int y, void *param);
int					ft_mouse_loop(int x, int y, void *param);
int					my_key_fonction(int key, void *param);
void				ft_struct_init(t_gener *s);
void				fractal_3d(t_gener *str, int x, int y);

#endif
