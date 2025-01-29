/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-gu <fdiaz-gu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 17:38:51 by fdiaz-gu          #+#    #+#             */
/*   Updated: 2025/01/29 17:03:52 by fdiaz-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void print_stack(t_stack **stack)
{
	while (*stack)
	{
		printf("[%d] -> %d\n", (*stack)->index ,(*stack)->value);
		stack = &(*stack)->next;
	}
}

void print_index(t_stack **stack)
{
	while (*stack)
	{
		printf("%d\n", (*stack)->index);
		stack = &(*stack)->next;
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

void start_ordering(t_stack **stack_a, t_stack **stack_b, int size)
{
	int half;
	int aux_index;

	aux_index = size - 2;
	half = (size / 2) + 1;
	while (size > half)
	{
		if ((*stack_a)->index < half)
			(ft_pb(stack_a, stack_b),size--);
		else
			ft_ra(stack_a);
	}	
	while (size > 3)
	{
		if ((*stack_a)->index < aux_index)		
			(ft_pb(stack_a, stack_b), size--);
		else
			ft_ra(stack_a);
	}
	order_three(stack_a);
	printf("STACK A:\n");
	print_stack(stack_a);
	printf("STACK B:\n");
	print_stack(stack_b);
}
