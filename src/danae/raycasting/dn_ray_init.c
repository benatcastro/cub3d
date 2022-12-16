/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dn_ray_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 09:07:05 by becastro          #+#    #+#             */
/*   Updated: 2022/12/16 16:09:02 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "danae.h"
#include "dn_raycast.h"

void	dn_init_fov(t_raycast *raycast, double pos[2], char init_view)
{
	double	dir_v[2];
	double	plane_v[2];

	dir_v[X] = pos[X];
	dir_v[Y] = pos[Y] + DIR_V;
	plane_v[X] = dir_v[X];
	plane_v[Y] = -dir_v[Y];
	raycast->start_angle = atan((plane_v[X] - PLANE_V) / plane_v[X]);
	raycast->end_angle = atan((plane_v[X] - PLANE_V) / plane_v[X]);
}

void	dn_raycast_init(t_frame *frame)
{
	t_raycast	raycast;

	dn_init_fov(&raycast, frame->player->pos, frame->player);
	printf("startPoint: %f endPoint: %f\n", raycast.start_angle, raycast.end_angle);
	dn_put_pixel(frame->mlx, frame->player->pos[X], frame->player->pos[Y], RED);
	dn_put_pixel(frame->mlx, frame->player->pos[X] + DIR_V, raycast.end_angle, YELLOW);
	dn_put_pixel(frame->mlx, frame->player->pos[X] - DIR_V, raycast.start_angle, YELLOW);
}
