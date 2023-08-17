/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cqin <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 12:51:16 by cqin              #+#    #+#             */
/*   Updated: 2023/05/16 14:57:05 by cqin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(t_stack **stack)
{
	int		head;
	int		head_index;
	t_stack	*tmp;

	tmp = (*stack);
	if (!stack)
		return ((void) NULL);
	head = tmp->value;
	head_index = tmp->index;
	while (tmp->next != NULL)
	{
		tmp->value = tmp->next->value;
		tmp->index = tmp->next->index;
		tmp = tmp->next;
	}
	if (tmp->next == NULL)
	{
		tmp->value = head;
		tmp->index = head_index;
	}
}

void	ft_ra(t_stack **stack_a, int idx)
{
	ft_rotate(stack_a);
	if (idx == 0)
		ft_printf("ra\n");
}

void	ft_rb(t_stack **stack_b, int idx)
{
	ft_rotate(stack_b);
	if (idx == 0)
		ft_printf("rb\n");
}

void	ft_rr(t_stack **stack_a, t_stack **stack_b, int idx)
{
	ft_rotate(stack_a);
	ft_rotate(stack_b);
	if (idx == 0)
		ft_printf("rr\n");
}
