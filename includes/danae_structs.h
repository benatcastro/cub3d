/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   danae_structs.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 13:00:50 by becastro          #+#    #+#             */
/*   Updated: 2022/12/13 14:02:16 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DANAE_STRUCTS_H
# define DANAE_STRUCTS_H

typedef struct s_mlx
{
	void	*ptr;
	void	*img;
	void	*addr;
	void	*win;
	int		bpp;
	int		ll;
	int		endian;
	int		offset;
}	t_mlx;
typedef struct s_frame
{
	struct s_mlx	*mlx;
}	t_frame;

#endif
