/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dn_raycast.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 20:26:38 by becastro          #+#    #+#             */
/*   Updated: 2023/01/22 14:43:27 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DN_RAYCAST_H
# define DN_RAYCAST_H
# include <math.h>
# include "danae.h"
# define PLANE_V	10
# define DIR_V		10

typedef struct s_draw
{
	int	line_lenght;
	int	draw_start;
	int	draw_end;
}	t_draw;
typedef struct s_raycast
{

	char			**map;
	int				tile[2];
	double			cam[2];
	double			plane[2];
	double			ray_dir[2];
	double			side_dist[2];
	double			delta_dist[2];
	double			dir[2];
	double			perp_wall_dst;
	int				step[2];
	bool			hit;
	int				side;
	struct s_draw	*draw_data;
}	t_raycast;

void	dn_raycast_loop(t_frame *frame, t_raycast *raycast);
#endif
