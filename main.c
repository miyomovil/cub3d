/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antomart <antomart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 21:53:13 by antomart          #+#    #+#             */
/*   Updated: 2020/07/13 13:16:03 by antomart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	leave(int mod, t_val *ptr, char *msg)
{
	if (mod == 0)
		printf("mod0%d",ptr->line_count);
		//mlx_destroy_window(win_infos->mlx_ptr, win_infos->win_ptr);
	system("killall afplay");
	ft_putstr_fd(msg, 1);
	if (msg[0])
		write(1, "\n", 1);
	exit(0);
}

int	main(void)
{
	t_val ptr;
	t_image img;

	read_map(&ptr);
	init_window(&ptr, &img);
}
