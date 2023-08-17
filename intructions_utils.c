/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intructions_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cqin <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 17:55:15 by cqin              #+#    #+#             */
/*   Updated: 2023/05/15 13:01:57 by cqin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_stacknew(int value)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->value = value;
	new->next = NULL;
	new->index = 0;
	new->position = -1;
	new->target_pos = -1;
	new->nb_mov_a = -1;
	new->nb_mov_b = -1;
	return (new);
}

void	*ft_stackadd_front(t_stack **stack, t_stack *new)
{
	if (!(stack == NULL || new == NULL))
	{
		new->next = *stack;
		*stack = new;
	}
	return (stack);
}

int	ft_stacksize(t_stack *stack)
{
	int	size;

	size = 0;
	while (stack != NULL)
	{
		stack = stack->next;
		size++;
	}
	return (size);
}

t_stack	*ft_stacklast(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next != NULL)
		stack = stack->next;
	return (stack);
}

void	*ft_stackadd_back(t_stack **stack, t_stack *new)
{
	t_stack	*tmp;

	if (stack)
	{
		if ((*stack) == NULL)
			(*stack) = new;
		else
		{
			tmp = ft_stacklast((*stack));
			tmp->next = new;
		}
	}
	return (stack);
}
