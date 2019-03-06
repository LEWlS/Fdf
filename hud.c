/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trabut <trabut@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 15:42:13 by lbonnete          #+#    #+#             */
/*   Updated: 2019/02/27 14:48:46 by trabut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_hud(t_info *info)
{
	void *n;

	n = info->wn;
	put_top_info(info);
	put_cadre(info);
	put_status(info, n);
	put_commands(info);
}

void	put_top_info(t_info *info)
{
	int		w;
	void	*p;
	int		e;
	void	*n;

	w = rgb(255, 255, 255);
	p = info->pt;
	e = info->ww;
	n = info->wn;
	mlx_string_put(p, n, (9 * e / 20), 25, w, "MAP :");
	mlx_string_put(p, n, (9 * e / 20 + 70), 25, w, info->map->name);
	mlx_string_put(p, n, (1 * e / 20), 25, w, "Position :");
	mlx_string_put(p, n, (1 * e / 20 + 125), 25, w, info->csx);
	mlx_string_put(p, n, ((1 * e) / 20 + 165), 25, w, "|");
	mlx_string_put(p, n, (1 * e / 20 + 185), 25, w, info->csy);
	mlx_string_put(p, n, (13 * e / 20), 25, w, "Arrow keys to move");
	mlx_string_put(p, n, (17 * e / 20), 25, w, "ESC to quit");
}

void	put_commands(t_info *info)
{
	int		a;
	int		w;
	void	*p;
	int		e;

	a = (90 * info->ww / 100);
	w = rgb(255, 255, 255);
	p = info->pt;
	e = info->wh;
	mlx_string_put(p, info->wn, a, (20 * e / 100), w, "< - | Zoom | + >");
	mlx_string_put(p, info->wn, a, (35 * e / 100), w, "< Q | Pas | W >");
	mlx_string_put(p, info->wn, a, (50 * e / 100), w, "< A | Amp | S >");
	mlx_string_put(p, info->wn, a, (65 * e / 100), w, "1 Isometric");
	mlx_string_put(p, info->wn, a, (75 * e / 100), w, "2 Cavaliere");
	mlx_string_put(p, info->wn, a, (85 * e / 100), w, "0 to reset");
}

void	put_status(t_info *info, void *n)
{
	int		i;
	int		w;
	void	*p;
	int		h;

	i = info->ww;
	w = rgb(255, 255, 255);
	p = info->pt;
	h = info->wh;
	mlx_string_put(p, n, (2 * i / 100), (20 * h / 100), w, "Zoom =");
	mlx_string_put(p, n, 6 * i / 100, (20 * h / 100), w, info->cw);
	mlx_string_put(p, n, (2 * i / 100), (35 * h / 100), w, "Pas =");
	mlx_string_put(p, n, (6 * i / 100), (35 * h / 100), w, info->cpas);
	mlx_string_put(p, n, (2 * i / 100), (50 * h / 100), w, "Amp =");
	mlx_string_put(p, n, (6 * i / 100), (50 * h / 100), w, info->camp);
	mlx_string_put(p, n, (2 * i / 100), (65 * h / 100), w, "View =");
	mlx_string_put(p, n, (6 * i / 100), (65 * h / 100), w, info->cproj);
}

void	put_cadre(t_info *info)
{
	info->x1 = info->ix;
	info->y1 = info->iy - 1;
	info->x2 = info->ix + info->iw;
	info->y2 = info->iy - 1;
	draw_line_hud(info);
	info->x1 = info->ix - 1;
	info->y1 = info->iy;
	info->x2 = info->ix - 1;
	info->y2 = info->iy + info->ih;
	draw_line_hud(info);
	info->x1 = info->ix + info->iw;
	info->y1 = info->iy;
	info->x2 = info->ix + info->iw;
	info->y2 = info->iy + info->ih;
	draw_line_hud(info);
}
