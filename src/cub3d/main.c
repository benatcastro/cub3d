/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 18:08:38 by becastro          #+#    #+#             */
/*   Updated: 2022/12/14 20:12:46 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "danae.h"
#include "cub3d.h"

int	main(int argc, char *argv[])
{
	t_data	data;

	if (!init_cub3d(argc, argv, &data))
		return (0);
	ft_printdouble(data.map);
	dn_init(HEIGHT, WIDTH, NAME, &data);
}
