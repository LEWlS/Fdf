/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proj_caval.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbonnete <lbonnete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 17:06:32 by trabut            #+#    #+#             */
/*   Updated: 2019/02/20 14:32:30 by lbonnete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_links_caval(t_info *info)
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
				right_line_caval(info, mapx, mapy);
			if (mapy + 1 < map.hauteur)
				bottom_line_caval(info, mapx, mapy);
			if (mapx - 1 >= 0)
				left_line_caval(info, mapx, mapy);
			if (mapy - 1 >= 0)
				upper_line_caval(info, mapx, mapy);
			mapx++;
		}
		mapy++;
	}
}
