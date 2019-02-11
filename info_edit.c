/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_edit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbonnete <lbonnete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 15:17:22 by lbonnete          #+#    #+#             */
/*   Updated: 2019/02/11 17:56:31 by lbonnete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
void			ft_reset_mouse_info(t_mouse_info *info)
{
    info->set = 0;
    info->x1 = 0;
    info->x2 = 0;
    info->y1 = 0;
    info->y2 = 0;
    info->thickness = 1;
    ft_putendl("Mouse info reset");
}

void			ft_reset_info(t_info *info)
{
    info->start_x = 600;
	info->start_y = 200;
    info->x1 = 0;
    info->y1 = 0;
	info->x2 = 0;
    info->y2 = 0;
    info->thickness = 0;
    info->amp = 5;
    info->width = 16;
    info->angle = 0;
    info->color1 = 0;
    info->color2 = 0;
	info->set = 0;
    ft_putendl("Info reset");
}


