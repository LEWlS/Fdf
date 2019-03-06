/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trabut <trabut@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 20:39:27 by marvin            #+#    #+#             */
/*   Updated: 2019/03/06 16:02:30 by trabut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	end_fdf(t_info *info)
{
	int i;

	i = 0;
	while (i < info->map->hauteur)
	{
		free((info->map->map)[i]);
		(info->map->map)[i] = 0;
		i++;
	}
	free(info->map->map);
	info->map->map = 0;
	free(info->csx);
	free(info->csy);
	free(info->cw);
	free(info->cpas);
	free(info->cproj);
	close(info->fd);
}

char	*cutter(char *str)
{
	int i;

	i = 0;
	if (str)
	{
		while (str[i])
			i++;
		while (i != 0)
		{
			if (str[i] == '/')
			{
				if (ft_strlen(&(str[i])) > 27)
					str[i + 27] = 0;
				return (&(str[i + 1]));
			}
			i--;
		}
		if (ft_strlen(&(str[i + 1])) > 27)
			str[i + 27] = 0;
		return (&(str[i]));
	}
	return (0);
}

void	main_support(t_info *info)
{
	reset_info(info);
	info->pt = mlx_init();
	info->wn = mlx_new_window(info->pt, info->ww, info->wh, "fdf");
	drawer(info);
}

int		main(int ac, char **av)
{
	t_info		info;
	t_map_info	map;

	if (ac != 2)
	{
		ft_putendl("Usage : ./fdf <filename>");
		return (0);
	}
	info.map = &map;
	if (!(get_map(info.map, info.fd = open(av[1], O_RDONLY))))
	{
		ft_putendl("map error");
		return (0);
	}
	info.map->name = cutter(av[1]);
	main_support(&info);
	mlx_key_hook(info.wn, deal_key, &info);
	mlx_loop(info.pt);
	return (0);
}
