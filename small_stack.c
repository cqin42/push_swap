/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cqin <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 11:35:04 by cqin              #+#    #+#             */
/*   Updated: 2023/05/16 15:00:23 by cqin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	mov_small_stack(int i, t_stack **stack)
{
	if (i == 1)
	{
		ft_ra(stack, 0);
		if (is_sorted(stack) == 0)
			ft_sa(stack, 0);
	}
	else if (i == 2)
	{
		ft_rra(stack, 0);
		if (is_sorted(stack) == 0)
			ft_sa(stack, 0);
	}
	else if (i == 3)
		ft_sa(stack, 0);
}

void	sort_small_stack(t_stack **stack)
{
	t_stack	*tmp;
	int		i;

	tmp = (*stack);
	if (is_sorted(stack) == 1)
		return ((void) NULL);
	if (tmp->value > tmp->next->value)
	{
		if (tmp->value > tmp->next->next->value)
			i = 1;
		else
			i = 3;
	}
	else if (tmp->value < tmp->next->value)
	{
		if (tmp->next->value > tmp->next->next->value)
			i = 2;
		else
			i = 3;
	}
	mov_small_stack(i, stack);
}
