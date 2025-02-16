/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-gu <fdiaz-gu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:40:56 by fdiaz-gu          #+#    #+#             */
/*   Updated: 2025/02/16 12:26:58 by fdiaz-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	free_list(t_stack *stack)
{
	t_stack	*tmp;

	while (stack != NULL)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}
}

void	assign_index(t_stack **stack, int index)
{
	t_stack	*first;
	int		min;
	int		stack_size;

	first = (*stack);
	stack_size = ft_lstsize_ps(stack);
	min = find_min_without_stack(stack);
	while (*stack)
	{
		if (((*stack)->index == 0) && ((*stack)->value == min))
		{
			(*stack)->index = index;
			break ;
		}
		stack = &(*stack)->next;
	}
	if (index <= stack_size)
		assign_index(&first, (index + 1));
}

void	print_stack(t_stack **stack)
{
	while (*stack)
	{
		printf("[%d] -> %d\n", (*stack)->index, (*stack)->value);
		stack = &(*stack)->next;
	}
}

void	assing_lower_target(t_stack **stack_a, t_stack **stack_b)
{
	int		closer_idx;
	int		target_pos;
	t_stack	*current;

	closer_idx = max_index(stack_a);
	current = *stack_a;
	while (current)
	{
		if ((*stack_b)->index < current->index && closer_idx > current->index)
		{
			closer_idx = current->index;
			target_pos = current->pos;
		}
		current = current->next;
	}
	(*stack_b)->target_pos = target_pos;
}
