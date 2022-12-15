/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dn_raycast.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 20:26:38 by becastro          #+#    #+#             */
/*   Updated: 2022/12/15 16:22:00 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DN_RAYCAST_H
# define DN_RAYCAST_H
# include <math.h>
# include "danae.h"
# define POV 90

typedef struct s_raycast
{
	double	start_point[2];
	double	end_point[2];
}	t_raycast;

void	dn_raycast_init(t_frame *frame);

#endif
