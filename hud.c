/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbonnete <lbonnete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 15:42:13 by lbonnete          #+#    #+#             */
/*   Updated: 2019/02/16 17:50:01 by lbonnete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    put_hud(t_info *info)
{
    info->hud_cap = 1;
    put_top_info(info);
    put_cadre(info);
	put_status(info);
	put_commands(info);
    info->hud_cap = 0;
}



void    put_top_info(t_info *info)
{
    t_map_info map;

    map = *(info->map);
    mlx_string_put(info->ptr, info->win, (9 * info->window_width / 20), 25, RGB(255, 255, 255), "MAP :");
    mlx_string_put(info->ptr, info->win, ((9 * info->window_width) / 20) + 70, 25, RGB(255, 255, 255), map.name);
    mlx_string_put(info->ptr, info->win, ((1 * info->window_width) / 20), 25, RGB(255, 255, 255), "Position :");
    mlx_string_put(info->ptr, info->win, ((1 * info->window_width) / 20) + 125, 25, RGB(255, 255, 255), ft_itoa(info->start_x));
    mlx_string_put(info->ptr, info->win, ((1 * info->window_width) / 20) + 165, 25, RGB(255, 255, 255), "|");
    mlx_string_put(info->ptr, info->win, ((1 * info->window_width) / 20) + 185, 25, RGB(255, 255, 255), ft_itoa(info->start_y));
    mlx_string_put(info->ptr, info->win, ((13 * info->window_width) / 20), 25, RGB(255, 255, 255), "Arrow keys to move");
    mlx_string_put(info->ptr, info->win, ((17 * info->window_width) / 20), 25, RGB(255, 255, 255), "ESC to quit");
}

void	put_commands(t_info *info)
{
	mlx_string_put(info->ptr, info->win, (90 * info->window_width / 100), (20 * info->window_height / 100), RGB(255, 255, 255), "< - | Zoom | + >");
	mlx_string_put(info->ptr, info->win, (90 * info->window_width / 100), (35 * info->window_height / 100), RGB(255, 255, 255), "< Q | Pas | W >");
	mlx_string_put(info->ptr, info->win, (90 * info->window_width / 100), (50 * info->window_height / 100), RGB(255, 255, 255), "< A | Amp | S >");
	mlx_string_put(info->ptr, info->win, (89 * info->window_width / 100), (65 * info->window_height / 100), RGB(255, 255, 255), "1 for Isometric View");
	mlx_string_put(info->ptr, info->win, (89 * info->window_width / 100), (75 * info->window_height / 100), RGB(255, 255, 255), "2 for Cavaliere View");
	mlx_string_put(info->ptr, info->win, (89 * info->window_width / 100), (85 * info->window_height / 100), RGB(255, 255, 255), "0 to reset");

}
void	put_status(t_info *info)
{
	mlx_string_put(info->ptr, info->win, (2 * info->window_width / 100), (20 * info->window_height / 100), RGB(255, 255, 255), "Zoom =");
    mlx_string_put(info->ptr, info->win, ((6 * info->window_width) / 100), (20 * info->window_height / 100), RGB(255, 255, 255), ft_itoa(info->width));
	mlx_string_put(info->ptr, info->win, (2 * info->window_width / 100), (35 * info->window_height / 100), RGB(255, 255, 255), "Pas =");
    mlx_string_put(info->ptr, info->win, ((6 * info->window_width) / 100), (35 * info->window_height / 100), RGB(255, 255, 255), ft_itoa(info->pas));
	mlx_string_put(info->ptr, info->win, (2 * info->window_width / 100), (50 * info->window_height / 100), RGB(255, 255, 255), "Amp =");
    mlx_string_put(info->ptr, info->win, ((6 * info->window_width) / 100), (50 * info->window_height / 100), RGB(255, 255, 255), ft_itoa(info->amp));
	mlx_string_put(info->ptr, info->win, (2 * info->window_width / 100), (65 * info->window_height / 100), RGB(255, 255, 255), "View =");
    mlx_string_put(info->ptr, info->win, ((6 * info->window_width) / 100), (65 * info->window_height / 100), RGB(255, 255, 255), ft_itoa(0));
}

void	put_cadre(t_info *info)
{
    info->x1 = info->image_x;
    info->y1 = info->image_y - 1;
    info->x2 = info->image_x + info->image_width;
    info->y2 = info->image_y - 1;
    draw_line_hud(info);

    info->x1 = info->image_x - 1;
    info->y1 = info->image_y;
    info->x2 = info->image_x - 1;
    info->y2 = info->image_y + info->image_height;
    draw_line_hud(info);

    info->x1 = info->image_x + info->image_width;
    info->y1 = info->image_y;
    info->x2 = info->image_x + info->image_width;
    info->y2 = info->image_y + info->image_height;
    draw_line_hud(info);
}