/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dn_put_pixel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 13:12:11 by becastro          #+#    #+#             */
/*   Updated: 2022/12/14 01:43:36 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "danae.h"

void	*dn_get_offset(uint16_t y, uint16_t x, t_mlx *mlx)
{
	return (mlx->addr + (y * mlx->ll + x * (mlx->bpp / 8)));
}

void	dn_put_pixel(uint16_t y, uint16_t x, int color, t_mlx *mlx)
{
	char	*dst;

	dst = dn_get_offset(y, x, mlx);
	*(uint32_t *)dst = color;
}
