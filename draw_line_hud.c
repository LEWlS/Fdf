/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line_hud.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbonnete <lbonnete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 13:52:58 by lbonnete          #+#    #+#             */
/*   Updated: 2019/02/16 17:22:12 by lbonnete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fdf.h"

int     draw_line_hud(t_info *info)
{
	t_line line;
	int e2;

	line.dx = abs(info->x2 - info->x1);
	line.sx = info->x1 < info->x2 ? 1 : -1;
	line.dy = abs(info->y2 - info->y1);
	line.sy = info->y1 < info->y2 ? 1 : -1;
	line.err = (line.dx > line.dy ? line.dx : -line.dy) / 2;
	while ((info->x1 != info->x2 || info->y1 != info->y2)
    && info->x1 < info->window_width && info->y1 < info->window_height && info->x1 >= 0 && info->y1 >= 0)
	{
		mlx_pixel_put(info->ptr, info->win, info->x1, info->y1, RGB(255, 255, 255));
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
