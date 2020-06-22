/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antomart <antomart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 09:37:47 by antomart          #+#    #+#             */
/*   Updated: 2020/06/22 16:47:14 by antomart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(void)
{
	t_val	ptr;
	char	*line;

	ptr.line_count = 1;
	ptr.map_read = open("maps/map.cub", O_RDONLY);
	while (get_next_line(ptr.map_read, &line))
	{
		if (ptr.line_count == 1 && line[0] == 'R' && line[1] == ' ')
		{
			get_res(line, &ptr);
			ft_printf("\n%d", ptr.h);
			ft_printf("\n%d", ptr.w);
		}
		if (ptr.line_count == 2)
			get_path_n(line, &ptr);
		if (ptr.line_count == 3)
			get_path_s(line, &ptr);
		if (ptr.line_count == 4)
			get_path_w(line, &ptr);
		if (ptr.line_count == 4)
			get_path_e(line, &ptr);
		ptr.line_count++;
		free(line);
	}
	return (0);
}
