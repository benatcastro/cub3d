/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   danae.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 02:50:34 by becastro          #+#    #+#             */
/*   Updated: 2022/12/16 15:07:44 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DANAE_H
# define DANAE_H

# include <stdio.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdint.h>
# include "libft.h"
# include "structs.h"
# include "dn_raycast.h"
# include "../src/mlx_darwin/mlx.h"
# include "../src/mlx_linux/mlx.h"
//colors

# define RED 		0x00FF0000
# define FLAMINGO	0x00F8C4F8
# define ROSE		0x00E2252B
# define SHAMROCK	0x0003AC13
# define SEAFOAM	0x003DED97
# define ORANGE		0x00FCAE1E
# define YELLOW		0x00FFF866
# define ARCTIC		0x0082EEFD
# define CERULEAN	0x000492C2
//init fncs
void	dn_init_loop(t_data *data);
void	dn_init(uint32_t height, uint32_t width, char *title, t_data *data);

//render fncs
void	dn_put_pixel(t_mlx *mlx, int x, int y, int color);
int		dn_render_frame(void *frame_info);

//hook fncs
void	dn_event_handler(t_data *data);
int		hook_handler(int hook, void *data);

//utils fncs
void	dn_init_frame(t_data *data);
void	dn_screen_offset(t_mlx *mlx, uint32_t width, uint32_t height);
void	dn_error(void);

#endif
