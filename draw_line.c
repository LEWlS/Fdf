/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbonnete <lbonnete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 13:52:58 by lbonnete          #+#    #+#             */
/*   Updated: 2019/02/11 17:54:46 by lbonnete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fdf.h"

int     draw_point(t_info *info)
{
	int x;
	int y;

    if (info->thickness == 0)
    {
         mlx_pixel_put(info->ptr, info->win, info->x1, info->y1, info->color1);
    }
    else
    {
	    if ((x = info->x1 - info->thickness) < 0)
           return (0);
    	while (x < info->x1 + info->thickness)
    	{
    		if ((y = info->y1 - info->thickness) < 0)
              return (0);
	    	while(y < info->y1 + info->thickness)
	    	{
	    		mlx_pixel_put(info->ptr, info->win, x, y, info->color1);
	    		y++;
	    	}
	    	x++;
    	}
    }
    return (1);
}

int     ft_draw_line(t_info *info)
{
	t_line line;
	int e2;

	line.dx = abs(info->x2 - info->x1);
	line.sx = info->x1 < info->x2 ? 1 : -1;
	line.dy = abs(info->y2 - info->y1);
	line.sy = info->y1 < info->y2 ? 1 : -1;
	line.err = (line.dx > line.dy ? line.dx : -line.dy) / 2;
	while (info->x1 != info->x2 && info->y1 != info->y2
    && info->x1 < 1600 && info->y1 < 900 && info->x1 > 0 && info->y1 > 0)
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
