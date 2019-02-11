/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbonnete <lbonnete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 14:41:13 by lbonnete          #+#    #+#             */
/*   Updated: 2019/02/11 17:44:15 by lbonnete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    static  printing_for_draw_links(t_map_info *map)
{
    ft_putstr("longueur = ");
    ft_putnbr(map->longueur);
    ft_putendl("");
    ft_putstr("hauteur = ");
    ft_putnbr(map->hauteur);
    ft_putendl("");

}

void            draw_links(t_info *info)
{
    t_map_info map = *(info->map);
    int mapx;
    int mapy;

    printing_for_draw_links(&map);
    mapx = 0;
    mapy = 0;
    while(mapy < map.hauteur)
    {
        mapx = 0;
        while (mapx < map.longueur)
        {
            if (mapx + 1 < map.longueur)
            {
                info->x1 = (mapx - mapy) * info->width  + info->start_x; 
                info->y1 = (mapx + mapy) * (info->width/2) + info->start_y - ((map.map)[mapy][mapx] * info->amp);
                info->x2 = ((mapx + 1) - mapy) * info->width + info->start_x;
                info->y2 = ((mapx + 1) + mapy) * (info->width/2) + info->start_y - ((map.map)[mapy][mapx + 1] * info->amp);
                ft_draw_line(info);
            }
            if (mapy + 1 < map.hauteur)
            {
                info->x1 = (mapx - mapy) * info->width  + info->start_x; 
                info->y1 = (mapx + mapy) * (info->width/2) + info->start_y - ((map.map)[mapy][mapx] * info->amp);
                info->x2 = (mapx - (mapy + 1)) * info->width + info->start_x;
                info->y2 = (mapx + (mapy + 1)) * (info->width/2) + info->start_y - ((map.map)[mapy + 1][mapx] * info->amp);
                ft_draw_line(info);
            }        
            mapx++;
        }
        mapy++;
    }
}