/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbonnete <lbonnete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 15:46:36 by lbonnete          #+#    #+#             */
/*   Updated: 2019/03/01 14:06:14 by lbonnete         ###   ########.fr       */
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
	int		i;
	char	**ret;

	if (!(ret = (char **)malloc(sizeof(char *) * len + 1)))
		return (0);
	ret[len] = NULL;
	if (map)
	{
		i = 0;
		while (i < len)
		{
			if (!(ret[i] = ft_strdup(map[i])))
				return (0);
			i++;
		}
		free(ret[i - 1]);
		destroy_tab(&map);
	}
	return (ret);
}

int		rgb(int r, int g, int b)
{
	return (256 * 256 * (r) + 256 * (g) + (b));
}

int		update_info(t_info *info)
{
	free(info->csx);
	info->csx = ft_itoa(info->sx);
	free(info->csy);
	info->csy = ft_itoa(info->sy);
	free(info->cw);
	info->cw = ft_itoa(info->w);
	free(info->cpas);
	info->cpas = ft_itoa(info->pas);
	free(info->cproj);
	info->cproj = ft_itoa(info->proj);
	free(info->camp);
	info->camp = ft_itoa(info->amp);
	return (1);
}
