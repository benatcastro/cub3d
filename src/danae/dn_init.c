/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dn_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 02:51:14 by becastro          #+#    #+#             */
/*   Updated: 2022/12/14 21:10:05 by becastro         ###   ########.fr       */
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

void	dn_init(uint32_t height, uint32_t width, char *title, t_data *data)
{
	t_mlx	*mlx;

	mlx = ft_calloc(1, sizeof(t_mlx));
	mlx->values = ft_calloc(1, sizeof(t_mlx_values));
	mlx->ptr = mlx_init();
	mlx->win = mlx_new_window(mlx->ptr, width, height, title);
	mlx->img = mlx_new_image(mlx->ptr, width, height);
	mlx->addr = mlx_get_data_addr(mlx->img, &mlx->values->bits_per_pixel,
			&mlx->values->line_length, &mlx->values->endian);
	data->mlx_data = mlx;
}
