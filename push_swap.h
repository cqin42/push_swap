/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cqin <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 12:28:11 by cqin              #+#    #+#             */
/*   Updated: 2023/05/16 16:44:25 by cqin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "get_next_line/get_next_line.h"
# include <limits.h>

typedef struct s_stack
{
	int					value;
	int					index;
	int					position;
	int					target_pos;
	int					nb_mov_a;
	int					nb_mov_b;
	struct s_stack		*next;
}	t_stack;

/*initialisation*/

int		ft_check_input(char *argv);
int		ft_check_duplicate(t_stack **stack_a, t_stack **stack_b);
int		ft_transformation(char **c, t_stack **stack_a);
t_stack	**ft_init_stack(int argc, char **argv, t_stack **stack_a,
			t_stack **stack_b);

/*utils*/
long	ft_atoi_long(const char *nptr);
void	ft_free_stack(t_stack **stack_a);
int		is_sorted(t_stack **stack_a);

/*intructions_utils*/
t_stack	*ft_stacknew(int value);
void	*ft_stackadd_front(t_stack **stack, t_stack *new);
int		ft_stacksize(t_stack *stack);
t_stack	*ft_stacklast(t_stack *stack);
void	*ft_stackadd_back(t_stack **stack, t_stack *new);

/*swap*/
void	ft_swap(t_stack **stack);
void	ft_sa(t_stack **stack_a, int idx);
void	ft_sb(t_stack **stack_b, int idx);
void	ft_ss(t_stack **stack_a, t_stack **stack_b, int idx);

/*push*/
void	ft_push(t_stack **stack_dst, t_stack **stack_src);
void	ft_pa(t_stack **stack_a, t_stack **stack_b, int idx);
void	ft_pb(t_stack **stack_a, t_stack **stack_b, int idx);

/*rotate*/
void	ft_rotate(t_stack **stack);
void	ft_ra(t_stack **stack_a, int idx);
void	ft_rb(t_stack **stack_b, int idx);
void	ft_rr(t_stack **stack_a, t_stack **stack_b, int idx);

/*reverse_rotate*/
void	ft_rra(t_stack **stack_a, int idx);
void	ft_rrb(t_stack **stack_b, int idx);
void	ft_reverse_rotate(t_stack **stack);
void	ft_rrr(t_stack **stack_a, t_stack **stack_b, int idx);

/*small_stack*/
void	mov_small_stack(int i, t_stack **stack);
void	sort_small_stack(t_stack **stack);

/*big_stack*/
void	last_mov(t_stack **stack_a);
void	find_index(t_stack *stack);
void	sort_big_stack(t_stack **stack_a, t_stack **stack_b);

/*push_swap*/
void	push_swap(t_stack **stack_a, t_stack **stack_b);
int		is_sorted(t_stack **stack);

/*positions*/
void	find_position(t_stack *stack);
int		target_position(t_stack	*stack_a, t_stack *stack_b);
int		target_pos(t_stack *stack_a, int max_value);
void	position(t_stack **stack_a, t_stack **stack_b);

/*mov*/
int		negative_to_positive(int value);
void	find_nb_mov(t_stack **stack_a, t_stack **stack_b);
void	find_min_mov(t_stack **stack_a, t_stack **stack_b);
void	single_mov(t_stack **stack_a, t_stack **stack_b, t_stack *tmp_b);
void	exec_min_mov(t_stack **stack_a, t_stack **stack_b, int pos);
#endif
