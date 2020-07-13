/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enter_the_matrix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antomart <antomart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 10:51:17 by antomart          #+#    #+#             */
/*   Updated: 2020/07/13 11:14:14 by antomart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			check_mat_width(char *line, t_val *ptr)
{
	if (ptr->mat_w < (int)ft_strlen(line))
	{
		ptr->mat_w = ft_strlen(line);
	}
}

void			exit_the_matrix(t_val *ptr)
{
	printf("\n");
	ptr->k = 0;
	ptr->g = 0;
	while (ptr->k < ptr->mat_h)
	{
		while (ptr->g < ptr->mat_w)
		{
			if (ptr->map[ptr->k][ptr->g] != '1' &&
					ptr->map[ptr->k][ptr->g] != '0' &&
						ptr->map[ptr->k][ptr->g] != 'N' &&
							ptr->map[ptr->k][ptr->g] != '2')
			{
				ptr->map[ptr->k][ptr->g] = '9';
				printf("%c ", ptr->map[ptr->k][ptr->g]);
			}
			else
				printf("%c ", ptr->map[ptr->k][ptr->g]);
			ptr->g++;
		}
		ptr->k++;
		ptr->g = 0;
		printf("\n");
	}
}

static char		**malloc_map(t_val *ptr)
{
	int		i;
	char	**map;

	if (!(map = (char **)malloc(sizeof(char *) * ptr->mat_h)))
		leave(1, ptr, "Error\nDuring map malloc");
	ft_bzero(map, sizeof(char *) * ptr->mat_h);
	i = 0;
	while (i < ptr->mat_h)
	{
		if (!(map[i] = (char *)malloc(sizeof(char) * ptr->mat_w)))
			leave(1, ptr, "Error\nDuring map malloc");
		ft_bzero(map[i], sizeof(char) * ptr->mat_w);
		i++;
	}
	return (map);
}

void			into_the_matrix(char *line, t_val *ptr)
{
	while (ptr->m < ptr->mat_w)
	{
		tab_parse(line, ptr);
		tab_parse_2(line, ptr);
		if (line[ptr->j] != '\t' &&
			(int)ft_strlen(line) < ptr->mat_w)
		{
			space_parse(line, ptr);
			if (line[ptr->j] == '\0' && (int)ft_strlen(line)
				< ptr->mat_w && ptr->tab_flag == 0)
			{
				ptr->d = ptr->mat_w - (int)ft_strlen(line);
				no_space_parse(ptr);
				break ;
			}
		}
	}
}

void			enter_the_matrix(t_val *ptr)
{
	char *line;

	ptr->mat_h = (ptr->line_count - 11);
	ptr->map = malloc_map(ptr);
	init_matrix_values(ptr);
	ptr->map_read = open("maps/map.cub", O_RDONLY);
	printf("\n");
	while (get_next_line(ptr->map_read, &line))
	{
		if (ptr->line_count >= 11)
		{
			if (ptr->i < ptr->mat_h)
			{
				into_the_matrix(line, ptr);
				ptr->i++;
				ptr->j = 0;
				ptr->m = 0;
				ptr->tab_flag = 0;
			}
		}
		ptr->line_count++;
		free(line);
	}
	exit_the_matrix(ptr);
}
