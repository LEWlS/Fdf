/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbonnete <lbonnete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 14:41:13 by lbonnete          #+#    #+#             */
/*   Updated: 2019/02/14 15:19:35 by lbonnete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	printing_map_size(t_map_info *map)
{
    ft_putstr("longueur = ");
    ft_putnbr(map->longueur);
    ft_putendl("");
    ft_putstr("hauteur = ");
    ft_putnbr(map->hauteur);
    ft_putendl("");

}

void    mouse_drawer(t_info *info)
{
    int bpp = 32;
    int size_l = info->image_width * 4;
    int i;
    int endian = 0;
    info->image = mlx_new_image(info->ptr, info->image_width , info->image_height );
    info->addr = mlx_get_data_addr(info->image, &bpp, &size_l, &endian);
	draw_line(info);
    draw_links(info);
    mlx_put_image_to_window(info->ptr, info->win, info->image, 0, 0);
    mlx_destroy_image(info->ptr, info->image);
}

void    drawer(t_info *info)
{
    int bpp = 32;
    int size_l = info->image_width * 4;
    int i;
    int endian = 0;
    info->image = mlx_new_image(info->ptr, info->image_width , info->image_height );
    info->addr = mlx_get_data_addr(info->image, &bpp, &size_l, &endian);
	draw_links(info);
    mlx_put_image_to_window(info->ptr, info->win, info->image, 0, 0);
    mlx_destroy_image(info->ptr, info->image);
}

void            draw_links(t_info *info)
{
    t_map_info map = *(info->map);
    int mapx;
    int mapy;

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
                info->y_origine = (mapx + mapy) * (info->width/2) + info->start_y;
                draw_line(info);
            }
            if (mapy + 1 < map.hauteur)
            {
                info->x1 = (mapx - mapy) * info->width  + info->start_x; 
                info->y1 = (mapx + mapy) * (info->width/2) + info->start_y - ((map.map)[mapy][mapx] * info->amp);
                info->x2 = (mapx - (mapy + 1)) * info->width + info->start_x;
                info->y2 = (mapx + (mapy + 1)) * (info->width/2) + info->start_y - ((map.map)[mapy + 1][mapx] * info->amp);
                info->y_origine = (mapx + mapy) * (info->width/2) + info->start_y;
                draw_line(info);
            }
			if (mapx - 1 >= 0)
            {
                info->x1 = (mapx - mapy) * info->width  + info->start_x; 
                info->y1 = (mapx + mapy) * (info->width/2) + info->start_y - ((map.map)[mapy][mapx] * info->amp);
                info->x2 = ((mapx - 1) - mapy) * info->width + info->start_x;
                info->y2 = ((mapx - 1) + mapy) * (info->width/2) + info->start_y - ((map.map)[mapy][mapx - 1] * info->amp);
                info->y_origine = (mapx + mapy) * (info->width/2) + info->start_y;
                draw_line(info);
            }
			if (mapy - 1 >= 0)
            {
                info->x1 = (mapx - mapy) * info->width  + info->start_x; 
                info->y1 = (mapx + mapy) * (info->width/2) + info->start_y - ((map.map)[mapy][mapx] * info->amp);
                info->x2 = (mapx - (mapy - 1)) * info->width + info->start_x;
                info->y2 = (mapx + (mapy - 1)) * (info->width/2) + info->start_y - ((map.map)[mapy - 1][mapx] * info->amp);
                info->y_origine = (mapx + mapy) * (info->width/2) + info->start_y;
                draw_line(info);
            }   
            mapx++;
        }
        mapy++;
    }
}