/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_utils_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antomart <antomart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 21:35:33 by antomart          #+#    #+#             */
/*   Updated: 2020/06/29 21:43:48 by antomart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	tab_parse_2(char *line, t_val *ptr)
{
	if (line[ptr->j] != '\t' &&
		(int)ft_strlen(line) == ptr->mat_w)
	{
		if (line[ptr->j] == ' ')
		{
			ptr->map[ptr->i][ptr->m] = '9';
			inc_j_m(ptr);
		}
		if (line[ptr->j] != ' ')
		{
			ptr->map[ptr->i][ptr->m] = line[ptr->j];
			inc_j_m(ptr);
		}
	}
}
