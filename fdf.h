/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trabut <trabut@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 16:54:05 by lbonnete          #+#    #+#             */
/*   Updated: 2019/02/27 14:49:38 by trabut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include "get_next_line.h"
# include "mlx.h"
# include "math.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef	struct	s_map_info
{
	int			**map;
	int			longueur;
	int			hauteur;
	char		*name;
}				t_map_info;

typedef	struct	s_info
{
	int			proj;
	void		*pt;
	void		*wn;
	int			fd;
	int			sx;
	int			sy;
	int			x1;
	int			y1;
	int			x2;
	int			y2;
	int			y_origine;
	int			pas;
	int			amp;
	int			w;
	int			set;
	int			wh;
	int			ww;
	char		*addr;
	void		*im;
	char		*cw;
	char		*csx;
	char		*csy;
	char		*cpas;
	char		*camp;
	char		*cproj;
	int			ih;
	int			iw;
	int			ix;
	int			iy;
	t_map_info	*map;
}				t_info;

typedef	struct	s_line
{
	int			dx;
	int			sx;
	int			dy;
	int			sy;
	int			err;
	int			e2;
}				t_line;

/*
** Dealers
*/

int				deal_key(int key, t_info *info);
void			deal_arrow(int key, t_info *info);
void			deal_amp_pas(int key, t_info *info);

/*
** Mappers
*/

int				get_map(t_map_info *map, int fd);
char			**get_char_map(int fd);
int				boucle_get_map(t_map_info *map, char ***c_map, int i, int cap);

/*
** Drawers
*/

void			draw_links(t_info *info);
int				draw_line(t_info *info);
int				draw_line_condition(t_info *info);
int				draw_line_condition_hud(t_info *info);
void			img_mod(int x, int y, t_info *info);
void			drawer(t_info *info);
void			put_hud(t_info *info);
void			put_top_info(t_info *info);
int				draw_line_hud(t_info *info);
void			put_cadre(t_info *info);
void			put_commands(t_info *info);
void			put_status(t_info *info, void *n);
void			draw_links_caval(t_info *info);
void			right_line(t_info *info, int mapx, int mapy);
void			bottom_line(t_info *info, int mapx, int mapy);
void			left_line(t_info *info, int mapx, int mapy);
void			upper_line(t_info *info, int mapx, int mapy);
void			right_line_caval(t_info *info, int mapx, int mapy);
void			bottom_line_caval(t_info *info, int mapx, int mapy);
void			left_line_caval(t_info *info, int mapx, int mapy);
void			upper_line_caval(t_info *info, int mapx, int mapy);

/*
** Tools
*/

char			**realloc_map(char **map, int len);
void			destroy_tab(char ***tab);
int				tab_len(char **tab);
int				rgb(int r, int g, int b);
char			*cutter(char *str);
void			reset_info(t_info *info);
void			end_fdf(t_info *info);
int				update_info(t_info *info);

#endif
