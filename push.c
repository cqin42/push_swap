/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cqin <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 12:48:08 by cqin              #+#    #+#             */
/*   Updated: 2023/05/16 14:55:48 by cqin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(t_stack **stack_dst, t_stack **stack_src)
{
	t_stack	*tmp;

	if (!(*stack_src))
		return ((void) NULL);
	tmp = (*stack_src)->next;
	(*stack_src)->next = (*stack_dst);
	(*stack_dst) = (*stack_src);
	(*stack_src) = tmp;
}

void	ft_pa(t_stack **stack_a, t_stack **stack_b, int idx)
{
	ft_push(stack_a, stack_b);
	if (idx == 0)
		ft_printf("pa\n");
}

void	ft_pb(t_stack **stack_a, t_stack **stack_b, int idx)
{
	ft_push(stack_b, stack_a);
	if (idx == 0)
		ft_printf("pb\n");
}
