/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   positions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cqin <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 12:46:06 by cqin              #+#    #+#             */
/*   Updated: 2023/03/02 14:20:45 by cqin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_position(t_stack *stack)
{
	t_stack	*tmp;
	int		i;

	tmp = stack;
	i = 1;
	while (tmp != NULL)
	{
		tmp->position = i;
		tmp = tmp->next;
		i++;
	}
}

int	target_pos(t_stack *stack_a, int max_value)
{
	t_stack	*tmp_a;
	int		target;

	target = 0;
	tmp_a = stack_a;
	while (tmp_a != NULL)
	{
		if (tmp_a->index < max_value)
		{
			max_value = tmp_a->index;
			target = tmp_a->position;
		}
		tmp_a = tmp_a->next;
	}
	return (target);
}

int	target_position(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*tmp_a;
	int		max_value;
	int		target;

	tmp_a = stack_a;
	max_value = INT_MAX;
	target = 0;
	while (tmp_a != NULL)
	{
		if (stack_b->index < tmp_a->index && tmp_a->index < max_value)
		{
			max_value = tmp_a->index;
			target = tmp_a->position;
		}
		tmp_a = tmp_a->next;
	}
	if (max_value != INT_MAX)
		return (target);
	target = target_pos(stack_a, max_value);
	return (target);
}

void	position(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;

	find_position(*stack_a);
	find_position(*stack_b);
	tmp = (*stack_b);
	while (tmp != NULL)
	{
		tmp->target_pos = target_position(*stack_a, tmp);
		tmp = tmp->next;
	}
}
