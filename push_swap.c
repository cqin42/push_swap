/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cqin <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 14:18:06 by cqin              #+#    #+#             */
/*   Updated: 2023/05/16 15:01:04 by cqin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_stack **stack_a, t_stack **stack_b)
{
	if (is_sorted(stack_a) == 1)
		return ;
	if (ft_stacksize(*stack_a) == 2)
		ft_sa(stack_a, 0);
	else if (ft_stacksize(*stack_a) == 3)
		sort_small_stack(stack_a);
	else if (ft_stacksize(*stack_a) > 3)
		sort_big_stack(stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	t_stack	**stack_a;
	t_stack	**stack_b;

	if (argc < 2)
		return (0);
	stack_a = (t_stack **)malloc(sizeof(t_stack));
	if (!stack_a)
		return (0);
	stack_b = (t_stack **)malloc(sizeof(t_stack));
	if (!stack_b)
		return (0);
	*stack_b = NULL ;
	*stack_a = NULL;
	stack_a = ft_init_stack(argc, argv, stack_a, stack_b);
	if (ft_check_duplicate(stack_a, stack_b) == 0)
	{
		ft_free_stack(stack_b);
		ft_free_stack(stack_a);
		return (ft_printf("Error\n"), 0);
	}
	find_index(*stack_a);
	push_swap(stack_a, stack_b);
	ft_free_stack(stack_b);
	ft_free_stack(stack_a);
	return (1);
}
