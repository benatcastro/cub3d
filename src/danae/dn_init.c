/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dn_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 02:51:14 by becastro          #+#    #+#             */
/*   Updated: 2022/12/14 01:43:03 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "danae.h"
#include "structs.h"

/**
 * @brief
 * returns the mlx struct and a window of passed parameters
 * @param height
 * @param width
 * @param title
 */
t_mlx	*dn_init(uint32_t height, uint32_t width, char *title)
{
	t_mlx	*mlx;

	mlx = ft_calloc(1, sizeof(t_mlx));
	mlx->ptr = mlx_init();
	mlx->img = mlx_new_image(mlx->ptr, width, height);
	mlx->win = mlx_new_window(mlx->ptr, width, height, title);
	mlx->addr = mlx_get_data_addr(mlx->ptr, &mlx->bpp, &mlx->ll, &mlx->endian);
	dn_put_pixel(5, 5, 0x00FF0000, mlx);
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img, 0, 0);
	return (mlx);
}
