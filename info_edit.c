/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_edit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbonnete <lbonnete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 15:17:22 by lbonnete          #+#    #+#             */
/*   Updated: 2019/02/18 15:36:51 by lbonnete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			reset_info(t_info *info)
{
    t_map_info map;

    map = *(info->map);
    info->x1 = 0;
    info->y1 = 0;
	info->x2 = 0;
    info->y2 = 0;
    info->amp = 1;
    info->width = 32;
    info->color1 = RGB(255,255,255);
    info->color2 = 0;
	info->set = 0;
    info->pas = 50;
    info->hud_cap = 0;
    info->window_height = 1080;
    info->window_width = 1920;
    info->start_x = info->window_width / 2 - ((map.longueur / 2) * info->width);
	info->start_y = info->window_height / 2 - ((map.hauteur / 2) * info->width);
    info->image_height = info->window_height - 50;
    info->image_width = 6 * info->window_width / 8 ;
    info->image_x = info->window_width / 8;
    info->image_y = 75;
}


