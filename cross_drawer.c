/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cross_drawer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbonnete <lbonnete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 13:30:22 by lbonnete          #+#    #+#             */
/*   Updated: 2019/02/25 07:48:33 by lbonnete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	right_line(t_info *info, int mapx, int mapy)
{
	t_map_info	map;
	int			a;
	int			b;

	map = *info->map;
	a = (map.map)[mapy][mapx] * info->amp;
	b = (map.map)[mapy][mapx + 1] * info->amp;
	info->x1 = (mapx - mapy) * info->w + info->sx;
	info->y1 = (mapx + mapy) * (info->w / 2) + info->sy - (a);
	info->x2 = ((mapx + 1) - mapy) * info->w + info->sx;
	info->y2 = ((mapx + 1) + mapy) * (info->w / 2) + info->sy - (b);
	info->y_origine = (mapx + mapy) * (info->w / 2) + info->sy;
	draw_line(info);
}

void	bottom_line(t_info *info, int mapx, int mapy)
{
	t_map_info	map;
	int			a;
	int			b;

	map = *info->map;
	a = (map.map)[mapy][mapx] * info->amp;
	b = (map.map)[mapy + 1][mapx] * info->amp;
	info->x1 = (mapx - mapy) * info->w + info->sx;
	info->y1 = (mapx + mapy) * (info->w / 2) + info->sy - (a);
	info->x2 = (mapx - (mapy + 1)) * info->w + info->sx;
	info->y2 = (mapx + (mapy + 1)) * (info->w / 2) + info->sy - (b);
	info->y_origine = (mapx + mapy) * (info->w / 2) + info->sy;
	draw_line(info);
}

void	left_line(t_info *info, int mapx, int mapy)
{
	t_map_info	map;
	int			a;
	int			b;

	map = *info->map;
	a = (map.map)[mapy][mapx] * info->amp;
	b = (map.map)[mapy][mapx - 1] * info->amp;
	info->x1 = (mapx - mapy) * info->w + info->sx;
	info->y1 = (mapx + mapy) * (info->w / 2) + info->sy - (a);
	info->x2 = ((mapx - 1) - mapy) * info->w + info->sx;
	info->y2 = ((mapx - 1) + mapy) * (info->w / 2) + info->sy - (b);
	info->y_origine = (mapx + mapy) * (info->w / 2) + info->sy;
	draw_line(info);
}

void	upper_line(t_info *info, int mapx, int mapy)
{
	t_map_info	map;
	int			a;
	int			b;

	map = *info->map;
	a = (map.map)[mapy][mapx] * info->amp;
	b = (map.map)[mapy - 1][mapx] * info->amp;
	info->x1 = (mapx - mapy) * info->w + info->sx;
	info->y1 = (mapx + mapy) * (info->w / 2) + info->sy - (a);
	info->x2 = (mapx - (mapy - 1)) * info->w + info->sx;
	info->y2 = (mapx + (mapy - 1)) * (info->w / 2) + info->sy - (b);
	info->y_origine = (mapx + mapy) * (info->w / 2) + info->sy;
	draw_line(info);
}
