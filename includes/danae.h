/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   danae.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 02:50:34 by becastro          #+#    #+#             */
/*   Updated: 2022/12/13 09:54:53 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DANAE_H
# define DANAE_H

# include <stdio.h>
# include <stdbool.h>
# include <stdio.h>
# include "libft.h"
# include "struct.h"
# include "mlx.h"

void	dn_init(u_int32_t height, u_int32_t width, char *title);
void	dn_render_frame(void *frame_info);
void	dn_error(void);

#endif
