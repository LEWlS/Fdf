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
	char	**map;

	
	
	fd = open(av[1], O_RDONLY);
	if (ac == 2)
		if (!(map = ft_get_map(fd)))
			return (0);
	ft_putendl(map[0]);
	info.ptr = mlx_init();
	info.win = mlx_new_window(info.ptr, 1600, 900, "New");
	info.color1 = 000255255255;
	info.set = 0;
	mouse.ptr = info.ptr;
	mouse.win = info.win;
	mlx_mouse_hook(info.win, deal_mouse, &mouse);
	mlx_key_hook(info.win, deal_key, &info);
	mlx_loop(info.ptr);
	return (0);
}
