/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsusheno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 22:04:58 by dsusheno          #+#    #+#             */
/*   Updated: 2016/04/14 21:39:36 by dsusheno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_choose_color(t_gener *s)
{
	if (s->i >= 0 && s->i < s->max_iter / 10)
		s->color = mlx_get_color_value(s->mlx_ptr, 0xDC143C);
	else if (s->i >= s->max_iter / 10 && s->i < s->max_iter / 5)
		s->color = mlx_get_color_value(s->mlx_ptr, 0xFF8C00);
	else if (s->i >= s->max_iter / 5 && s->i < 3 * s->max_iter / 10)
		s->color = mlx_get_color_value(s->mlx_ptr, 0xFFD700);
	else if (s->i >= s->max_iter * 3 / 10 && s->i < 4 * s->max_iter / 10)
		s->color = mlx_get_color_value(s->mlx_ptr, 0x7CFC00);
	else if (s->i >= s->max_iter * 4 / 10 && s->i < 5 * s->max_iter / 10)
		s->color = mlx_get_color_value(s->mlx_ptr, 0x00FFFF);
	else if (s->i >= s->max_iter * 5 / 10 && s->i < 6 * s->max_iter / 10)
		s->color = mlx_get_color_value(s->mlx_ptr, 0x0000FF);
	else if (s->i >= s->max_iter * 6 / 10 && s->i < 7 * s->max_iter / 10)
		s->color = mlx_get_color_value(s->mlx_ptr, 0xB514AA);
	else if (s->i >= s->max_iter * 7 / 10 && s->i <= s->max_iter)
		s->color = mlx_get_color_value(s->mlx_ptr, 0xD272CC);
}

void	ft_add_point(t_gener *str, int x, int y)
{
	if (x >= 0 && y >= 0 && x < 1200 && y < 800)
	{
		ft_choose_color(str);
		*(unsigned int *)(str->pixl + x * (str->bpp / 8) +
				(y * str->size_line)) = str->color;
		str->pixl[x * (str->bpp / 8) + 3 + y * str->size_line] =
			(255 - 255 * (str->i < str->max_iter));
	}
	fractal_3d(str, x, y);
}

void	fractal_3d(t_gener *str, int x, int y)
{
	double	z;
	int		x1;
	int		y1;
	int		z1;

	z = -(double)str->i / str->max_iter * 100;
	y = y + 300;
	x1 = x;
	y1 = cos(1) * y - sin(1) * z;
	z1 = sin(1) * y + cos(1) * z;
	if (x1 >= 0 && y1 >= 0 && x1 < 1200 && y1 < 800)
	{
		*(unsigned int *)(str->pixl2 + x1 * (str->bpp / 8) +
				(y1 * str->size_line)) = str->color;
		str->pixl2[x1 * (str->bpp / 8) + 3 + y1 * str->size_line] =
			(255 - 255 * (str->i < str->max_iter));
	}
}

void	ft_image_action(t_gener *s)
{
	char *iter;
	char *text;

	iter = ft_itoa(s->max_iter);
	mlx_clear_window(s->mlx_ptr, s->win_ptr);
	mlx_destroy_image(s->mlx_ptr, s->img_ptr);
	s->img_ptr = mlx_new_image(s->mlx_ptr, 1200, 800);
	mlx_clear_window(s->mlx_ptr, s->win_ptr2);
	mlx_destroy_image(s->mlx_ptr, s->img_ptr2);
	s->img_ptr2 = mlx_new_image(s->mlx_ptr, 1200, 800);
	if (s->name == 2)
		fractal_julia(s);
	else if (s->name == 1)
		fractal_mandelbrot(s);
	else if (s->name == 3)
		fractal_ship(s);
	else if (s->name == 4)
		fractal_tricorn(s);
	else if (s->name == 5)
		fractal_celtic(s);
	mlx_put_image_to_window(s->mlx_ptr, s->win_ptr, s->img_ptr, 0, 0);
	mlx_put_image_to_window(s->mlx_ptr, s->win_ptr2, s->img_ptr2, 0, 0);
	text = "Nb iteration: ";
	mlx_string_put(s->mlx_ptr, s->win_ptr, 10, 20, 0xFFFFFF, text);
	mlx_string_put(s->mlx_ptr, s->win_ptr, 10, 40, 0xFFFFFF, iter);
}

void	ft_struct_init(t_gener *s)
{
	s->c_re = -0.7;
	s->c_im = 0.27015;
	s->new_re = 0;
	s->new_im = 0;
	s->old_re = 0;
	s->old_im = 0;
	s->mlx_ptr = NULL;
	s->win_ptr = NULL;
	s->img_ptr = NULL;
	s->pixl = NULL;
	s->bpp = 0;
	s->size_line = 0;
	s->endian = 0;
	s->color = 0;
	s->max_iter = 0;
	s->i = 0;
	s->w = 0;
	s->h = 0;
	s->pi = 0;
	s->pr = 0;
	s->zoom = 1;
	s->x_zoom = 0;
	s->y_zoom = 0;
	s->move_x = 0;
	s->move_y = 0;
}
