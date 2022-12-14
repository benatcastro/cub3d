/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dn_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 02:51:14 by becastro          #+#    #+#             */
/*   Updated: 2022/12/14 20:23:31 by becastro         ###   ########.fr       */
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
	t_mlx	mlx;

	mlx.ptr = mlx_init();
	mlx.win = mlx_new_window(mlx.ptr, height, width, title);
	mlx.addr = mlx_get_data_addr(mlx.img, &mlx.values.bits_per_pixel,
			&mlx.values.line_length, &mlx.values.endian);
	data->mlx_data = &mlx;
}

/**
 * @brief
 * creates a new mlx window and stores it in data->mlx pointer
 * @param height
 * @param width
 * @param data
 */
void	dn_init_image(u_int32_t height, uint32_t width, t_data *data)
{
	data->mlx_data->img = mlx_new_image(data->mlx_data->ptr, width, height);
}
