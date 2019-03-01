/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbonnete <lbonnete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 13:52:58 by lbonnete          #+#    #+#             */
/*   Updated: 2019/02/22 18:13:43 by trabut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		draw_line_condition(t_info *info)
{
	return ((info->x1 != info->x2 || info->y1 != info->y2)
		&& info->x1 < info->iw
		&& info->y1 < info->ih && info->x1 >= 0 && info->y1 >= 0);
}

int		draw_line(t_info *info)
{
	t_line	line;
	int		e2;

	line.dx = abs(info->x2 - info->x1);
	line.sx = info->x1 < info->x2 ? 1 : -1;
	line.dy = abs(info->y2 - info->y1);
	line.sy = info->y1 < info->y2 ? 1 : -1;
	line.err = (line.dx > line.dy ? line.dx : -line.dy) / 2;
	while (draw_line_condition(info))
	{
		img_mod(info->x1, info->y1, info);
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

void	img_mod(int x, int y, t_info *info)
{
	int pos;
	int color_diff;

	color_diff = abs(info->y_origine - y);
	pos = x * 4;
	pos += y * info->iw * 4;
	if (pos + 2 < info->iw * 4 * info->ih && pos >= 0)
	{
		info->addr[pos + 2] = color_diff > 127 ? 127 : color_diff;
		info->addr[pos + 1] = color_diff > 127 ? 127 : color_diff + 30;
		info->addr[pos] = 90;
	}
}
