/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_square.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbonnete <lbonnete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 18:15:00 by lbonnete          #+#    #+#             */
/*   Updated: 2019/01/08 18:15:27 by lbonnete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_square(t_info *try, int key, int size, int color)
{
	int x;
	int y;

	if (key == 126)
		try->y = try->y - size;
	if (key == 125)
		try->y = try->y + size;
	if (key == 123)
		try->x = try->x - size;
	if (key == 124)
		try->x = try->x + size;
	x = try->x;
	while (x < try->x + size)
	{
		y = try->y;
		while(y < try->y + size)
		{
			mlx_pixel_put(try->ptr, try->win, x, y, color);
			y++;
		}
		x++;
	}
}

void	put_new_square(t_info *try, int key, int size)
{
	put_square(try, 0, 20, 0);
	put_square(try, key, 20, try->color);
}
