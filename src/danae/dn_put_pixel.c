/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dn_put_pixel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 13:12:11 by becastro          #+#    #+#             */
/*   Updated: 2022/12/14 20:01:05 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "danae.h"

void	dn_put_pixel(t_mlx *data, uint16_t x, uint16_t y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->values.line_length + x
			* (data->values.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
