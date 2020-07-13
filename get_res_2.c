/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_res_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antomart <antomart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 08:10:21 by antomart          #+#    #+#             */
/*   Updated: 2020/06/30 08:02:02 by antomart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_path_spr(char *line, t_val *ptr)
{
	ptr->spr_path = ft_substr_1(line, 2, ft_strlen(line));
	ft_printf("\n%s", ptr->spr_path);
}

void	get_f_values(char *line, t_val *ptr)
{
	ptr->i = 0;
	while (line[ptr->i] != ',')
		ptr->i++;
	ptr->f_value1str = ft_substr_1(line, 2, ptr->i);
	ptr->f_value_1 = ft_atoi(ptr->f_value1str);
	ptr->i++;
	ptr->c = ptr->i;
	ptr->d = 0;
	while (line[ptr->i] != ',')
	{
		ptr->i++;
		ptr->d++;
	}
	ptr->f_value2str = ft_substr_1(line, ptr->c, ptr->d);
	ptr->f_value_2 = ft_atoi(ptr->f_value2str);
	ptr->i++;
	ptr->c = ptr->i;
	ptr->d = 0;
	while (line[ptr->i] != ',')
	{
		ptr->i++;
		ptr->d++;
	}
	ptr->f_value3str = ft_substr_1(line, ptr->c, ptr->d);
	ptr->f_value_3 = ft_atoi(ptr->f_value3str);
	printf("\n%d %d %d", ptr->f_value_1, ptr->f_value_2, ptr->f_value_3);
}

void	get_c_values(char *line, t_val *ptr)
{
	ptr->i = 0;
	while (line[ptr->i] != ',')
		ptr->i++;
	ptr->c_value1str = ft_substr_1(line, 2, ptr->i);
	ptr->c_value_1 = ft_atoi(ptr->c_value1str);
	ptr->i++;
	ptr->c = ptr->i;
	ptr->d = 0;
	while (line[ptr->i] != ',')
	{
		ptr->i++;
		ptr->d++;
	}
	ptr->c_value2str = ft_substr_1(line, ptr->c, ptr->d);
	ptr->c_value_2 = ft_atoi(ptr->c_value2str);
	ptr->i++;
	ptr->c = ptr->i;
	ptr->d = 0;
	while (line[ptr->i] != ',')
	{
		ptr->i++;
		ptr->d++;
	}
	ptr->c_value3str = ft_substr_1(line, ptr->c, ptr->d);
	ptr->c_value_3 = ft_atoi(ptr->c_value3str);
	printf("\n%d %d %d", ptr->c_value_1, ptr->c_value_2, ptr->c_value_3);
}

void	get_res_2(char *line, t_val *ptr)
{
	if (ptr->line_count == 2)
		get_path_n(line, ptr);
	if (ptr->line_count == 3)
		get_path_s(line, ptr);
	if (ptr->line_count == 4)
		get_path_w(line, ptr);
	if (ptr->line_count == 5)
		get_path_e(line, ptr);
	if (ptr->line_count == 7)
		get_path_spr(line, ptr);
	if (ptr->line_count == 8)
		get_f_values(line, ptr);
	if (ptr->line_count == 9)
		get_c_values(line, ptr);
	if (ptr->line_count >= 11)
		check_mat_width(line, ptr);
}
