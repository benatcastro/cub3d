/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_initial_errors.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalvarez <aalvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 01:05:27 by aalvarez          #+#    #+#             */
/*   Updated: 2022/09/21 17:00:39 by adel-cor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_color_res(t_vault *vault)
{
	vault->rx = 1920;
	vault->ry = 1080;
}

void	ft_init(t_vault *vault)
{
	vault->rx = 0;
	vault->ry = 0;
	vault->data.img = NULL;
	vault->texture[0].img = NULL;
	vault->texture[1].img = NULL;
	vault->texture[2].img = NULL;
	vault->texture[3].img = NULL;
	vault->data.mlx_win = NULL;
	ft_swap(&vault->init_x, &vault->init_y);
}
