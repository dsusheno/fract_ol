/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsusheno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/20 17:31:54 by dsusheno          #+#    #+#             */
/*   Updated: 2016/04/14 21:35:52 by dsusheno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_choose_fractal(char **str, t_gener *s)
{
	if (!ft_strcmp(str[1], "Mandelbrot"))
		s->name = 1;
	else if (!ft_strcmp(str[1], "Julia"))
		s->name = 2;
	else if (!ft_strcmp(str[1], "BurningShip"))
		s->name = 3;
	else if (!ft_strcmp(str[1], "Tricorn"))
		s->name = 4;
	else if (!ft_strcmp(str[1], "Celtic"))
		s->name = 5;
	else
		return (0);
	return (1);
}

int		ft_iteration(char **str, t_gener *s)
{
	int i;

	i = -1;
	while (str[2][++i])
		if (!ft_isdigit(str[2][i]))
			return (0);
	s->max_iter = ft_getnbr(str[2]);
	if (s->max_iter <= 0)
		return (0);
	return (1);
}

void	ft_text_put2(t_gener *s, void *win_ptr, char *text)
{
	text = "Move Fractal right: Right arrow Button";
	mlx_string_put(s->mlx_ptr, win_ptr, 10, 160, 0xFFFFFF, text);
	text = "Iteration +5      : Shift";
	mlx_string_put(s->mlx_ptr, win_ptr, 10, 180, 0xFFFFFF, text);
	text = "Iteration -5      : Right control";
	mlx_string_put(s->mlx_ptr, win_ptr, 10, 200, 0xFFFFFF, text);
	text = "Iteration +50     : +";
	mlx_string_put(s->mlx_ptr, win_ptr, 10, 220, 0xFFFFFF, text);
	text = "Iteration -50     : -";
	mlx_string_put(s->mlx_ptr, win_ptr, 10, 240, 0xFFFFFF, text);
	text = "Parameters of Fractal Julia:";
	mlx_string_put(s->mlx_ptr, win_ptr, 10, 260, 0xFFFFFF, text);
	text = "Mouse position.";
	mlx_string_put(s->mlx_ptr, win_ptr, 10, 280, 0xFFFFFF, text);
	text = "You can only work with the first window.";
	mlx_string_put(s->mlx_ptr, win_ptr, 5, 340, 0xFFFFFF, text);
	text = "3D projection is at the second window.";
	mlx_string_put(s->mlx_ptr, win_ptr, 5, 360, 0xFFFFFF, text);
}

void	ft_text_put(t_gener *s)
{
	void	*win_ptr;
	char	*text;

	if (!(win_ptr = mlx_new_window(s->mlx_ptr, 400, 800, "Menu")))
		return ;
	text = "Menu:";
	mlx_string_put(s->mlx_ptr, win_ptr, 10, 20, 0xFFFFFF, text);
	text = "Zoom +            : Scrolling Up";
	mlx_string_put(s->mlx_ptr, win_ptr, 10, 40, 0xFFFFFF, text);
	text = "Zoom -            : Scrolling Down";
	mlx_string_put(s->mlx_ptr, win_ptr, 10, 60, 0xFFFFFF, text);
	text = "Change Fractal <- : < Button";
	mlx_string_put(s->mlx_ptr, win_ptr, 10, 80, 0xFFFFFF, text);
	text = "Change Fractal -> : > Button";
	mlx_string_put(s->mlx_ptr, win_ptr, 10, 100, 0xFFFFFF, text);
	text = "Exit              : Esc";
	mlx_string_put(s->mlx_ptr, win_ptr, 10, 120, 0xFFFFFF, text);
	text = "Move Fractal left : Left arrow Button";
	mlx_string_put(s->mlx_ptr, win_ptr, 10, 140, 0xFFFFFF, text);
	ft_text_put2(s, win_ptr, text);
}

int		main(int argc, char **argv)
{
	t_gener s;

	ft_struct_init(&s);
	if (argc != 3 || !ft_choose_fractal(argv, &s) || !ft_iteration(argv, &s))
	{
		ft_putstrn("fract'ol: you need to enter just one name of Fractal\n"
				"(BurningShip, Mandelbrot, Tricorn, Celtic or Julia)\n"
				"and number of iteration (>0) after space");
		return (0);
	}
	if (!(s.mlx_ptr = mlx_init()) ||
			!(s.win_ptr = mlx_new_window(s.mlx_ptr, 1200, 800, "Fract'ol"))
			|| !(s.win_ptr2 = mlx_new_window(s.mlx_ptr, 1200, 800, "Fract'3D")))
		return (0);
	s.img_ptr = mlx_new_image(s.mlx_ptr, 1200, 800);
	s.img_ptr2 = mlx_new_image(s.mlx_ptr, 1200, 800);
	s.pixl = mlx_get_data_addr(s.img_ptr, &s.bpp, &s.size_line, &s.endian);
	s.pixl2 = mlx_get_data_addr(s.img_ptr2, &s.bpp, &s.size_line, &s.endian);
	ft_image_action(&s);
	ft_text_put(&s);
	mlx_mouse_hook(s.win_ptr, ft_mouse, &s);
	mlx_key_hook(s.win_ptr, my_key_fonction, &s);
	mlx_hook(s.win_ptr, 6, (1L << 6), ft_mouse_loop, &s);
	mlx_loop(s.mlx_ptr);
	return (0);
}
