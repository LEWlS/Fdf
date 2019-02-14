/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbonnete <lbonnete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 15:35:05 by lbonnete          #+#    #+#             */
/*   Updated: 2019/02/14 14:43:56 by lbonnete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char    **get_char_map(int fd)
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
		ft_putendl(line);
		if (!(map[i] = ft_strdup(line)))
			return (0);
		if (!(map = realloc_map(map, ++len)))
			return (0);
		i++;
	}
	return (map);
}

int		get_map(t_map_info *map, int fd)
{
	char	**c_map;
	char	**tmp;
	int 	i;
	int		j;
	int 	cap;

	i = 0;
	cap = 1;
	if (!(c_map = get_char_map(fd)))
		return (0);
	map->hauteur = tab_len(c_map) - 1;
	if (!(map->map = (int **)malloc(sizeof(int *) * map->hauteur)))
		return (0);
	while (i < map->hauteur)
	{
		tmp = ft_strsplit(c_map[i], ' ');
		if (cap)
		{
			map->longueur = tab_len(tmp);
			cap = 0;
		}
		if (map->longueur != tab_len(tmp) && i != map->hauteur - 1 )
			return (0);
		if (!((map->map)[i] = (int *)malloc(sizeof(int) * map->longueur)))
			return (0);
		j = 0;
		while (tmp[j])
		{
			map->map[i][j] = ft_atoi(tmp[j]);
			j++;
		}
		i++;
		destroy_tab(&tmp);
	}
	return (1);
}