/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbonnete <lbonnete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 15:40:23 by lbonnete          #+#    #+#             */
/*   Updated: 2019/01/08 18:21:52 by lbonnete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		deal_key(int key,	t_info *try)
{
	ft_putnbr(key);
	ft_putendl("");
	if (key == 53)
		mlx_destroy_window (try->ptr, try->win);
	else
		put_new_square(try, key, 20);
	return (0);
	
}
int		deal_mouse(int button, int x, int y, void *param)
{

}

int		main(void)
{
	t_info	try;

	try.x = 500;
	try.y = 500;
	try.color = 123;
	try.ptr = mlx_init();
	try.win = mlx_new_window(try.ptr, 1000, 1000, "New");
	mlx_mouse_hook(try.win, deal_mouse, &try);
	mlx_key_hook (try.win, deal_key, &try);
	mlx_loop(try.ptr);
	return (0);
}