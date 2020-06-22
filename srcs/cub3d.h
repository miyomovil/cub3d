/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antomart <antomart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 07:54:43 by antomart          #+#    #+#             */
/*   Updated: 2020/06/22 16:42:49 by antomart         ###   ########.fr       */
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
	int	line_count;
	int	map_read;
	int h;
	int w;
	char *N_path;
	char *S_path;
	char *W_path;
	char *E_path;

}				t_val;

void	get_res(char *line, t_val *ptr);
void	get_path_n(char *line, t_val *ptr);
void	get_path_s(char *line, t_val *ptr);
void	get_path_w(char *line, t_val *ptr);
void	get_path_e(char *line, t_val *ptr);

#endif