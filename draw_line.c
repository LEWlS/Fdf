/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbonnete <lbonnete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 13:52:58 by lbonnete          #+#    #+#             */
/*   Updated: 2019/02/11 14:00:02 by lbonnete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fdf.h"

void	draw_point(t_info *info, int x1, int y1, int x2, int y2)
{
	int x;
	int y;

	x = x1 - info->thickness;
	while (x < x1 + info->thickness)
	{
		y = y1 - info->thickness;
		while(y < y1 + info->thickness)
		{
			mlx_pixel_put(info->ptr, info->win, x, y, info->color1);
			y++;
		}
		x++;
	}
}

int             ft_draw_line(t_info *info, int x1, int y1, int x2, int y2)
{
	t_line line;
	int e2;

	line.dx = abs(x2 - x1);
	line.sx = x1 < x2 ? 1 : -1;
	line.dy = abs(y2 - y1);
	line.sy = y1 < y2 ? 1 : -1;
	line.err = (line.dx > line.dy ? line.dx : -line.dy) / 2;
	while (x1 != x2 && y1 != y2)
	{
		draw_point(info, x1, y1, x2, y2);
		e2 = line.err;
		if (e2 > -line.dx)
		{
			line.err -= line.dy;
			x1 += line.sx;
		}
		if (e2 < line.dy)
		{
			line.err += line.dx;
			y1 += line.sy;
		}
	}
	return (1);
}
