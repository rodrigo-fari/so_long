/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_chr_count.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42poto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 13:51:12 by rde-fari          #+#    #+#             */
/*   Updated: 2024/08/09 14:54:03 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_str_chr_count(char *str, int c)
{
	int		i;
	int		a;

	a = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			a++;
		i++;
	}
	return (a);
}