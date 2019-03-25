/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_edit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbonnete <lbonnete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 15:17:22 by lbonnete          #+#    #+#             */
/*   Updated: 2019/03/25 17:34:32 by lbonnete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	char_info(t_info *info)
{
	info->csx = ft_itoa(info->sx);
	info->csy = ft_itoa(info->sy);
	info->cpas = ft_itoa(info->pas);
	info->camp = ft_itoa(info->amp);
	info->cproj = ft_itoa(info->proj);
	info->cw = ft_itoa(info->w);
}

void	reset_info(t_info *info)
{
	t_map_info map;

	map = *(info->map);
	info->x1 = 0;
	info->y1 = 0;
	info->x2 = 0;
	info->y2 = 0;
	info->amp = 1;
	info->w = 32;
	info->set = 0;
	info->pas = info->w;
	info->wh = 1080;
	info->ww = 1920;
	info->ih = info->wh - 50;
	info->iw = 6 * info->ww / 8;
	info->sx = info->iw / 2;
	info->sy = 5 * info->ih / 100;
	info->ix = info->ww / 8;
	info->iy = 75;
	info->proj = 1;
	char_info(info);
}
