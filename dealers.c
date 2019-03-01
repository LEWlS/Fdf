/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dealers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbonnete <lbonnete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 15:16:24 by lbonnete          #+#    #+#             */
/*   Updated: 2019/02/27 17:38:22 by lbonnete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	deal_arrow(int key, t_info *info)
{
	if (key == 123)
		info->sx += info->pas;
	if (key == 124)
		info->sx -= info->pas;
	if (key == 126)
		info->sy += info->pas;
	if (key == 125)
		info->sy -= info->pas;
	if (key == 18 || key == 83)
		info->proj = 1;
	if (key == 19 || key == 84)
		info->proj = 2;
}

void	deal_amp_pas(int key, t_info *info)
{
	if (key == 0)
		info->amp--;
	if (key == 1)
		info->amp++;
	if (key == 13)
		info->pas += 2;
	if (key == 12)
		if (info->pas > 2)
			info->pas -= 2;
}

int		deal_key(int key, t_info *info)
{
	mlx_clear_window(info->pt, info->wn);
	if ((key < 127 && key > 122) || key == 18
	|| key == 19 || key == 84 || key == 83)
		deal_arrow(key, info);
	if (key == 82 || key == 29)
		reset_info(info);
	if (key == 53)
	{
		mlx_destroy_window(info->pt, info->wn);
		end_fdf(info);
		exit(0);
	}
	if (key == 51)
		mlx_clear_window(info->pt, info->wn);
	if (key == 69 || key == 24)
		info->w += 2;
	if (key == 78 || key == 27)
		if (info->w > 2)
			info->w -= 2;
	if (key == 0 || key == 1 || key == 13 || key == 12)
		deal_amp_pas(key, info);
	update_info(info);
	drawer(info);
	put_hud(info);
	return (0);
}
