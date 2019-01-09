/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbonnete <lbonnete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 15:40:23 by lbonnete          #+#    #+#             */
/*   Updated: 2019/01/09 17:58:22 by lbonnete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_resest_info(t_mouse_info *info)
{
	info->x1 = 0;
	info->y1 = 0;
	info->x2 = 0;
	info->y2 = 0;
	info->set = 0;
}

int		deal_key(int key, t_info *try)
{
	ft_putnbr(key);
	ft_putendl("");
	if (key == 53)
	{
		mlx_destroy_window(try->ptr, try->win);
		exit(0);
	}
	else
		put_new_square(try, key, 20);
	return (0);
}

int		deal_mouse(int button, int x, int y, t_mouse_info *info)
{
	if (info->set == 0)
	{
		info->x1 = x;
		info->y1 = y;
		info->set = 1;
	}
	else
	{
		info->x2 = x;
		info->y2 = y;
		ft_draw_line_mouse(info);
		ft_resest_info(info);
	}
	return (info->set);
}

int		main(void)
{
	t_info			try;
	t_mouse_info	info;

	try.x = 500;
	try.y = 500;
	try.color = 123;
	try.ptr = mlx_init();
	try.win = mlx_new_window(try.ptr, 1600, 900, "New");
	info.ptr = try.ptr;
	info.win = try.win;
	info.color = 000255255255;
	info.set = 0;
	mlx_mouse_hook(try.win, deal_mouse, &info);
	mlx_key_hook(try.win, deal_key, &try);
	mlx_loop(try.ptr);
	return (0);
}
