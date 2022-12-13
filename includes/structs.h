/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 18:02:45 by becastro          #+#    #+#             */
/*   Updated: 2022/12/13 06:36:50 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

#include "danae.h"
typedef struct s_mlx
{
	mlx_t		*mlx;
	mlx_image_t	*mlx_img;
}	t_mlx;
typedef struct s_frame
{
	struct s_mlx	*mlx;
}	t_frame;

#endif
