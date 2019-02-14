/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_edit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbonnete <lbonnete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 15:17:22 by lbonnete          #+#    #+#             */
/*   Updated: 2019/02/14 14:47:41 by lbonnete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			reset_info(t_info *info)
{
    
    info->x1 = 0;
    info->y1 = 0;
	info->x2 = 0;
    info->y2 = 0;
    info->thickness = 0;
    info->amp = 1;
    info->width = 16;
    info->angle = 0;
    info->color1 = RGB(255,255,255);
    info->color2 = 0;
	info->set = 0;
    info->pas = 4;
    info->window_height = 1080;
    info->window_width = 1920;
    info->start_x = info->window_width/2;
	info->start_y = info->window_height/2;
    info->image_height = info->window_height;
    info->image_width = info->window_width;
    info->font = RGB(0,0,0);
    ft_putendl("Info reset");
}


