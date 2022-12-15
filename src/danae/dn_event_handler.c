/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dn_event_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 20:31:05 by becastro          #+#    #+#             */
/*   Updated: 2022/12/15 11:35:58 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "danae.h"
#include "hooks.h"
#include <stdlib.h> //just for exit

int	mouse_handler(int event, void *data)
{
	(void)data;
	if (event == 0)
		exit(0);
	return (event);
}

int	key_handler(int key, void *data)
{
	(void)data;
	if (key == DARWIN_ESC)
		exit(0); // change for exit fnc
	return (key);
}

void	dn_event_handler(t_data *data)
{
	mlx_key_hook(data->mlx_data->win, key_handler, data);
	mlx_mouse_hook(data->mlx_data->win, mouse_handler, data);
}
