/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-gu <fdiaz-gu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 17:38:51 by fdiaz-gu          #+#    #+#             */
/*   Updated: 2025/02/10 19:13:54 by fdiaz-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void assign_positions(t_stack **stack)
{
	int pos = 0;
	while (*stack)
	{
		(*stack)->pos = pos;
		pos++;
		stack = &(*stack)->next;
	}
}

void assing_target(t_stack **stack_a, t_stack **stack_b)
{
	while (*stack_b)
	{
		calculate_lower_pos(stack_a, stack_b);
		stack_b = &(*stack_b)->next;
	}
}

void order_three(t_stack **stack_a)
{
	if ((*stack_a)->value < (*stack_a)->next->value)
	{
		if ((*stack_a)->value > (*stack_a)->next->next->value)
			ft_rra(stack_a);
		else
		{
			ft_rra(stack_a);
			ft_sa(stack_a);
		}
	}
	else
	{
		if ((*stack_a)->next->value > (*stack_a)->next->next->value)
		{
			ft_sa(stack_a);
			ft_rra(stack_a);
		}
		else
		{
			if ((*stack_a)->value > (*stack_a)->next->next->value)
				ft_ra(stack_a);
			else
				ft_sa(stack_a);
		}
	}
}
static void push_all_except_three(t_stack **stack_a, t_stack **stack_b, int size)
{
	int half;
	int current_size;

	half = (size / 2) + 1;
	current_size = size;
	while (current_size > half && current_size >= 3)
	{
		if ((*stack_a)->index < half)
			(ft_pb(stack_a, stack_b), current_size--);
		else
			ft_ra(stack_a);
	}
	while (current_size > 3)
	{
		if ((*stack_a)->index == size || (*stack_a)->index == size - 1 || (*stack_a)->index == size - 2)
			ft_ra(stack_a);
		else
			(ft_pb(stack_a, stack_b), current_size--);
	}
	if (!is_sorted(stack_a))
		order_three(stack_a);
}

void start_ordering(t_stack **stack_a, t_stack **stack_b, int size)
{
	push_all_except_three(stack_a, stack_b, size);
	while (*stack_b)
	{
		assign_positions(stack_a);
		assign_positions(stack_b);
		calculate_lower_pos(stack_a, stack_b);
		assign_costs(stack_b, ft_lstsize_ps(stack_a), ft_lstsize_ps(stack_b));
		calculate_optimal(stack_a, stack_b);
	}
	order_a(stack_a);
}

// printf("STACK A:\n");
// print_stack(stack_a);
// printf("STACK B:\n");
// print_stack(stack_b);