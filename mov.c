/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cqin <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 12:04:00 by cqin              #+#    #+#             */
/*   Updated: 2023/05/16 15:03:39 by cqin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_nb_mov(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp_b;
	int		size_a;
	int		size_b;

	size_a = ft_stacksize(*stack_a);
	size_b = ft_stacksize(*stack_b);
	tmp_b = (*stack_b);
	while (tmp_b != NULL)
	{
		if (tmp_b->position - 1 > size_b / 2)
			tmp_b->nb_mov_b = -(size_b - (tmp_b->position - 1));
		else
			tmp_b->nb_mov_b = tmp_b->position - 1;
		if (tmp_b->target_pos - 1 > size_a / 2)
			tmp_b->nb_mov_a = -(size_a - (tmp_b->target_pos - 1));
		else
			tmp_b->nb_mov_a = tmp_b->target_pos - 1;
		tmp_b = tmp_b->next;
	}
}

void	single_mov(t_stack **stack_a, t_stack **stack_b, t_stack *tmp_b)
{
	while (tmp_b->nb_mov_a < 0)
	{
		ft_rra(stack_a, 0);
		tmp_b->nb_mov_a = tmp_b->nb_mov_a + 1;
	}
	while (tmp_b->nb_mov_a > 0)
	{
		ft_ra(stack_a, 0);
		tmp_b->nb_mov_a = tmp_b->nb_mov_a - 1;
	}
	while (tmp_b->nb_mov_b < 0)
	{
		ft_rrb(stack_b, 0);
		tmp_b->nb_mov_b = tmp_b->nb_mov_b + 1;
	}
	while (tmp_b->nb_mov_b > 0)
	{
		ft_rb(stack_b, 0);
		tmp_b->nb_mov_b = tmp_b->nb_mov_b - 1;
	}
}

void	exec_min_mov(t_stack **stack_a, t_stack **stack_b, int pos)
{
	t_stack	*tmp_b;

	tmp_b = *stack_b;
	while (tmp_b->position != pos)
	{
		tmp_b = tmp_b->next;
	}
	while (tmp_b->nb_mov_a < 0 && tmp_b->nb_mov_b < 0)
	{
		ft_rrr(stack_a, stack_b, 0);
		tmp_b->nb_mov_a = tmp_b->nb_mov_a + 1;
		tmp_b->nb_mov_b = tmp_b->nb_mov_b + 1;
	}
	while (tmp_b->nb_mov_a > 0 && tmp_b->nb_mov_b > 0)
	{
		ft_rr(stack_a, stack_b, 0);
		tmp_b->nb_mov_a = tmp_b->nb_mov_a - 1;
		tmp_b->nb_mov_b = tmp_b->nb_mov_b - 1;
	}
	single_mov(stack_a, stack_b, tmp_b);
	if (tmp_b->nb_mov_b == 0 && tmp_b->nb_mov_a == 0)
		ft_pa(stack_a, stack_b, 0);
}

int	negative_to_positive(int value)
{
	if (value < 0)
		value = value * -1;
	return (value);
}

void	find_min_mov(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp_b;
	int		min_mov;
	int		mov_a;
	int		mov_b;
	int		pos;

	pos = 0;
	min_mov = INT_MAX;
	tmp_b = (*stack_b);
	while (tmp_b != NULL)
	{
		mov_a = tmp_b->nb_mov_a;
		mov_b = tmp_b->nb_mov_b;
		mov_a = negative_to_positive(mov_a);
		mov_b = negative_to_positive(mov_b);
		if (mov_a + mov_b < min_mov)
		{
			min_mov = mov_a + mov_b;
			pos = tmp_b->position;
		}
		tmp_b = tmp_b->next;
	}
	if (min_mov != INT_MAX)
		exec_min_mov(stack_a, stack_b, pos);
}
