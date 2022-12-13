/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   danae.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 02:50:34 by becastro          #+#    #+#             */
/*   Updated: 2022/12/13 03:19:54 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DANAE_H
# define DANAE_H

# include <stdio.h>
# include "mlx_darwin.h"
# include "libft.h"
# include "struct.h"

void	dn_init(u_int32_t height, u_int32_t width, char *title);
void	dn_init_loop(void);
void	dn_render_frame(void *frame_info);

#endif
