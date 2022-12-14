/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dn_put_pixel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 13:12:11 by becastro          #+#    #+#             */
/*   Updated: 2022/12/16 15:07:33 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "danae.h"

void	dn_put_pixel(t_mlx *mlx, int x, int y, int color)
{
	char	*dst;

	dst = mlx->addr + ((y + mlx->values->window_offset[Y])
			* mlx->values->line_length
			+ (x + mlx->values->window_offset[X])
			* (mlx->values->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
