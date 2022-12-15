/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dn_ray.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 09:07:05 by becastro          #+#    #+#             */
/*   Updated: 2022/12/15 16:22:11 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "danae.h"
#include "dn_raycast.h"

void	dn_init_pov(t_raycast *raycast, double pos[2])
{
	(void)raycast;
	(void)pos;
}

void	dn_raycast_init(t_frame *frame)
{
	t_raycast	raycast;

	dn_init_pov(&raycast, frame->player->pos);
}
