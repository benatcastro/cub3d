/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dn_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 14:22:38 by becastro          #+#    #+#             */
/*   Updated: 2022/12/15 15:37:39 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "danae.h"

void	dn_screen_offset(t_mlx *mlx, uint32_t width, uint32_t height)
{
	mlx->values->window_offset[X] = width / 2;
	mlx->values->window_offset[Y] = height / 2;
}
