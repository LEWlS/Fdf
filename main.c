/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbonnete <lbonnete@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 20:39:27 by marvin            #+#    #+#             */
/*   Updated: 2019/01/10 20:39:27 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int ac, char **av)
{
	int fd;
	t_info	info;
	t_mouse_info mouse;
	t_map_info map;

	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		ft_putstr("map : ");
		ft_putendl(av[1]);
		if (!(ft_get_map(&map, fd)))
		{
			ft_putendl("map error");
			return (0);
		}
	}
	ft_reset_info(&info);
	ft_reset_mouse_info(&mouse);
	
	
	info.ptr = mlx_init();
	info.win = mlx_new_window(info.ptr, 1600, 900, "New");
	info.color1 = RGB(255,255,255);
	mouse.color = info.color1;
	mouse.ptr = info.ptr;
	mouse.win = info.win;
	if ((info.map = &map))
	{
		ft_putendl("Starting to draw");
		draw_links(&info);
	}
	mlx_mouse_hook(info.win, deal_mouse, &mouse);
	mlx_key_hook(info.win, deal_key, &mouse);
	mlx_loop(info.ptr);
	close(fd);
	free(&map);
	free(&info);
	free(&mouse);
	return (0);
}
