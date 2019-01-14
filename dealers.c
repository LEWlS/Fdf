/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dealers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbonnete <lbonnete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 15:16:24 by lbonnete          #+#    #+#             */
/*   Updated: 2019/01/14 16:24:45 by lbonnete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		deal_key(int key, t_info *try)
{
	ft_putnbr(key);
	ft_putendl("");
	if (key == 53)
	{
		mlx_destroy_window(try->ptr, try->win);
		exit(0);
	}
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
		ft_resest_mouse_info(info);
	}
	return (info->set);
}
