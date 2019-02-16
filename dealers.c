/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dealers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbonnete <lbonnete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 15:16:24 by lbonnete          #+#    #+#             */
/*   Updated: 2019/02/16 17:49:15 by lbonnete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		deal_key(int key, t_info *info)
{
	mlx_clear_window(info->ptr, info->win);
	ft_putnbr(key);
	ft_putendl("");
	if (key == 82 || key == 29)
	{
		reset_info(info);
	}
	if (key == 35)
	{
		ft_putendl("Printing all info");
		ft_putstr("width = ");
		ft_putnbr(info->width);
		ft_putendl("");
		ft_putstr("pas = ");
		ft_putnbr(info->pas);
		ft_putendl("");
		ft_putstr("amp = ");
		ft_putnbr(info->amp);
		ft_putendl("");
	}
	if (key == 53)
	{
		mlx_destroy_window(info->ptr, info->win);
		end_fdf(info);
		exit(0);
	}
	if (key == 51)
	{
		mlx_clear_window(info->ptr, info->win);
	}
	if (key == 69)
	{
		info->width += 2;
	}
	if (key == 78)
	{
		if (info->width > 2)
			info->width -= 2;
	}
	if (key == 0)
	{
		info->amp--;
	}
	if (key == 1)
	{
		info->amp++;
	}
	if (key == 123)
	{
		ft_putendl("Moving left");
		info->start_x += info->pas;
	}
	if (key == 124)
	{
		ft_putendl("Moving right");
		info->start_x -= info->pas;
	}
	if (key == 126)
	{
		ft_putendl("Moving up");
		info->start_y += info->pas;
	}
	if (key == 125)
	{
		ft_putendl("Moving down");
		info->start_y -= info->pas;
	}
	if (key == 13)
	{
		info->pas += 2;
		ft_putstr("Pas set to : ");
		ft_putnbr(info->pas);
		ft_putendl("");
	}
	if (key == 12)
	{
		if (info->pas > 2)
			info->pas -= 2;
		ft_putstr("Pas set to : ");
		ft_putnbr(info->pas);
		ft_putendl("");
	}
	drawer(info);
	put_hud(info);
	return (0);
}

int		deal_mouse(int button, int x, int y, t_info *info)
{
	ft_putstr("x = ");
	ft_putnbr(x);
	ft_putstr(" | y = ");
	ft_putnbr(y);
	ft_putendl("");
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
		mouse_drawer(info);
		info->x1 = 0;
		info->y1 = 0;
		info->x2 = 0;
		info->y2 = 0;
		info->set = 0;
	}
	return (info->set);
}
