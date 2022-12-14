/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   danae.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 02:50:34 by becastro          #+#    #+#             */
/*   Updated: 2022/12/14 21:56:24 by becastro         ###   ########.fr       */
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

//init fncs
void	dn_init_image(u_int32_t height, uint32_t width, t_data *data);
void	dn_init(uint32_t height, uint32_t width, char *title, t_data *data);

//render fncs
void	dn_put_pixel(t_mlx *mlx, uint16_t x, uint16_t y, int color);
void	dn_render_frame(void *frame_info);

//hook fncs
void	dn_event_handler(t_data *data);
int		hook_handler(int hook, void *data);

//utils fncs
void	dn_error(void);

#endif
