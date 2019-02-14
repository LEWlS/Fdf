/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbonnete <lbonnete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 13:52:58 by lbonnete          #+#    #+#             */
/*   Updated: 2019/02/14 17:13:36 by lbonnete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fdf.h"

int     draw_point(t_info *info)
{
	int x;
	int y;

    if (info->thickness == 0)
    {
        img_mod(info->x1, info->y1, info);
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
	    		img_mod(x, y, info);
	    		y++;
	    	}
	    	x++;
    	}
    }
    return (1);
}

int     draw_line(t_info *info)
{
	t_line line;
	int e2;

	line.dx = abs(info->x2 - info->x1);
	line.sx = info->x1 < info->x2 ? 1 : -1;
	line.dy = abs(info->y2 - info->y1);
	line.sy = info->y1 < info->y2 ? 1 : -1;
	line.err = (line.dx > line.dy ? line.dx : -line.dy) / 2;
	while ((info->x1 != info->x2 || info->y1 != info->y2)
    && info->x1 < info->image_width && info->y1 < info->image_height && info->x1 >= 0 && info->y1 >= 0)
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

void    img_mod(int x, int y, t_info *info)
{
    int pos;
	int color_diff;

	if (info->hud_cap)
	{
		pos = x * 4;
    	pos += y * info->image_width * 4;
    	if (pos + 2 < info->image_width * 4 * info->image_height && pos >= 0)
    	{
    	    info->addr[pos + 2] = 90;
    	    info->addr[pos + 1] = 0;
    	    info->addr[pos] = 90;
    	}

	}
	else
	{
		color_diff = abs(info->y_origine - y);
    	pos = x * 4;
    	pos += y * info->image_width * 4;
    	if (pos + 2 < info->image_width * 4 * info->image_height && pos >= 0)
    	{
    	    info->addr[pos + 2] = 90;
    	    info->addr[pos + 1] = color_diff;
    	    info->addr[pos] = 90;
    	}
	}
}
