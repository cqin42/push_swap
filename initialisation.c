/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cqin <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 13:28:01 by cqin              #+#    #+#             */
/*   Updated: 2023/05/15 13:03:26 by cqin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_input(char *argv)
{
	int	i;

	i = 0;
	if (argv[i] == '+' || argv[i] == '-')
		i++;
	while (argv[i])
	{
		if (ft_isdigit(argv[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_check_duplicate(t_stack **stack_a, t_stack **stack_b)
{
	int		content;
	t_stack	*tmp;
	t_stack	*stack;

	stack = (*stack_a);
	if (!stack)
	{
		ft_free_stack(stack_a);
		ft_free_stack(stack_b);
		exit(EXIT_FAILURE);
	}
	while (stack != NULL)
	{
		content = stack->value;
		tmp = stack;
		while (tmp->next != NULL)
		{
			tmp = tmp->next;
			if (content == tmp->value)
				return (0);
		}
		stack = stack->next;
	}
	return (1);
}

int	ft_transformation(char **c, t_stack **stack_a)
{
	long	tmp;
	int		i;

	i = 0;
	while (c[i] != NULL)
	{
		if (ft_check_input(c[i]) == 0)
			return (free(c[i]), free(c), 0);
		tmp = ft_atoi_long(c[i]);
		if (tmp < INT_MIN || tmp > INT_MAX)
			return (free(c[i]), free(c), 0);
		if (!*stack_a)
			*stack_a = ft_stacknew(tmp);
		else
			ft_stackadd_back(stack_a, ft_stacknew(tmp));
		free(c[i]);
		i++;
	}
	return (1);
}

t_stack	**ft_init_stack(int argc, char **argv, t_stack **stack_a,
			t_stack **stack_b)
{
	int		i;
	char	**str;

	i = 1;
	while (i < argc)
	{
		str = ft_split(argv[i], ' ');
		if (ft_transformation(str, stack_a) == 0)
		{
			ft_printf("Error\n");
			ft_free_stack(stack_a);
			ft_free_stack(stack_b);
			exit(EXIT_FAILURE);
		}
		i++;
		free(str);
	}
	return (stack_a);
}
