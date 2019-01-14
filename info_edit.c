/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_edit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbonnete <lbonnete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 15:17:22 by lbonnete          #+#    #+#             */
/*   Updated: 2019/01/14 16:27:08 by lbonnete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
void			ft_resest_mouse_info(t_mouse_info *info)
{
    info->set = 0;
    info->x1 = 0;
    info->x2 = 0;
    info->y1 = 0;
    info->y2 = 0;
}

void			ft_resest_info(t_info *info)
{
    info->x1 = 0;
    info->y1 = 0;
	info->x2 = 0;
    info->y2 = 0;
    info->unit = 0;
    info->thickness = 0;
    info->angle = 0;
    info->color1 = 0;
    info->color2 = 0;
	info->set = 0;
}


