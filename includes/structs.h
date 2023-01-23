/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 18:02:45 by becastro          #+#    #+#             */
/*   Updated: 2023/01/23 16:08:46 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include <stdint.h>

enum e_axis
{
	X,
	Y,
};

enum e_compass
{
	NORTH,
	SOUTH,
	WEST,
	EASTH,
};
typedef struct s_player
{
	char		init_view;
	double		view;
	double		pos[2];
	uint32_t	tile[2];
}	t_player;

typedef struct s_data
{
	char			*north_texture;
	char			*south_texture;
	char			*east_texture;
	char			*west_texture;
	int				floor;
	int				ceiling;
	char			**map;
	char			compass;
	int				init_x;
	int				init_y;
	struct s_frame	*frame_data;
	struct s_mlx	*mlx_data;
}	t_data;
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
/**
 * @brief
 * struct saving values for mlx data
 */
typedef struct s_mlx_values {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		window_offset[2];
}	t_mlx_values;

typedef struct s_mlx
{
	void				*ptr;
	void				*img;
	void				*addr;
	void				*win;
	struct s_mlx_values	*values;
}	t_mlx;
typedef struct s_frame
{
	char				**map;
	struct s_player		*player;
	struct s_raycast	*raycast;
	struct s_mlx		*mlx;
}	t_frame;

#endif
