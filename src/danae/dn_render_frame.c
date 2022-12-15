/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dn_render_frame.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 02:45:17 by becastro          #+#    #+#             */
/*   Updated: 2022/12/15 16:09:57 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "danae.h"

int	dn_render_frame(void *frame_info)
{
	static uint32_t	tick;
	t_frame			*frame;

	frame = (t_frame *)frame_info;
	mlx_put_image_to_window(frame->mlx->ptr,
		frame->mlx->win, frame->mlx->img, 0, 0);
	return (tick);
}
