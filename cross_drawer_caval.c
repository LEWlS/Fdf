/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cross_drawer_caval.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbonnete <lbonnete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 13:30:22 by lbonnete          #+#    #+#             */
/*   Updated: 2019/02/25 08:07:09 by lbonnete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	right_line_caval(t_info *info, int mapx, int mapy)
{
	t_map_info	map;
	int			a;
	int			b;

	map = *info->map;
	a = (map.map)[mapy][mapx] * info->amp;
	b = (map.map)[mapy][mapx + 1] * info->amp;
	info->x1 = (mapx) * info->w + info->sx + (a);
	info->y1 = (mapy) * (info->w) + info->sy - (a);
	info->x2 = (mapx + 1) * info->w + info->sx + (b);
	info->y2 = (mapy) * (info->w) + info->sy - (b);
	info->y_origine = (mapy) * (info->w) + info->sy;
	draw_line(info);
}

void	bottom_line_caval(t_info *info, int mapx, int mapy)
{
	t_map_info	map;
	int			a;
	int			b;

	map = *info->map;
	a = (map.map)[mapy][mapx] * info->amp;
	b = (map.map)[mapy + 1][mapx] * info->amp;
	info->x1 = (mapx) * info->w + info->sx + (a);
	info->y1 = (mapy) * (info->w) + info->sy - (a);
	info->x2 = (mapx) * info->w + info->sx + (b);
	info->y2 = (mapy + 1) * (info->w) + info->sy - (b);
	info->y_origine = (mapy) * (info->w) + info->sy;
	draw_line(info);
}

void	left_line_caval(t_info *info, int mapx, int mapy)
{
	t_map_info	map;
	int			a;
	int			b;

	map = *info->map;
	a = (map.map)[mapy][mapx] * info->amp;
	b = (map.map)[mapy][mapx - 1] * info->amp;
	info->x1 = (mapx) * info->w + info->sx + (a);
	info->y1 = (mapy) * (info->w) + info->sy - (a);
	info->x2 = (mapx - 1) * info->w + info->sx + (b);
	info->y2 = (mapy) * (info->w) + info->sy - (b);
	info->y_origine = (mapy) * (info->w) + info->sy;
	draw_line(info);
}

void	upper_line_caval(t_info *info, int mapx, int mapy)
{
	t_map_info	map;
	int			a;
	int			b;

	map = *info->map;
	a = (map.map)[mapy][mapx] * info->amp;
	b = (map.map)[mapy - 1][mapx] * info->amp;
	info->x1 = (mapx) * info->w + info->sx + (a);
	info->y1 = (mapy) * (info->w) + info->sy - (a);
	info->x2 = (mapx) * info->w + info->sx + (b);
	info->y2 = (mapy - 1) * (info->w) + info->sy - (b);
	info->y_origine = (mapy) * (info->w) + info->sy;
	draw_line(info);
}
