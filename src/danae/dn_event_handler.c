/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dn_event_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 20:31:05 by becastro          #+#    #+#             */
/*   Updated: 2023/01/23 14:23:21 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "danae.h"
#include "hooks.h"
#include <stdlib.h> //just for exit

int	mouse_handler(int event, void *frame)
{
	(void)frame;
	if (event == 0)
		exit(0);
	return (event);
}

int	key_handler(int key, void *frame_ptr)
{
	t_frame	*frame;

	frame = frame_ptr;
	if (key == DARWIN_ESC)
		exit(0); // change for exit fnc
	if (key == W)
		frame->player->pos[X] += 0.5;
	if (key == S)
		frame->player->pos[X] -= 0.5;
	if (key == A)
		frame->player->pos[Y] -= 0.5;
	if (key == D)
		frame->player->pos[Y] += 0.5;
	return (key);
}

void	dn_event_handler(t_frame *frame)
{
	mlx_key_hook(frame->mlx->win, key_handler, frame);
	mlx_mouse_hook(frame->mlx->win, mouse_handler, frame);
}
