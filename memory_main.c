/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 20:40:19 by marvin            #+#    #+#             */
/*   Updated: 2019/01/10 20:40:19 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int ac, char **av)
{
	int fd;
	char	**map;

	
	
	fd = open(av[1], O_RDONLY);
	if (ac == 2)
		if (!(map = ft_get_map(fd)))
			return (0);
	ft_putendl(map[0]);