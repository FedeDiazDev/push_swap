/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-gu <fdiaz-gu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 13:21:14 by fdiaz-gu          #+#    #+#             */
/*   Updated: 2025/02/16 12:26:15 by fdiaz-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	calc_rotations(t_stack **stack_a, int size)
{
	assign_positions(stack_a);
	while ((*stack_a))
	{
		if ((*stack_a)->index == 1)
		{
			if (((*stack_a)->pos + 1) <= (size / 2 + 1))
				return ((*stack_a)->pos);
			else
				return ((*stack_a)->pos - size);
		}
		stack_a = &(*stack_a)->next;
	}
	return (0);
}

void	order_a(t_stack **stack)
{
	int	rotations;

	rotations = calc_rotations(stack, ft_lstsize_ps(stack));
	while (rotations != 0)
	{
		if (rotations < 0)
			(ft_rra(stack), rotations++);
		else
			(ft_ra(stack), rotations--);
	}
}

int	absv(int num)
{
	if (num < 0)
		return (num * -1);
	return (num);
}

void	exec_move(t_stack **stack_a, t_stack **stack_b, int movs_a, int movs_b)
{
	while (movs_a > 0 && movs_b > 0)
		(ft_rr(stack_a, stack_b), movs_a--, movs_b--);
	while (movs_a < 0 && movs_b < 0)
		(ft_rrr(stack_a, stack_b), movs_a++, movs_b++);
	while (movs_a > 0)
		(ft_ra(stack_a), movs_a--);
	while (movs_a < 0)
		(ft_rra(stack_a), movs_a++);
	while (movs_b > 0)
		(ft_rb(stack_b), movs_b--);
	while (movs_b < 0)
		(ft_rrb(stack_b), movs_b++);
}

void	calculate_optimal(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*best_node;
	t_stack	*aux_b;

	best_node = *stack_b;
	aux_b = *stack_b;
	while (aux_b)
	{
		if ((absv(best_node->cost_a) + absv(best_node->cost_b))
			> (absv(aux_b->cost_a) + absv(aux_b->cost_b)))
		{
			best_node = aux_b;
		}
		aux_b = aux_b->next;
	}
	exec_move(stack_a, stack_b, best_node->cost_a, best_node->cost_b);
	ft_pa(stack_a, stack_b);
}
