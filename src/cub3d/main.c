/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 18:08:38 by becastro          #+#    #+#             */
/*   Updated: 2022/12/15 15:04:26 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "danae.h"
#include "cub3d.h"
#include <stdlib.h> //provisional just for exit

int	hook_handler(int hook, void *data)
{
	(void)data;
	exit(0);//change for exit fnc
	return (hook);
}

int	main(int argc, char *argv[])
{
	t_data	data;

	if (!init_cub3d(argc, argv, &data))
		return (0);
	ft_printdouble(data.map);
	dn_init(HEIGHT, WIDTH, NAME, &data);
	mlx_hook(data.mlx_data->win, 17, 0, hook_handler, &data);
	dn_event_handler(&data);
	mlx_loop(data.mlx_data->ptr);
}
