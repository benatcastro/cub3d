/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 03:09:30 by becastro          #+#    #+#             */
/*   Updated: 2022/12/16 14:47:09 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include "danae.h"
# define NAME	"cub3d"
# define WIDTH	1920
# define HEIGHT	1080

# define ENOTXPM "File has not an xpm extension"


/* User input errors */
int		init_cub3d(int argc, char **argv, t_data *data);
int		ft_input_errors(int argc, char *file);
int		ft_file_errors(t_file *file, t_data *data, t_color *color);
int		ft_fill_data(t_data *data, char *line);
int		ft_invalidmap_line(char **file_content);
int		ft_create_map(t_data *data, char **file_content);
int		ft_checklimits(t_data *data, int i, int j);
int		ft_invalidcolor_line(t_data *data, t_color *color, char **content);
char	*ft_get_next_line(int fd);

/* Different general utilities functions */
void	ft_freedata(t_data *data);
void	ft_init_structs(t_data *data, t_color *color);
void	ft_trim_data(t_data *data);
int		ft_start(t_data *data);
void	ft_color_res(t_data *data);
#endif
