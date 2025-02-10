/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-gu <fdiaz-gu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 15:19:46 by fdiaz-gu          #+#    #+#             */
/*   Updated: 2025/02/10 19:14:54 by fdiaz-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	is_sorted(t_stack **stack)
{
	if (!stack)
		return (0);
	while ((*stack)->next != NULL)
	{
		if ((*stack)->value > ((*stack)->next)->value)
			return (0);
		stack = &(*stack)->next;
	}
	return (1);
}

void	ft_push_swap(t_stack **stack_a, t_stack **stack_b)
{
	int	s_size;

	s_size = ft_lstsize_ps(stack_a);
	if (s_size == 2 && !(is_sorted(stack_a)))
		ft_sa(stack_a);
	else if (s_size == 3 && !(is_sorted(stack_a)))
		order_three(stack_a);
	else
		start_ordering(stack_a, stack_b, s_size);
	// else if (s_size == 4 && !(is_sorted(stack_a)))
	// 	order_four(stack_a, stack_b);
	// else if (s_size == 5 && !(is_sorted(stack_a)))
	// 	order_five(stack_a, stack_b);
	// else if (s_size <= 100 && !(is_sorted(stack_a)))
	// 	loops_for_hundred(stack_a, stack_b, s_size);
	// else if (s_size > 100 && !(is_sorted(stack_a)))
	// 	loops_for_five_hundred(stack_a, stack_b, s_size);
}

void	ft_free_split(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		ft_error();
	stack_a = resort_ags(argv, &stack_a);
	check_duplicated(&stack_a);
	assign_index(&stack_a, 1);
	ft_push_swap(&stack_a, &stack_b);
	print_stack(&stack_a);
	free_list(stack_a);
	free_list(stack_b);
}
