/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dn_ray_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 09:07:05 by becastro          #+#    #+#             */
/*   Updated: 2022/12/16 20:48:39 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "danae.h"
#include "dn_raycast.h"
#include "cub3d.h"

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

void	dn_raycast_drawer(t_raycast *raycast)
{
	t_draw	draw_data;

	//Calculate height of line to draw on screen
	draw_data.line_lenght = (int)(HEIGHT / raycast->perp_wall_dst);

	//calculate lowest and highest pixel to fill in current stripe

}

void	dn_ray_iterator(t_ray *ray, t_raycast *raycast)
{
	while (!ray->hit)
	{
		if (ray->side_dist[X] < ray->side_dist[Y])
		{
			ray->side_dist[X] += ray->delta_dist[Y];
			ray->tile[X] += ray->steps[X];
			ray->side = 0;
		}
		else
		{
			ray->side_dist[Y] += ray->delta_dist[X];
			ray->tile[Y] += ray->steps[Y];
			ray->side = 1;
		}
		if (raycast->map[ray->tile[X]][ray->tile[Y]] > 0)
			ray->hit = true;
	}
	if (!ray->side)
		raycast->perp_wall_dst = (ray->side_dist[X] - ray->delta_dist[X]);
	else
		raycast->perp_wall_dst = (ray->side_dist[Y] - ray->delta_dist[Y]);
}

void	dn_get_ray_steps(t_frame *frame, t_raycast *rc)
{
	if (rc->t_ray->ray_dir[X] < 0)
	{
		rc->t_ray->steps[X] = -1;
		rc->t_ray->side_dist[X] = (frame->player->pos[X]
				- rc->t_ray->tile[X] * rc->t_ray->delta_dist[X]);
	}
	else
	{
		rc->t_ray->steps[X] = 1;
		rc->t_ray->side_dist[X] = (rc->t_ray->tile[X]
				+ 1.0 - frame->player->pos[X]) * rc->t_ray->delta_dist[X];
	}
	if (rc->t_ray->ray_dir[Y] < 0)
	{
		rc->t_ray->steps[Y] = -1;
		rc->t_ray->side_dist[Y] = (frame->player->pos[Y]
				- rc->t_ray->tile[Y] * rc->t_ray->delta_dist[Y]);
	}
	else
	{
		rc->t_ray->steps[Y] = 1;
		rc->t_ray->side_dist[Y] = (rc->t_ray->tile[Y]
				+ 1.0 - frame->player->pos[X]) * rc->t_ray->delta_dist[Y];
	}
}

void	dn_raycast_loop(t_frame *frame, t_raycast *raycast)
{
	int		x;
	t_ray	*ray;

	ray = raycast->t_ray;
	x = -1;
	while (++x < WIDTH)
	{
		ray->tile[X] = frame->player->pos[X];
		ray->tile[Y] = frame->player->pos[Y];
		raycast->cam[X] = 2 * x / (double)WIDTH - 1;
		ray->ray_dir[X] = raycast->dir[X] + raycast->plane[X] * raycast->cam[X];
		ray->ray_dir[Y] = raycast->dir[Y] + raycast->plane[Y] * raycast->cam[X];
		ray->delta_dist[X] = fabs(1 / ray->ray_dir[X]);
		ray->delta_dist[Y] = fabs(1 / ray->ray_dir[Y]);
		dn_get_ray_steps(frame, raycast);

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

