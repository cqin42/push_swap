/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cqin <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 12:44:13 by cqin              #+#    #+#             */
/*   Updated: 2023/05/16 15:03:53 by cqin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_stack **stack)
{
	int	tmp;

	if (ft_stacksize(*stack) <= 1)
		return ((void) NULL);
	tmp = (*stack)->value;
	(*stack)->value = (*stack)->next->value;
	(*stack)->next->value = tmp;
	tmp = (*stack)->index;
	(*stack)->index = (*stack)->next->index;
	(*stack)->next->index = tmp;
}

void	ft_sa(t_stack **stack_a, int idx)
{
	ft_swap(stack_a);
	if (idx == 0)
		ft_printf("sa\n");
}

void	ft_sb(t_stack **stack_b, int idx)
{
	ft_swap(stack_b);
	if (idx == 0)
		ft_printf("sb\n");
}

void	ft_ss(t_stack **stack_a, t_stack **stack_b, int idx)
{
	ft_swap(stack_a);
	ft_swap(stack_b);
	if (idx == 0)
		ft_printf("ss\n");
}
