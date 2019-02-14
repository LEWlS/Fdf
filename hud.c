/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbonnete <lbonnete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 15:42:13 by lbonnete          #+#    #+#             */
/*   Updated: 2019/02/14 17:30:59 by lbonnete         ###   ########.fr       */
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
    int x;
    int y;

    x = 300;
    y = 0;
    info->y2 = 50;
    while (x < 320)
    {
        info->x1 = x;
        info->y1 = y;
        info->x2 = x;
        draw_line_hud(info);
        x++;
        info->y2++;
    }
    x = 1500;
    y = 0;
    info->y2 = 70;
    while (x < 1520)
    {
        info->x1 = x;
        info->y1 = y;
        info->x2 = x;
        draw_line_hud(info);
        x++;
        info->y2--;
    }
    x = 320;
    y = 50;
    info->y2 = y;
    while (y < 70)
    {
        info->x1 = x;
        info->y1 = y;
        info->x2 = 1500;
        info->y2 = y;
        draw_line_hud(info);
        y++;
    }
    mlx_string_put(info->ptr, info->win, 734, 26, RGB(255, 255, 255), "MAP :");
}