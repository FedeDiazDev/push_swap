/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-gu <fdiaz-gu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 10:50:44 by fdiaz-gu          #+#    #+#             */
/*   Updated: 2025/02/10 19:14:37 by fdiaz-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include "../libft/libft.h"
# include "../libft/ft_printf.h"
# include "../libft/get_next_line.h"

typedef struct s_stack
{
	int				value;
	int				index;
	int				pos;
	int				cost_a;
	int				cost_b;
	int				target_pos;
	struct s_stack	*next;
}t_stack;

void		start_ordering(t_stack **stack_a, t_stack **stack_b, int size);
t_stack		*ft_get_penultimate(t_stack *stack);
void		order_three(t_stack **stack_a);
void		ft_sa(t_stack **stack_a);
void		ft_sb(t_stack **stack_b);
void		ft_ss(t_stack **stack_a, t_stack **stack_b);
void		ft_ra(t_stack **stack_a);
void		ft_rb(t_stack **stack_b);
void		ft_rr(t_stack **stack_a, t_stack **stack_b);
void		ft_rra(t_stack **stack_a);
void		ft_rrb(t_stack **stack_b);
void		ft_rrr(t_stack **stack_a, t_stack **stack_b);
void		ft_pa(t_stack **stack_a, t_stack **stack_b);
void		ft_pb(t_stack **stack_a, t_stack **stack_b);
void		check_duplicated(t_stack **stack_a);
int			check_if_nb(char *str);
void		ft_lstadd_back_ps(t_stack **lst, t_stack *new);
void		ft_lstadd_front_ps(t_stack **lst, t_stack *new);
t_stack		*check_nb_in_argv(char *str, t_stack **stack_a);
t_stack		*check_and_save(char *str, t_stack **first_node);
t_stack		*ft_lstnew_ps(int content);
t_stack		*ft_lstlast_ps(t_stack *lst);
t_stack		*resort_ags(char **argv, t_stack **stack);
void		ft_error(void);
int			find_min(t_stack **stack);
int			is_sorted(t_stack **stack);
int			ft_lstsize_ps(t_stack **stack);
void		free_list(t_stack *stack);
void		ft_free_split(char **str);
void		assign_index(t_stack **stack, int index);
int			find_min_without_stack(t_stack **stack);
int			find_pos_index(t_stack **stack, int nb);
int			find_pos_value(t_stack **stack, int nb);
int			find_max(t_stack **stack);
int			ft_atoi_ps(const char *str);
int			max_index(t_stack **stack);
void		assign_costs(t_stack **stack_b, int size_a, int size_b);
void		print_stack(t_stack **stack);
void		assign_positions(t_stack **stack);
int calc_rotations(t_stack **stack_a, int size);
void order_a(t_stack **stack);
int absv(int num);
void exec_move(t_stack **stack_a, t_stack **stack_b, int movs_a, int movs_b);
void calculate_optimal(t_stack **stack_a, t_stack **stack_b);
void assing_lower_target(t_stack **stack_a, t_stack **stack_b);
void calculate_lower_pos(t_stack **stack_a, t_stack **stack_b);



#endif