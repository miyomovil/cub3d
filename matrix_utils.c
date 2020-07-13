/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antomart <antomart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 20:41:13 by antomart          #+#    #+#             */
/*   Updated: 2020/06/29 21:43:20 by antomart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_matrix_values(t_val *ptr)
{
	ptr->i = 0;
	ptr->j = 0;
	ptr->m = 0;
	ptr->tab_flag = 0;
	ptr->d = 0;
	ptr->z = 0;
	ptr->line_count = 1;
}

void	inc_j_m(t_val *ptr)
{
	ptr->j++;
	ptr->m++;
}

void	tab_parse(char *line, t_val *ptr)
{
	if (line[ptr->j] == '\t' &&
			(int)ft_strlen(line) < ptr->mat_w)
	{
		ptr->map[ptr->i][ptr->m] = '9';
		ptr->map[ptr->i][ptr->m + 1] = '9';
		ptr->map[ptr->i][ptr->m + 2] = '9';
		ptr->map[ptr->i][ptr->m + 3] = '9';
		ptr->m = ptr->m + 4;
		ptr->j++;
		ptr->tab_flag++;
	}
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

void	space_parse(char *line, t_val *ptr)
{
	if (line[ptr->j] == ' ')
	{
		ptr->map[ptr->i][ptr->m] = '9';
		inc_j_m(ptr);
	}
	if (line[ptr->j] != ' ' && line[ptr->j] != '\0')
	{
		ptr->map[ptr->i][ptr->m] = line[ptr->j];
		inc_j_m(ptr);
	}
}

void	no_space_parse(t_val *ptr)
{
	while (ptr->d > 0)
	{
		ptr->map[ptr->i][ptr->j + ptr->z] = '9';
		ptr->z++;
		ptr->d--;
	}
}
