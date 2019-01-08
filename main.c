/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbonnete <lbonnete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 15:40:23 by lbonnete          #+#    #+#             */
/*   Updated: 2019/01/08 16:58:32 by lbonnete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_square_4(t_info *try , int key)
{
	int x;
	int y;

	x = try->x;
	while (x < try->x + 4)
	{
		y = try->y;
		while(y < try->y + 4)
		{
			mlx_pixel_put(try->ptr, try->win, x, y, 123);
			y++;
		}
		x++;
	}
	if (key == 126)
		try->x -= 4;
	if (key == 124)
		try->y += 4;
	if (key == 125)
		try->x += 4;
	if (key == 123)
		try->y -= 4;
}

void	Rput_square_4(t_info *try , int key)
{
	int x;
	int y;

	x = try->x;
	while (x < try->x + 4)
	{
		y = try->y;
		while(y < try->y + 4)
		{
			mlx_pixel_put(try->ptr, try->win, x, y, 456);
			y++;
		}
		x++;
	}
	if (key == 126)
		try->x -= 4;
	if (key == 124)
		try->y += 4;
	if (key == 125)
		try->x += 4;
	if (key == 123)
		try->y -= 4;
}

int		deal_key(int key,	t_info *try)
{
	ft_putnbr(key);
	if (key == 53)
		mlx_destroy_window (try->ptr, try->win);
	if (123 >= key && key <= 126)
		Rput_square_4(try, key);
	return (0);
	
}

int		main(void)
{
	t_info	try;

	try.x = 500;
	try.y = 500;
	try.ptr = mlx_init();
	try.win = mlx_new_window(try.ptr, 1000, 1000, "New");
	put_square_4(&try, 0);
	try.x -= 100;
	try.y -= 100;
	put_square_4(&try, 0);
	mlx_key_hook (try.win, deal_key, &try);
	mlx_loop(try.ptr);
	return (0);
}