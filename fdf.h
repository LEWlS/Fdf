/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbonnete <lbonnete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 16:54:05 by lbonnete          #+#    #+#             */
/*   Updated: 2019/01/08 18:18:48 by lbonnete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include "get_next_line/get_next_line.h"
# include "mlx.h"

typedef struct  s_key_info
{
    void    *ptr;
    void    *win;
    int     x;
    int     y;
    int     z;
    int     color;
}               t_info;
typedef struct  s_mouse_info
{
    void    *ptr;
    void    *win;
    int     x;
    int     y;
    int     z;
    int     color;
}               t_mouse_info;

void	put_new_square(t_info *try, int key, int size);
void	put_square(t_info *try, int key, int size, int color);

#endif
