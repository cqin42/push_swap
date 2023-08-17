/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cqin <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 15:36:03 by cqin              #+#    #+#             */
/*   Updated: 2023/05/16 15:01:26 by cqin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	last_mov(t_stack **stack_a)
{
	t_stack	*tmp;

	tmp = (*stack_a);
	while (tmp->next != NULL)
	{
		if (tmp->value > tmp->next->value)
		{
			if (tmp->position >= ft_stacksize(tmp) / 2)
				while (is_sorted(stack_a) == 0)
					ft_rra(stack_a, 0);
			else
				while (is_sorted(stack_a) == 0)
					ft_ra(stack_a, 0);
		}
		else
			tmp = tmp->next;
	}
}

void	find_index(t_stack *stack)
{
	t_stack	*tmp;
	t_stack	*biggest;
	int		size;
	int		max_value;

	size = ft_stacksize(stack);
	while (size > 0)
	{
		tmp = stack;
		max_value = INT_MIN;
		biggest = NULL;
		while (tmp != NULL)
		{
			if (tmp->index == 0 && tmp->value > max_value)
			{
				max_value = tmp->value;
				biggest = tmp;
			}
			else
				tmp = tmp->next;
		}
		if (biggest != NULL)
			biggest->index = size;
		size--;
	}
}

void	begin_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	i;
	int	j;
	int	size;

	size = ft_stacksize(*stack_a);
	i = 0;
	j = 0;
	while (size > 6 && (j < size && i < size / 2))
	{
		if ((*stack_a)->index <= size / 2)
		{
			ft_pb(stack_a, stack_b, 0);
			i++;
		}
		else
			ft_ra(stack_a, 0);
		j++;
	}
}

void	sort_big_stack(t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	if (is_sorted(stack_a) == 1)
		return ((void) NULL);
	begin_sort(stack_a, stack_b);
	size = ft_stacksize(*stack_a);
	while (size > 3)
	{
		ft_pb(stack_a, stack_b, 0);
		size--;
	}
	sort_small_stack(stack_a);
	size = ft_stacksize(*stack_b);
	while (size > 0)
	{
		position(stack_a, stack_b);
		find_nb_mov(stack_a, stack_b);
		find_min_mov(stack_a, stack_b);
		size--;
	}
	if (is_sorted(stack_a) == 0)
		last_mov(stack_a);
}
