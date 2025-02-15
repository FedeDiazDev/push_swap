/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-gu <fdiaz-gu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:16:52 by fdiaz-gu          #+#    #+#             */
/*   Updated: 2023/11/21 16:24:19 by fdiaz-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void calculate_lower_pos(t_stack **stack_a, t_stack **stack_b)
{

	while (*stack_b)
	{
		assing_lower_target(stack_a, stack_b);
		stack_b = &(*stack_b)->next;
	}
}

int	find_min_without_stack(t_stack **stack)
{
	int	min;

	min = INT_MAX;
	while ((*stack))
	{
		if (((*stack)->index == 0) && (min > (*stack)->value))
			min = (*stack)->value;
		stack = &(*stack)->next;
	}
	return (min);
}
void assign_costs(t_stack **stack_b, int size_a, int size_b)
{
	t_stack *aux_b;

	aux_b = *stack_b;
	while (aux_b)
	{
		if ((aux_b->pos + 1) <= size_b / 2 + 1)
			aux_b->cost_b = aux_b->pos;
		else
			aux_b->cost_b = aux_b->pos - size_b;
		if ((aux_b->target_pos + 1) <= size_a / 2 + 1)
			aux_b->cost_a = aux_b->target_pos;
		else
			aux_b->cost_a = aux_b->target_pos - size_a;
		aux_b = aux_b->next;
	}
}

int max_index(t_stack **stack)
{
	int max;

	max = (*stack)->index;
	while (*stack)
	{
		if ((*stack)->index > max)
			max = (*stack)->index;
		stack = &(*stack)->next;
	}
	return (max);
}

int	ft_atoi_ps(const char *str)
{
	unsigned long	result;
	int				sign;

	sign = 1;
	result = 0;
	while ((*str == ' ' || ('\t' <= *str && *str <= '\r')))
		str++;
	if (*str == '-')
	{
		sign = -sign;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		if (result > INT_MAX && sign > 0)
			ft_error();
		if (result > INT_MAX && sign < 0)
			ft_error();
		str++;
	}
	return (result * sign);
}
