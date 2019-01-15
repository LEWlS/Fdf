/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbonnete <lbonnete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 18:19:54 by lbonnete          #+#    #+#             */
/*   Updated: 2019/01/15 17:03:01 by lbonnete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fdf.h"

void	draw_point(t_mouse_info *info)
{
	int x;
	int y;

	x = info->x1 - info->thickness;
	while (x < info->x1 + info->thickness)
	{
		y = info->y1 - info->thickness;
		while(y < info->y1 + info->thickness)
		{
			mlx_pixel_put(info->ptr, info->win, x, y, info->color);
			y++;
		}
		x++;
	}
}

int             ft_draw_line_mouse(t_mouse_info *info)
{
	t_line line;
	int e2;

	line.dx = abs(info->x2 - info->x1);
	line.sx = info->x1 < info->x2 ? 1 : -1;
	line.dy = abs(info->y2 - info->y1);
	line.sy = info->y1 < info->y2 ? 1 : -1;
	line.err = (line.dx > line.dy ? line.dx : -line.dy) / 2;
	while (info->x1 !=info->x2 && info->y1 != info->y2)
	{
		draw_point(info);
		e2 = line.err;
		if (e2 > -line.dx)
		{
			line.err -= line.dy;
			info->x1 += line.sx;
		}
		if (e2 < line.dy)
		{
			line.err += line.dx;
			info->y1 += line.sy;
		}
	}
	return (1);
}
