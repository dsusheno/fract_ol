/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsusheno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 22:03:33 by dsusheno          #+#    #+#             */
/*   Updated: 2016/04/12 17:07:16 by dsusheno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_mouse(int button, int x, int y, void *param)
{
	t_gener		*s;

	s = (t_gener *)param;
	if (button == 5)
	{
		s->zoom *= 2;
		s->x_zoom = x / (s->zoom / 2) + s->x_zoom - x / s->zoom;
		s->y_zoom = y / (s->zoom / 2) + s->y_zoom - y / s->zoom;
	}
	if (button == 4)
	{
		s->x_zoom = s->x_zoom - x / s->zoom;
		s->y_zoom = s->y_zoom - y / s->zoom;
		s->zoom /= 2;
	}
	ft_image_action(s);
	return (0);
}

int		ft_mouse_loop(int x, int y, void *param)
{
	double long	x1;
	double long	y1;
	t_gener		*s;

	x1 = x;
	y1 = y;
	s = (t_gener *)param;
	if (s->name == 2)
	{
		s->c_re = -0.7 + x1 / 1000;
		s->c_im = 0.27015 + y1 / 1000;
		ft_image_action(s);
	}
	return (0);
}

void	my_key_fonction2(int key, t_gener *str)
{
	if (key == 258 || key == 269 || key == 126
			|| key == 125 || key == 124 || key == 123
			|| key == 27 || key == 24)
	{
		if (key == 258)
			str->max_iter += 5;
		else if (key == 24)
			str->max_iter += 50;
		else if (key == 269)
			str->max_iter += (str->max_iter > 5) ? -5 : 0;
		else if (key == 27)
			str->max_iter += (str->max_iter > 50) ? -50 : 0;
		else if (key == 126)
			str->move_y += (0.1 / str->zoom);
		else if (key == 125)
			str->move_y -= (0.1 / str->zoom);
		else if (key == 123)
			str->move_x += (0.1 / str->zoom);
		else if (key == 124)
			str->move_x -= (0.1 / str->zoom);
		ft_image_action(str);
	}
}

int		my_key_fonction(int key, void *param)
{
	t_gener		*str;

	str = (t_gener *)param;
	if (key == 53 || key == 47 || key == 43)
	{
		if (key == 53)
			exit(0);
		if (key == 47)
			str->name += (str->name < 5) ? 1 : -4;
		else if (key == 43)
			str->name += (str->name > 1) ? -1 : +4;
		str->zoom = 1;
		str->x_zoom = 0;
		str->y_zoom = 0;
		str->move_x = 0;
		str->move_y = 0;
		ft_image_action(str);
	}
	my_key_fonction2(key, str);
	return (0);
}
