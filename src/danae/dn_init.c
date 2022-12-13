/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dn_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 02:51:14 by becastro          #+#    #+#             */
/*   Updated: 2022/12/13 03:22:21 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "danae.h"
#include "structs.h"

void	dn_init(u_int32_t height, u_int32_t width, char *title)
{
	t_mlx	mlx;

	mlx.mlx_ptr = mlx_init();
	mlx.win_ptr	= mlx_new_window(mlx.mlx_ptr, height, width, title);
}

void	dn_init_loop(void)
{
	return ;
}
