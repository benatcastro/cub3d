/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   danae.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 02:50:34 by becastro          #+#    #+#             */
/*   Updated: 2022/12/15 16:36:17 by becastro         ###   ########.fr       */
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
# include "../src/mlx_darwin/mlx.h"
# include "../src/mlx_linux/mlx.h"
//colors

# define RED 0x00FF0000
//init fncs
void	dn_init_loop(t_data *data);
void	dn_init(uint32_t height, uint32_t width, char *title, t_data *data);

//render fncs
void	dn_put_pixel(t_mlx *mlx, uint16_t x, uint16_t y, int color);
int		dn_render_frame(void *frame_info);

//hook fncs
void	dn_event_handler(t_data *data);
int		hook_handler(int hook, void *data);

//utils fncs
void	dn_get_frame(t_data *data, t_frame *frame);
void	dn_screen_offset(t_mlx *mlx, uint32_t width, uint32_t height);
void	dn_error(void);

#endif
