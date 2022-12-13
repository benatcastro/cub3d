/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 18:08:38 by becastro          #+#    #+#             */
/*   Updated: 2022/12/13 06:50:42 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "danae.h"
#include "cub3d.h"

int	main(int argc, char *argv[])
{
	dn_init(HEIGHT, WIDTH, "cub3d");
	init_cub3d(argc, argv);
}
