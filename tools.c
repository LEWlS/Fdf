/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbonnete <lbonnete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 15:46:36 by lbonnete          #+#    #+#             */
/*   Updated: 2019/02/14 14:44:13 by lbonnete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		tab_len(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

void	destroy_tab(char ***tab)
{
	int i;

	i = 0;
	while ((*tab)[i])
	{
		free((*tab)[i]);
		(*tab)[i] = 0;
		i++;
	}
	free(*tab);
	*tab = 0;
}

char	**realloc_map(char **map, int len)
{
    int i;
    char **ret;

	if (!(ret = (char **)malloc(sizeof(char *) * len + 1)))
		return (0);
	ret[len] = NULL;
	i = 0;
	while (i < len)
	{
		if (!(ret[i] = ft_strdup(map[i])))
			return (0);
		i++;
	}
	destroy_tab(&map);
	return (ret);
}

int		RGB(int r, int g, int b)
{
	return (256 * 256 * (r) + 256 * (g) + (b));
}