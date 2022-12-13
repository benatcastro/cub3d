/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_resolution_init.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 01:05:27 by aalvarez          #+#    #+#             */
/*   Updated: 2022/12/13 07:13:19 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_color_res(t_data *data)
{
	(void)data;
	// data->rx = 1920;
	// data->ry = 1080;
}

void	ft_init(t_data *data)
{
	(void)data;
	// data->rx = 0;
	// data->ry = 0;
	// data->data.img = NULL;
	// data->texture[0].img = NULL;
	// data->texture[1].img = NULL;
	// data->texture[2].img = NULL;
	// data->texture[3].img = NULL;
	// data->data.mlx_win = NULL;
	// ft_swap(&data->init_x, &data->init_y);
}
