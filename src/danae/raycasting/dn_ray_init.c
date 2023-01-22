/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dn_ray_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 09:07:05 by becastro          #+#    #+#             */
/*   Updated: 2023/01/22 14:29:47 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "danae.h"
#include "dn_raycast.h"
#include "cub3d.h"
#include <stdlib.h>



#define mapWidth 24
#define mapHeight 24

int worldMap[mapWidth][mapHeight]=
{
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

static void	dn_draw_vertical(t_frame *frame, t_raycast *rc, int h, int x)
{
	int	line_height;
	int	draw_start;
	int	draw_end;
	int	draw_pos;


	line_height = (int)(h / rc->perp_wall_dst);
	draw_start = -line_height / 2 + h / 2;
	draw_end = line_height / 2 + h / 2;
	draw_pos = draw_start;

	if (draw_start < 0)
		draw_start = 0;
	if (draw_end >= h)
		draw_end = h - 1;
	while (draw_pos < draw_end)
	{
		dn_put_pixel(frame->mlx, x, draw_pos, FLAMINGO);
		draw_pos++;
	}

}

void	dn_raycast_loop (t_frame *frame, t_raycast *rc)
{
	double	posX = 22, posY = 12;
	int		w = WIDTH;
	int		h = HEIGHT;

	rc = ft_calloc(1, sizeof(t_raycast));
	rc->plane[X] = 0;
	rc->plane[Y] = 0.66;
	rc->dir[X] = -1;
	rc->dir[Y] = -1;
	for(int x = 0; x < w; x++)
	{
		rc->cam[X] = 2 * x / (double)w - 1;
		rc->ray_dir[X] = rc->dir[X] + rc->plane[X] * rc->cam[X];
		rc->ray_dir[Y] = rc->dir[Y] + rc->plane[Y] * rc->cam[X];
		rc->tile[X] = (int)posX;
		rc->tile[Y] = (int)posY;

		if (rc->ray_dir[X] == 0)
			rc->delta_dist[X] = 1e30;
		else
			rc->delta_dist[X] = fabs(1 / rc->ray_dir[X]);
		if (rc->ray_dir[Y] == 0)
			rc->delta_dist[Y] = 1e30;
		else
			rc->delta_dist[Y] = fabs(1 / rc->ray_dir[Y]);
		rc->hit = false;
		if (rc->ray_dir[X] < 0)
		{
			rc->step[X] = -1;
			rc->side_dist[X] = (posX - rc->tile[X]) * rc->delta_dist[X];
		}
		else
		{
			rc->step[X] = 1;
			rc->side_dist[X] = (rc->tile[X] + 1.0 - posX) * rc->delta_dist[X];
		}
		if (rc->ray_dir[Y] < 0)
		{
			rc->step[Y] = -1;
			rc->side_dist[Y] = (posY - rc->tile[Y]) * rc->delta_dist[Y];
		}
		else
		{
			rc->step[Y] = 1;
			rc->side_dist[Y] = (rc->tile[Y] + 1.0 - posY) * rc->delta_dist[Y];
		}
		while (rc->hit == false)
		{
			if (rc->side_dist[X] < rc->side_dist[Y])
			{
				rc->side_dist[X] += rc->delta_dist[X];
			rc->tile[X] += rc->step[X];
			rc->side = 0;
			}
			else
			{
				rc->side_dist[Y] += rc->delta_dist[Y];
				rc->tile[Y] += rc->step[Y];
				rc->side = 1;
			}
			if (worldMap[rc->tile[X]][rc->tile[Y]] > 0)
				rc->hit = true;
		}
		if (rc->side == 0)
			rc->perp_wall_dst = (rc->side_dist[X] - rc->delta_dist[X]);
		else
			rc->perp_wall_dst = (rc->side_dist[Y] - rc->delta_dist[Y]);
		dn_draw_vertical(frame, rc, h, x);
	}
}
