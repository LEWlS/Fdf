/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbonnete <lbonnete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 15:35:05 by lbonnete          #+#    #+#             */
/*   Updated: 2019/03/07 12:24:45 by lbonnete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_ret(char ***c_map, t_map_info *map, char **tmp, int j)
{
	int i;

	i = 0;
	destroy_tab(c_map);
	destroy_tab(&tmp);
	while (i < j - 1)
	{
		free((map->map)[i]);
		(map->map)[i] = 0;
		i++;
	}
	ft_putendl("map error");
	exit(0);
}

char	**get_char_map(int fd)
{
	char	*line;
	char	**map;
	int		len;
	int		i;

	len = 0;
	i = 0;
	while (get_next_line(fd, &line) == 1)
	{
		if (!(map = realloc_map(map, ++len)))
			return (0);
		if (!(map[i] = ft_strdup(line)))
			return (0);
		i++;
		ft_strdel(&line);
	}
	return (map);
}

int		boucle_get_map(t_map_info *map, char ***c_map, int i, int cap)
{
	int		j;
	char	**tmp;

	while (++i < map->hauteur)
	{
		if (!(tmp = ft_strsplit((*c_map)[i], ' ')))
			return (0);
		if (cap)
		{
			map->longueur = tab_len(tmp);
			cap = 0;
		}
		if (map->longueur != tab_len(tmp))
			free_ret(c_map, map, tmp, i);
		if (!((map->map)[i] = (int *)malloc(sizeof(int) * map->longueur)))
			return (0);
		j = -1;
		while (tmp[++j])
			map->map[i][j] = ft_atoi(tmp[j]);
		destroy_tab(&tmp);
	}
	destroy_tab(c_map);
	return (1);
}

int		get_map(t_map_info *map, int fd)
{
	char	**c_map;
	int		i;
	int		cap;

	i = -1;
	cap = 1;
	if (fd == -1)
		return (0);
	if (!(c_map = get_char_map(fd)))
		return (0);
	map->hauteur = tab_len(c_map);
	if (!(map->map = (int **)malloc(sizeof(int *) * map->hauteur)))
		return (0);
	if (!boucle_get_map(map, &c_map, i, cap))
		return (0);
	return (1);
}
