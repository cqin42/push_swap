/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cqin <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 11:21:44 by cqin              #+#    #+#             */
/*   Updated: 2023/05/17 14:38:08 by cqin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error_check(void)
{
	write(1, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	ft_check_action_second(t_stack **stack_a, t_stack **stack_b, char *line)
{
	if (line[0] == 'r' && line[1] == 'a' && line[2] == '\n')
		ft_ra(stack_a, 1);
	else if (line[0] == 'r' && line[1] == 'b' && line[2] == '\n')
		ft_rb(stack_b, 1);
	else if (line[0] == 'r' && line[1] == 'r' && line[2] == '\n')
		ft_rr(stack_a, stack_b, 1);
	else if (line[0] == 'r' && line[1] == 'r' && (line[2] == 'r'
			&& line[3] == '\n'))
		ft_rrr(stack_a, stack_b, 1);
	else if (line[0] == 'r' && line[1] == 'r' && (line[2] == 'a'
			&& line[3] == '\n'))
		ft_rra(stack_a, 1);
	else if (line[0] == 'r' && line[1] == 'r' && (line[2] == 'b'
			&& line[3] == '\n'))
		ft_rrb(stack_b, 1);
}

char	*ft_check_action(t_stack **stack_a, t_stack **stack_b, char *line)
{
	if (line[0] == 's' && line[1] == 'a' && line[2] == '\n')
		ft_sa(stack_a, 1);
	else if (line[0] == 's' && line[1] == 'b' && line[2] == '\n')
		ft_sb(stack_b, 1);
	else if (line[0] == 's' && line[1] == 's' && line[2] == '\n')
		ft_ss(stack_a, stack_b, 1);
	else if (line[0] == 'p' && line[1] == 'a' && line[2] == '\n')
		ft_pa(stack_a, stack_b, 1);
	else if (line[0] == 'p' && line[1] == 'b' && line[2] == '\n')
		ft_pb(stack_a, stack_b, 1);
	else if (line[0] == 'r')
		ft_check_action_second(stack_a, stack_b, line);
	else
		ft_error_check();
	return (get_next_line(0));
}

void	ft_check(t_stack **a, t_stack **b, char *line)
{
	char	*tmp;
	int		i;

	i = 0;
	if (!line && is_sorted(a) == 0)
		return (ft_printf("KO\n"), (void) NULL);
	while (line && line[i] != '\n')
	{
		tmp = line;
		line = ft_check_action(a, b, line);
		free(tmp);
	}
	if (b != NULL)
		ft_printf("KO\n");
	else if (is_sorted(a) == 0)
		ft_printf("KO\n");
	else if (!line && (is_sorted(a) == 1 && b == NULL))
		ft_printf("OK\n");
	free(line);
}

int	main(int argc, char **argv)
{
	t_stack	**stack_a;
	t_stack	**stack_b;
	char	*line;

	if (argc < 2)
		return (0);
	stack_a = (t_stack **)malloc(sizeof(t_stack));
	stack_b = (t_stack **)malloc(sizeof(t_stack));
	if (!stack_a || !stack_b)
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
	line = get_next_line(STDIN_FILENO);
	ft_check(stack_a, stack_b, line);
	ft_free_stack(stack_b);
	ft_free_stack(stack_a);
	return (1);
}
