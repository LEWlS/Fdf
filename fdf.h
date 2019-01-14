/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbonnete <lbonnete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 16:54:05 by lbonnete          #+#    #+#             */
/*   Updated: 2019/01/14 17:45:33 by lbonnete         ###   ########.fr       */
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

typedef struct  s_mouse_info
{
    void	*ptr;
    void	*win;
    int		x1;
    int		y1;
	int		x2;
    int		y2;
    int		color;
	int		set;
    int     thickness;
}				t_mouse_info;

typedef struct  s_info
{
    void	*ptr;
    void	*win;
    int		x1;
    int		y1;
	int		x2;
    int		y2;
    int     unit;
    int     thickness;
    int     angle;
    int		color1;
    int		color2;
	int		set;
}               t_info;

typedef struct  s_map_info
{
    int **map;
    int longueur;
    int largeur;
}               t_map_info;

typedef struct s_line
{
	int dx;
	int sx;
	int dy;
	int sy;
	int err;
	int e2;
}				t_line;

/*Dealers*/
int				deal_key(int key, t_info *try);
int				deal_mouse(int button, int x, int y, t_mouse_info *info);
/*mappers*/
char    		**ft_get_map(int fd);
/*drawers*/
int				ft_draw_line_mouse(t_mouse_info *info);
/*void			put_new_square(t_info *try, int key, int size);
void			put_square(t_info *try, int key, int size, int color);
*/
/*tools*/
char			**ft_realloc_map(char **map, int len);
void        	destroy_map(char ***map);
/*info_editers*/
void			ft_resest_mouse_info(t_mouse_info *info);
void			ft_resest_info(t_info *info);


#endif
