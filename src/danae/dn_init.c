/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dn_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 02:51:14 by becastro          #+#    #+#             */
/*   Updated: 2022/12/13 14:03:24 by becastro         ###   ########.fr       */
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
t_mlx	*dn_init(u_int32_t height, u_int32_t width, char *title)
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
