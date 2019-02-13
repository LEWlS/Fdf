/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbonnete <lbonnete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 15:46:36 by lbonnete          #+#    #+#             */
/*   Updated: 2019/02/13 13:41:49 by lbonnete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_tab_len(char **tab)
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

char	**ft_realloc_map(char **map, int len)
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

void	put_font(t_info *info)
{
	int x;
	int y;

	x = 0;
	while (x < info->window_width)
	{
		y = 0;
		while(y < info->window_height)
		{
			mlx_pixel_put(info->ptr, info->win, x, y, info->font);
			y++;
		}
		x++;
	}
}