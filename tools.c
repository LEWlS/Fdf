/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbonnete <lbonnete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 15:46:36 by lbonnete          #+#    #+#             */
/*   Updated: 2019/01/14 16:13:36 by lbonnete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static	void	destroy(char ***map)
{


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
	destroy(&map);
	return (ret);
}