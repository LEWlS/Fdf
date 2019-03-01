/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trabut <trabut@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 14:41:13 by lbonnete          #+#    #+#             */
/*   Updated: 2019/02/25 12:33:59 by trabut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	drawer(t_info *info)
{
	int bpp;
	int size_l;
	int endian;

	bpp = 32;
	size_l = info->iw * 4;
	endian = 0;
	info->im = mlx_new_image(info->pt, info->iw, info->ih);
	info->addr = mlx_get_data_addr(info->im, &bpp, &size_l, &endian);
	if (info->proj == 1)
		draw_links(info);
	else
		draw_links_caval(info);
	put_hud(info);
	mlx_put_image_to_window(info->pt, info->wn, info->im, info->ix, info->iy);
	mlx_destroy_image(info->pt, info->im);
}

void	draw_links(t_info *info)
{
	t_map_info	map;
	int			mapx;
	int			mapy;

	map = *(info->map);
	mapx = 0;
	mapy = 0;
	while (mapy < map.hauteur)
	{
		mapx = 0;
		while (mapx < map.longueur)
		{
			if (mapx + 1 < map.longueur)
				right_line(info, mapx, mapy);
			if (mapy + 1 < map.hauteur)
				bottom_line(info, mapx, mapy);
			if (mapx - 1 >= 0)
				left_line(info, mapx, mapy);
			if (mapy - 1 >= 0)
				upper_line(info, mapx, mapy);
			mapx++;
		}
		mapy++;
	}
}
