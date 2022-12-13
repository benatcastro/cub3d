/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 02:48:49 by aalvarez          #+#    #+#             */
/*   Updated: 2022/12/13 07:13:19 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdlib.h>

void	ft_freedata(t_data *data)
{
	free(data->north_texture);
	free(data->south_texture);
	free(data->west_texture);
	free(data->east_texture);
	ft_doublefree(data->map);
}

void	ft_init_structs(t_data *data, t_color *color)
{
	data->north_texture = NULL;
	data->south_texture = NULL;
	data->west_texture = NULL;
	data->east_texture = NULL;
	data->map = NULL;
	data->floor = -1;
	data->ceiling = -1;
	color->ceiling_integer = -1;
	color->floor_integer = -1;
}

void	ft_trim_data(t_data *data)
{
	char	*tmp;

	tmp = ft_strdup(data->north_texture);
	free(data->north_texture);
	data->north_texture = ft_strtrim(tmp, " \n");
	free(tmp);
	tmp = ft_strdup(data->south_texture);
	free(data->south_texture);
	data->south_texture = ft_strtrim(tmp, " \n");
	free(tmp);
	tmp = ft_strdup(data->west_texture);
	free(data->west_texture);
	data->west_texture = ft_strtrim(tmp, " \n");
	free(tmp);
	tmp = ft_strdup(data->east_texture);
	free(data->east_texture);
	data->east_texture = ft_strtrim(tmp, " \n");
	free(tmp);
}
