/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsusheno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 16:27:16 by dsusheno          #+#    #+#             */
/*   Updated: 2016/04/12 16:27:35 by dsusheno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#define DISP_X (s->x_zoom * s->zoom)
#define DISP_Y (s->y_zoom * s->zoom)

void	fractal_julia(t_gener *s)
{
	t_fract		f;

	f.y = s->y_zoom - 1 / s->zoom;
	while ((f.y += 1 / s->zoom) < s->y_zoom + 800 / s->zoom)
	{
		f.x = s->x_zoom - 1 / s->zoom;
		while ((f.x += 1 / s->zoom) < s->x_zoom + 1200 / s->zoom)
		{
			s->new_re = 1.5 * (f.x - 600) / 600 + s->move_x;
			s->new_im = (f.y - 400) / 400 + s->move_y;
			s->i = -1;
			while (++s->i < s->max_iter &&
				s->new_re * s->new_re + s->new_im * s->new_im <= 4)
			{
				s->old_re = s->new_re;
				s->old_im = s->new_im;
				s->new_re = s->old_re * s->old_re -
				s->old_im * s->old_im + s->c_re;
				s->new_im = 2 * s->old_re * s->old_im + s->c_im;
			}
			ft_add_point(s, f.x * s->zoom - DISP_X, f.y * s->zoom - DISP_Y);
		}
	}
}

void	fractal_mandelbrot(t_gener *s)
{
	t_fract		f;

	f.y = s->y_zoom - 1 / s->zoom;
	while ((f.y += 1 / s->zoom) < s->y_zoom + 800 / s->zoom)
	{
		f.x = s->x_zoom - 1 / s->zoom;
		while ((f.x += 1 / s->zoom) < s->x_zoom + 1200 / s->zoom)
		{
			s->pr = 1.5 * (f.x - 600) / 600 - 0.5 + s->move_x;
			s->pi = (f.y - 400) / 400 + s->move_y;
			s->new_re = 0;
			s->new_im = 0;
			s->i = -1;
			while (++s->i < s->max_iter &&
				s->new_re * s->new_re + s->new_im * s->new_im <= 4)
			{
				s->old_re = s->new_re;
				s->old_im = s->new_im;
				s->new_re = s->old_re * s->old_re -
				s->old_im * s->old_im + s->pr;
				s->new_im = 2 * s->old_re * s->old_im + s->pi;
			}
			ft_add_point(s, f.x * s->zoom - DISP_X, f.y * s->zoom - DISP_Y);
		}
	}
}

void	fractal_tricorn(t_gener *s)
{
	t_fract		f;

	f.y = s->y_zoom - 1 / s->zoom;
	while ((f.y += 1 / s->zoom) < s->y_zoom + 800 / s->zoom)
	{
		f.x = s->x_zoom - 1 / s->zoom;
		while ((f.x += 1 / s->zoom) < s->x_zoom + 1200 / s->zoom)
		{
			s->pr = 1.5 * (f.x - 600) / 400 + s->move_x;
			s->pi = (f.y - 400) / 300 + s->move_y;
			s->new_re = 0;
			s->new_im = 0;
			s->i = -1;
			while (++s->i < s->max_iter &&
				s->new_re * s->new_re + s->new_im * s->new_im <= 4)
			{
				s->old_re = s->new_re;
				s->old_im = s->new_im;
				s->new_re = s->old_re * s->old_re -
				s->old_im * s->old_im + s->pr;
				s->new_im = -2 * s->old_re * s->old_im + s->pi;
			}
			ft_add_point(s, f.x * s->zoom - DISP_X, f.y * s->zoom - DISP_Y);
		}
	}
}

void	fractal_ship(t_gener *s)
{
	t_fract		f;

	f.y = s->y_zoom - 1 / s->zoom;
	while ((f.y += 1 / s->zoom) < s->y_zoom + 800 / s->zoom)
	{
		f.x = s->x_zoom - 1 / s->zoom;
		while ((f.x += 1 / s->zoom) < s->x_zoom + 1200 / s->zoom)
		{
			s->pr = (f.x - 600) / 400 - 0.5 + s->move_x;
			s->pi = (f.y - 400) / 400 - 0.5 + s->move_y;
			s->new_re = 0;
			s->new_im = 0;
			s->i = -1;
			while (++s->i < s->max_iter &&
				s->new_re * s->new_re + s->new_im * s->new_im <= 4)
			{
				s->old_re = (s->new_re >= 0) ? s->new_re : -s->new_re;
				s->old_im = (s->new_im >= 0) ? s->new_im : -s->new_im;
				s->new_re = s->old_re * s->old_re -
				s->old_im * s->old_im + s->pr;
				s->new_im = 2 * s->old_re * s->old_im + s->pi;
			}
			ft_add_point(s, f.x * s->zoom - DISP_X, f.y * s->zoom - DISP_Y);
		}
	}
}

void	fractal_celtic(t_gener *s)
{
	t_fract		f;

	f.y = s->y_zoom - 1 / s->zoom;
	while ((f.y += 1 / s->zoom) < s->y_zoom + 800 / s->zoom)
	{
		f.x = s->x_zoom - 1 / s->zoom;
		while ((f.x += 1 / s->zoom) < s->x_zoom + 1200 / s->zoom)
		{
			s->pr = 1.5 * (f.x - 600) / 400 - 0.5 + s->move_x;
			s->pi = (f.y - 400) / 300 + s->move_y;
			s->new_re = 0;
			s->new_im = 0;
			s->i = -1;
			while (++s->i < s->max_iter &&
				s->new_re * s->new_re + s->new_im * s->new_im <= 4)
			{
				s->old_re = s->new_re;
				s->old_im = s->new_im;
				s->new_re = fabsl(s->old_re * s->old_re -
					s->old_im * s->old_im) + s->pr;
				s->new_im = 2 * s->old_re * s->old_im + s->pi;
			}
			ft_add_point(s, f.x * s->zoom - DISP_X, f.y * s->zoom - DISP_Y);
		}
	}
}
