/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   danae.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 02:50:34 by becastro          #+#    #+#             */
/*   Updated: 2022/12/13 14:00:04 by becastro         ###   ########.fr       */
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
# include "danae_structs.h"
# include "mlx.h"

t_mlx	*dn_init(u_int32_t height, u_int32_t width, char *title);
void	dn_render_frame(void *frame_info);
void	dn_put_pixel(uint16_t y, u_int16_t x, int color, t_mlx *mlx);
void	dn_error(void);

#endif
