/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dn_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 02:51:14 by becastro          #+#    #+#             */
/*   Updated: 2022/12/15 16:35:35 by becastro         ###   ########.fr       */
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
	dn_screen_offset(mlx, width, height);
	data->mlx_data = mlx;
}

void	dn_get_frame(t_data *data, t_frame *frame)
{
	frame = ft_calloc(1, sizeof(t_frame));
	frame->map = data->map;
	frame->mlx = data->mlx_data;
	frame->player->tile[X] = data->init_x;
	frame->player->tile[Y] = data->init_y;
}

void	dn_init_loop(t_data *data)
{
	t_frame	*frame;

	frame = ft_calloc(1, sizeof(t_frame));
	mlx_put_image_to_window(data->mlx_data->ptr,
		data->mlx_data->win, data->mlx_data->img, 0, 0);
	mlx_loop_hook(data->mlx_data->ptr, dn_render_frame, frame);
	mlx_loop(data->mlx_data->ptr);
}
