/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-gu <fdiaz-gu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 12:11:38 by fdiaz-gu          #+#    #+#             */
/*   Updated: 2025/02/16 12:13:34 by fdiaz-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap_bonus.h"

static int	ft_strcmp(const char *s1, const char *s2)
{
	size_t			i;
	unsigned char	*s1copy;
	unsigned char	*s2copy;

	i = 0;
	s1copy = (unsigned char *)s1;
	s2copy = (unsigned char *)s2;
	while (s2copy[i] != '\0')
	{
		if (s1copy[i] != s2copy[i])
			return (s1copy[i] - s2copy[i]);
		i++;
	}
	return (s1copy[i] - s2copy[i]);
}

static void	ft_error_cmd(char *line, t_stack **stack_a, t_stack **stack_b)
{
	if (line)
		free(line);
	if (stack_b)
		free_list(*stack_b);
	if (stack_a)
		free_list(*stack_a);
	write(1, "KO\n", 3);
	return ;
}

static int	reverse_movements(char *line, t_stack **stack_a, t_stack **stack_b)
{
	if (!ft_strcmp(line, "rra\n"))
		return (ft_rra(stack_a), 1);
	if (!ft_strcmp(line, "rrb\n"))
		return (ft_rrb(stack_b), 1);
	if (!ft_strcmp(line, "rrr\n"))
		return (ft_rrr(stack_a, stack_b), 1);
	else
		(ft_error_cmd(line, stack_a, stack_b), 0);
	return (0);
}

static int	check_and_execute(char *line, t_stack **stack_a, t_stack **stack_b)
{
	if (!ft_strcmp(line, "sa\n"))
		return (ft_sa(stack_a), 1);
	if (!ft_strcmp(line, "sb\n"))
		return (ft_sb(stack_b), 1);
	if (!ft_strcmp(line, "ss\n"))
		return (ft_ss(stack_a, stack_b), 1);
	if (!ft_strcmp(line, "pa\n"))
		return (ft_pa(stack_a, stack_b), 1);
	if (!ft_strcmp(line, "pb\n"))
		return (ft_pb(stack_a, stack_b), 1);
	if (!ft_strcmp(line, "ra\n"))
		return (ft_ra(stack_a), 1);
	if (!ft_strcmp(line, "rb\n"))
		return (ft_rb(stack_b), 1);
	if (!ft_strcmp(line, "rr\n"))
		return (ft_rr(stack_a, stack_b), 1);
	else
		return (reverse_movements(line, stack_a, stack_b));
}

int	check_commands(t_stack **stack_a, t_stack **stack_b)
{
	char	*line;

	line = get_next_line(0);
	while (line && *line != '\n')
	{
		if (!check_and_execute(line, stack_a, stack_b))
			return (0);
		free(line);
		line = get_next_line(0);
	}
	free(line);
	return (1);
}
