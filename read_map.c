/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antomart <antomart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 09:37:47 by antomart          #+#    #+#             */
/*   Updated: 2020/07/13 12:28:50 by antomart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_values(t_val *ptr)
{
	ptr->mat_w = 0;
}

void	read_map(t_val *ptr)
{
	char	*line;

	ptr->line_count = 1;
	init_values(ptr);
	ptr->map_read = open("maps/map.cub", O_RDONLY);
	while (get_next_line(ptr->map_read, &line))
	{
		if (ptr->line_count == 1 && line[0] == 'R' && line[1] == ' ')
		{
			get_res(line, ptr);
			ft_printf("\n%d", ptr->h);
			ft_printf("\n%d", ptr->w);
		}
		get_res_2(line, ptr);
		ptr->line_count++;
		free(line);
	}
	enter_the_matrix(ptr);
}
