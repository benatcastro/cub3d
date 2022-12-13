/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dn_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 02:51:14 by becastro          #+#    #+#             */
/*   Updated: 2022/12/13 06:39:42 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "danae.h"
#include "structs.h"


void	dn_init(u_int32_t height, u_int32_t width, char *title)
{
	t_frame	*frame;

	frame = ft_calloc(1, sizeof(t_frame));
	frame->mlx->mlx = mlx_init(width, height, title, true);
	if (!frame->mlx)
		dn_error();
	frame->mlx->mlx_img = mlx_new_image(frame->mlx->mlx, width, height);
	mlx_image_to_window(frame->mlx->mlx, frame->mlx->mlx_img, width, height);
	//mlx_loop_hook(frame.mlx->mlx, dn_render_frame, &frame);
	mlx_loop(frame->mlx->mlx);
}
