/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cqin <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 12:27:47 by cqin              #+#    #+#             */
/*   Updated: 2023/05/16 14:58:34 by cqin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_reverse_rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*last;
	t_stack	*last_before;

	tmp = (*stack);
	if (!tmp)
		return ((void) NULL);
	last_before = ft_stacklast(tmp);
	last = ft_stacklast((*stack));
	(*stack) = last;
	(*stack)->next = tmp;
	tmp = (*stack);
	while (tmp->next != last_before)
		tmp = tmp->next;
	tmp->next = NULL;
}

void	ft_rra(t_stack **stack_a, int idx)
{
	ft_reverse_rotate(stack_a);
	if (idx == 0)
		ft_printf("rra\n");
}

void	ft_rrb(t_stack **stack_b, int idx)
{
	ft_reverse_rotate(stack_b);
	if (idx == 0)
		ft_printf("rrb\n");
}

void	ft_rrr(t_stack **stack_a, t_stack **stack_b, int idx)
{
	ft_reverse_rotate(stack_a);
	ft_reverse_rotate(stack_b);
	if (idx == 0)
		ft_printf("rrr\n");
}
