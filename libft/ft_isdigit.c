/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cqin <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:25:39 by cqin              #+#    #+#             */
/*   Updated: 2022/11/16 13:50:55 by cqin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

/*int	main(void)
{
	printf("c :%d\nc :%d\n ",ft_isdigit('c'),isdigit('c'));
	printf("0 :%d\n0 :%d\n",ft_isdigit('0'),isdigit('0'));
}*/
