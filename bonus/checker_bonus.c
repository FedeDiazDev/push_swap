#include "../include/push_swap_bonus.h"

void	check_duplicated(t_stack **stack_a)
{
	t_stack	*aux;

	if (!stack_a)
		return ;
	while ((*stack_a)->next)
	{
		aux = (*stack_a)->next;
		while (aux != NULL)
		{
			if ((*stack_a)->value == aux->value)
				ft_error();
			aux = aux->next;
		}
		stack_a = &(*stack_a)->next;
	}
}

int is_sorted(t_stack **stack)
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

int main(int argc, char **argv)
{
    t_stack *stack_a;
    t_stack *stack_b;

    stack_a = NULL;
    stack_b = NULL;
    if (argc == 1 || (argc == 2 && !argv[1][0]))
        return (1);
    stack_a = resort_ags(argv, &stack_a);
    check_duplicated(&stack_a);
    if (check_commands(&stack_a, &stack_b))
    {
        if (stack_a && is_sorted(&stack_a) && !stack_b)
            write(1, "OK\n", 3);
        else
            write(1, "KO\n", 3);
    }
    if (stack_a)
        free_list(stack_a);
    if (stack_b)
        free_list(stack_b);
    return (0);
}