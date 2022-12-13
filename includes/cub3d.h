/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 03:09:30 by becastro          #+#    #+#             */
/*   Updated: 2022/12/13 07:21:41 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# define WIDTH	1920
# define HEIGHT	1080
# define ENOTXPM "File has not an xpm extension"

typedef struct s_file
{
	int		file_fd;
	int		file_size;
	char	*file;
}	t_file;

typedef struct s_color
{
	int		ceiling_integer;
	int		floor_integer;
	int		color_r;
	int		color_g;
	int		color_b;
}	t_color;

typedef struct s_data
{
	char		*north_texture;
	char		*south_texture;
	char		*east_texture;
	char		*west_texture;
	int			floor;
	int			ceiling;
	char		**map;
	char		compass;
	int			init_x;
	int			init_y;
}	t_data;

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
