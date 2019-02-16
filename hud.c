/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbonnete <lbonnete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 15:42:13 by lbonnete          #+#    #+#             */
/*   Updated: 2019/02/16 15:46:12 by lbonnete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    put_hud(t_info *info)
{
    info->hud_cap = 1;
    put_info_screen(info);
    info->hud_cap = 0;
}

void    put_info_screen(t_info *info)
{
    t_map_info map;

    map = *(info->map);
    mlx_string_put(info->ptr, info->win, 734, 26, RGB(255, 255, 255), "MAP :");
    mlx_string_put(info->ptr, info->win, 800, 26, RGB(255, 255, 255), map.name);
}