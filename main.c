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

	if (ac != 2)
	{
		ft_putendl("Need file");
		return (0);
	}
	fd = open(av[1], O_RDONLY);
	
	ft_putendl(map[0]);
	ft_resest_info(&info);
	ft_resest_mouse_info(&mouse);
	info.ptr = mlx_init();
	info.win = mlx_new_window(info.ptr, 1600, 900, "New");
	info.color1 = 000255255255;
	mouse.color = info.color1;
	mouse.ptr = info.ptr;
	mouse.win = info.win;
	mlx_mouse_hook(info.win, deal_mouse, &mouse);
	mlx_key_hook(info.win, deal_key, &info);
	mlx_loop(info.ptr);
	close(fd);
	return (0);
}
