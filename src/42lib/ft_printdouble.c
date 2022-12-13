/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printdouble.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 07:30:08 by becastro          #+#    #+#             */
/*   Updated: 2022/12/13 07:48:04 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_printdouble(char **str)
{
	int	i;

	if (!str || str[0])
		return ((void)printf("Print err\n"), 1);
	i = -1;
	while (str[++i])
		printf("%s", str[i]);
	return (i);
}
