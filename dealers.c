/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dealers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbonnete <lbonnete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 15:16:24 by lbonnete          #+#    #+#             */
/*   Updated: 2019/02/13 13:55:53 by lbonnete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		deal_key(int key, t_info *info)
{
	ft_putnbr(key);
	ft_putendl("");
	if (key == 53)
	{
		mlx_destroy_window(info->ptr, info->win);
		exit(0);
	}
	if (key == 51)
	{
		put_font(info);
	}
	if (key == 69)
	{
		put_font(info);
		info->width++;
		draw_links(info);
	}
	if (key == 78)
	{
		put_font(info);
		if (info->width > 1)
			info->width--;
		draw_links(info);
	}
	if (key == 17)
	{
		if (info->thickness > 0)
			info->thickness--;
		ft_putstr("thickness set to :");
		ft_putnbr(info->thickness);
		ft_putendl("");
	}
		if (key == 16)
	{
		if (info->thickness < 10)
			info->thickness++;
		ft_putstr("thickness set to :");
		ft_putnbr(info->thickness);
		ft_putendl("");
	}
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
		ft_draw_line(info);
		info->x1 = 0;
		info->y1 = 0;
		info->x2 = 0;
		info->y2 = 0;
		info->set = 0;
	}
	return (info->set);
}
