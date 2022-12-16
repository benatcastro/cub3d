/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dn_render_frame.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 02:45:17 by becastro          #+#    #+#             */
/*   Updated: 2022/12/16 21:31:23 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "danae.h"

int	dn_render_frame(void *frame_info)
{
	static uint32_t	tick;
	t_frame			*frame;

	frame = (t_frame *)frame_info;
	dn_raycast_loop(frame, frame->raycast);
	return (tick);
}
