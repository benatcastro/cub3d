/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dn_ray_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 09:07:05 by becastro          #+#    #+#             */
/*   Updated: 2022/12/16 16:52:58 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "danae.h"
#include "dn_raycast.h"

/*void	dn_init_fov(t_raycast *raycast, double pos[2], char init_view)
{
	double	dir_v[2];
	double	plane_v[2];

	dir_v[X] = pos[X];
	dir_v[Y] = pos[Y];
	if (init_view == 'N')
		dir_v[Y] += DIR_V;
	if (init_view == 'S')
		dir_v[Y] -= DIR_V;
	if (init_view == 'E')
		dir_v[X] -= DIR_V;
	if (init_view == 'W')
		dir_v[X] += DIR_V;
	plane_v[X] = dir_v[X];
	plane_v[Y] = -dir_v[Y];
	raycast->start_angle = atan((plane_v[X] - PLANE_V) / plane_v[X]);
	raycast->end_angle = atan((plane_v[X] - PLANE_V) / plane_v[X]);
}*/

void	dn_raycast_loop(t_frame *frame, t_raycast *raycast)
{
	int	x;

	x = -1;
	(void)frame;
	while (++x < HEIGHT)
	{
		raycast->camera[X] = 2 * x / HEIGHT - 1;
		raycast->t_ray.ray_dir[X] = raycast->dir[X] + raycast->plane[X] * raycast->camera[X];
		raycast->t_ray.ray_dir[Y] = raycast->dir[Y] + raycast->plane[Y] * raycast->camera[X];
	}
}

void	dn_raycast_init(t_frame *frame)
{
	t_raycast	raycast;

	raycast.map = frame->map;
	raycast.dir[X] = -1;
	raycast.dir[Y] = 0;
	raycast.plane[X] = 0;
	raycast.plane[Y] = 0.66; //FOV
}

