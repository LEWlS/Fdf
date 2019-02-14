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

void	end_fdf(t_info *info)
{
	close(info->fd);
}

int		main(int ac, char **av)
{
	t_info	info;
	t_map_info map;

	if (ac != 2)
	{
		ft_putendl("Usage : ./../../fdf/fdf <filename> [ case_size z_size ]");
		return (0);
	}
	info.fd = open(av[1], O_RDONLY);
	ft_putstr("map : ");
	ft_putendl(av[1]);
	if (!(get_map(&map, info.fd)))
	{
		ft_putendl("map error");
		return (0);
	}
	if ((info.map = &map))
	{
		ft_putendl("Starting to draw");
		printing_map_size(&map);
		reset_info(&info);
		info.ptr = mlx_init();
		info.win = mlx_new_window(info.ptr, info.window_width, info.window_height, "New");
		info.color1 = RGB(255,255,255);
		drawer(&info);
	}
	mlx_mouse_hook(info.win, deal_mouse, &info);
	mlx_key_hook(info.win, deal_key, &info);
	mlx_loop(info.ptr);
	return (0);
}
