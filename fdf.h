/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbonnete <lbonnete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 16:54:05 by lbonnete          #+#    #+#             */
/*   Updated: 2019/02/16 17:30:44 by lbonnete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include "get_next_line/get_next_line.h"
# include "mlx.h"
# include "math.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct  s_map_info
{
    int			**map;
    int			longueur;
    int			hauteur;
    char        *name;
}               t_map_info;

typedef struct  s_info
{
    void		*ptr;
    void		*win;
    int         fd;
	int			start_x;
	int			start_y;
    int			x1;
    int			y1;
	int			x2;
    int			y2;
    int         y_origine;
    int         pas;
	int			amp;
	int 		width;
    int			color1;
    int			color2;
	int		    set;
    int         window_height;
    int         window_width;
    char        *addr;
    void        *image;
    int         image_height;
	int 		image_width;
    int         image_x;
    int         image_y;
    int         hud_cap;
    t_map_info  *map;
}               t_info;

typedef struct s_line
{
	int			dx;
	int			sx;
	int			dy;
	int			sy;
	int			err;
	int			e2;
}				t_line;

/*Dealers*/
int				deal_key(int key, t_info *mouse);
int				deal_mouse(int button, int x, int y, t_info *info);
/*Mappers*/
int				get_map(t_map_info *map, int fd);
char            **get_char_map(int fd);
void    		draw_links(t_info *info);
/*Drawers*/
void    		draw_links(t_info *info);
void    		draw_bottom_links(t_info *info);
void    		draw_upper_links(t_info *info);
int             draw_line(t_info *info);
void            img_mod(int x, int y, t_info *info);
void    		drawer(t_info *info);
void            mouse_drawer(t_info *info);
void            put_hud(t_info *info);
void            put_top_info(t_info *info);
int             draw_line_hud(t_info *info);
void            put_cadre(t_info *info);
void	        put_commands(t_info *info);
void	        put_status(t_info *info);
/*Tools*/
char			**realloc_map(char **map, int len);
void        	destroy_tab(char ***tab);
int				tab_len(char **tab);
int		        RGB(int r, int g, int b);
char	        *cutter(char	*str);
/*Info_editers*/
void			reset_info(t_info *info);
/*printers*/
void            printing_map_size(t_map_info *map);
/*Destroyers*/
void	        end_fdf(t_info *info);
#endif
