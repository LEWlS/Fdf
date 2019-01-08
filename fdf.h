/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbonnete <lbonnete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 16:54:05 by lbonnete          #+#    #+#             */
/*   Updated: 2019/01/08 16:32:02 by lbonnete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include "get_next_line/get_next_line.h"
# include "mlx.h"

typedef struct  s_info
{
    void    *ptr;
    void    *win;
    int     x;
    int     y;
    int     z;
}               t_info;

#endif
