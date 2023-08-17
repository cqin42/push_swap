/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cqin <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 13:25:00 by cqin              #+#    #+#             */
/*   Updated: 2023/05/16 13:22:24 by cqin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atoi_long(const char *nptr)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	if (nptr[i] >= '0' && nptr[i] <= '9')
	{
		while ((nptr[i] != '\0') && (nptr[i] >= '0' && nptr[i] <= '9'))
			result = result * 10 + nptr[i++] - '0';
		return (sign * result);
	}
	return (result);
}

void	ft_free_stack(t_stack **stack_a)
{
	t_stack	*tmp;

	while ((*stack_a) != NULL)
	{
		tmp = (*stack_a);
		(*stack_a) = (*stack_a)->next;
		free(tmp);
	}
	free(stack_a);
}

int	is_sorted(t_stack **stack)
{
	t_stack	*tmp;

	tmp = (*stack);
	while (tmp->next != NULL)
	{
		if (tmp->value > tmp->next->value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
