/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_limits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 00:46:04 by aalvarez          #+#    #+#             */
/*   Updated: 2022/12/13 07:13:19 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_map_limits(t_data *data)
{
	int	i;

	i = -1;
	while (data->map[0][++i])
		if (!ft_chr_in_set(data->map[0][i], " 1\n"))
			return (1);
	i = -1;
	while (data->map[ft_doublestrlen((const char **)data->map) - 1][++i])
		if (!ft_chr_in_set(data->map
				[ft_doublestrlen((const char **)data->map) - 1][i], " 1\n"))
			return (1);
	i = -1;
	while (data->map[++i])
		if (!ft_chr_in_set(data->map[i][ft_strlen(data->map[i]) - 2], " 1\n"))
			if (ft_strlen(data->map[i]) > 1)
				return (1);
	return (0);
}

static int	ft_limits_0(t_data *data, int i, int j)
{
	if (data->map[i][j] == '0')
		if (!ft_chr_in_set(data->map[i][j + 1], "01NSWE")
			|| !ft_chr_in_set(data->map[i][j - 1], "01NSWE")
			|| !ft_chr_in_set(data->map[i + 1][j], "01NSWE")
			|| !ft_chr_in_set(data->map[i - 1][j], "01NSWE"))
			return (1);
	return (0);
}

static int	ft_limits_init_pos(t_data *data, int i, int j)
{
	if (ft_chr_in_set(data->map[i][j], "NSWE"))
		if (!ft_chr_in_set(data->map[i][j + 1], "01")
			|| !ft_chr_in_set(data->map[i][j - 1], "01")
			|| !ft_chr_in_set(data->map[i + 1][j], "01")
			|| !ft_chr_in_set(data->map[i - 1][j], "01"))
			return (1);
	return (0);
}

int	ft_checklimits(t_data *data, int i, int j)
{
	if (ft_limits_0(data, i, j))
		return (1);
	if (ft_limits_init_pos(data, i, j))
		return (1);
	if (ft_map_limits(data) && ((data->map[i][j] == ' '
			&& (ft_strlen(data->map[i])
				< ft_strlen(data->map[i + 1])))
		&& (!ft_chr_in_set(data->map[i][j + 1], " 1\n")
		|| !ft_chr_in_set(data->map[i][j - 1], " 1\n")
		|| !ft_chr_in_set(data->map[i + 1][j], " 1\n")
		|| !ft_chr_in_set(data->map[i - 1][j], " 1\n"))))
		return (1);
	return (0);
}
