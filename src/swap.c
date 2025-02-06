/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-gu <fdiaz-gu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 11:00:12 by fdiaz-gu          #+#    #+#             */
/*   Updated: 2025/01/29 17:53:37 by fdiaz-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	ft_swap(t_stack **stack)
{
	t_stack	*aux_stack;

	if (ft_lstsize_ps(stack) < 2)
		return ;
	aux_stack = *stack;
	*stack = (*stack)->next;
	aux_stack->next = (*stack)->next;
	(*stack)->next = aux_stack;
}

void	ft_sa(t_stack **stack_a)
{
	ft_swap(stack_a);
	ft_printf("%s\n", "sa");
}

void	ft_sb(t_stack **stack_b)
{
	ft_swap(stack_b);
	ft_printf("%s\n", "sb");
}

void	ft_ss(t_stack **stack_a, t_stack **stack_b)
{
	ft_swap(stack_a);
	ft_swap(stack_b);
	ft_printf("%s\n", "ss");
}
