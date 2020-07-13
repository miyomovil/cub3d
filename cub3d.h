/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antomart <antomart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 07:54:43 by antomart          #+#    #+#             */
/*   Updated: 2020/07/13 13:17:42 by antomart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include <math.h>
# include <fcntl.h>
# include "libft.h"
# include "mlx.h"

typedef	struct	s_cub3d
{
	int		line_count;
	int		map_read;
	int		h;
	int		w;
	char	*n_path;
	char	*s_path;
	char	*w_path;
	char	*e_path;
	char	*spr_path;
	char	**map;
	char	*f_value1str;
	char	*f_value2str;
	char	*f_value3str;
	char	*c_value1str;
	char	*c_value2str;
	char	*c_value3str;
	int		f_value_1;
	int		f_value_2;
	int		f_value_3;
	int		c_value_1;
	int		c_value_2;
	int		c_value_3;
	int		i;
	int		d;
	int		c;
	int		k;
	int		g;
	int		j;
	int		m;
	int		z;
	int		tab_flag;
	int		mat_h;
	int		mat_w;

}				t_val;

typedef struct  s_image
{
    void        *img;
    char        *addr;
    int         bits_per_pixel;
    int         line_length;
    int         endian;
}               t_image;


void			get_res(char *line, t_val *ptr);
void			get_res_2(char *line, t_val *ptr);
void			get_path_n(char *line, t_val *ptr);
void			get_path_s(char *line, t_val *ptr);
void			get_path_w(char *line, t_val *ptr);
void			get_path_e(char *line, t_val *ptr);
void			get_path_spr(char *line, t_val *ptr);
void			get_f_values(char *line, t_val *ptr);
void			get_c_values(char *line, t_val *ptr);
void			leave(int mod, t_val *ptr, char *msg);
void			read_map(t_val *ptr);
void			init_matrix_values(t_val *ptr);
void			check_mat_width(char *line, t_val *ptr);
void			enter_the_matrix(t_val *ptr);
void			into_the_matrix(char *line, t_val *ptr);
void			exit_the_matrix(t_val *ptr);
void			inc_j_m(t_val *ptr);
void			tab_parse(char *line, t_val *ptr);
void			tab_parse_2(char *line, t_val *ptr);
void			space_parse(char *line, t_val *ptr);
void			no_space_parse(t_val *ptr);
void			init_window(t_val *ptr, t_image *img);
#endif
