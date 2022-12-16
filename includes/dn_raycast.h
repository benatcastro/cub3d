/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dn_raycast.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 20:26:38 by becastro          #+#    #+#             */
/*   Updated: 2022/12/16 16:52:51 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DN_RAYCAST_H
# define DN_RAYCAST_H
# include <math.h>
# include "danae.h"
# define HEIGHT		1920
# define WIDTH		1080
# define PLANE_V	10
# define DIR_V		10

typedef struct s_ray
{
	double	side_dist[2];
	double	ray_dir[2];
	double	delta_dist[2];
}	t_ray;
typedef struct s_raycast
{

	char			**map;
	struct s_ray	t_ray;
	double			camera[2];
	double			plane[2];
	double			dir[2];
	double			ray[2];
}	t_raycast;

void	dn_raycast_init(t_frame *frame);

#endif
