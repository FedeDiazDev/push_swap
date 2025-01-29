/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-gu <fdiaz-gu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 11:00:10 by fdiaz-gu          #+#    #+#             */
/*   Updated: 2025/01/29 16:24:11 by fdiaz-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rotate(t_stack **stack)
{
	t_stack	*aux;
	t_stack	*last;

	aux = *stack;
	*stack = (*stack)->next;
	last = ft_lstlast_ps(*stack);
	aux->next = NULL;
	last->next = aux;
}

void	ft_ra(t_stack **stack_a)
{
	rotate(stack_a);
	// ft_printf("%s\n", "ra");
}

void	ft_rb(t_stack **stack_b)
{
	rotate(stack_b);
	ft_printf("%s\n", "rb");
}

void	ft_rr(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_printf("%s\n", "rr");
}
