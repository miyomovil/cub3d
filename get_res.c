/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_res.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antomart <antomart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 14:56:06 by antomart          #+#    #+#             */
/*   Updated: 2020/06/30 08:01:20 by antomart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_res(char *line, t_val *ptr)
{
	int i;

	i = 0;
	if (line[0] == 'R')
		line[0] = ' ';
	ptr->h = ft_atoi(line);
	while (line[i])
	{
		if (ft_isdigit(line[i]) && ft_isdigit(line[i + 1]))
		{
			line[i] = ' ';
		}
		if (ft_isdigit(line[i]) && ft_isspace(line[i + 1]))
		{
			line[i] = ' ';
			break ;
		}
		i++;
	}
	ptr->w = ft_atoi(line);
}

void	get_path_n(char *line, t_val *ptr)
{
	ptr->n_path = ft_substr_1(line, 3, ft_strlen(line));
	ft_printf("\n%s", ptr->n_path);
}

void	get_path_s(char *line, t_val *ptr)
{
	ptr->s_path = ft_substr_1(line, 3, ft_strlen(line));
	ft_printf("\n%s", ptr->s_path);
}

void	get_path_w(char *line, t_val *ptr)
{
	ptr->w_path = ft_substr_1(line, 3, ft_strlen(line));
	ft_printf("\n%s", ptr->w_path);
}

void	get_path_e(char *line, t_val *ptr)
{
	ptr->e_path = ft_substr_1(line, 3, ft_strlen(line));
	ft_printf("\n%s", ptr->e_path);
}
