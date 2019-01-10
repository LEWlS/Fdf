/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbonnete <lbonnete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 15:35:05 by lbonnete          #+#    #+#             */
/*   Updated: 2019/01/10 16:05:10 by lbonnete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char    **ft_get_map(int fd)
{
	char	*line;
	char	**map;
	int		len;
	int i;
	
	len = 1;
	if (!(map = (char **)malloc(sizeof(char *) * len + 1)))
			return (0);
	map[len] = NULL;
	i = 0;
	while (get_next_line(fd, &line))
	{
		if (!(map[i] = ft_strdup(line)))
			return (0);
		if (!(map = ft_realloc_map(map, ++len)))
			return (0);
		ft_putendl(map[i]);
		i++;
	}
	return (map);
}