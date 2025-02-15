#ifndef PUSH_SWAP_BONUS_H
#define PUSH_SWAP_BONUS_H

#include <stdlib.h>
#include <limits.h>
#include <unistd.h>
typedef struct s_stack
{
	int value;
	int index;
	int pos;
	int cost_a;
	int cost_b;
	int target_pos;
	struct s_stack *next;
} t_stack;

void free_list(t_stack *stack);
char *get_next_line(int fd);
void ft_sa(t_stack **stack_a);
void ft_sb(t_stack **stack_b);
void ft_ss(t_stack **stack_a, t_stack **stack_b);
void ft_ra(t_stack **stack_a);
void ft_rb(t_stack **stack_b);
void ft_rr(t_stack **stack_a, t_stack **stack_b);
void ft_rra(t_stack **stack_a);
void ft_rrb(t_stack **stack_b);
void ft_rrr(t_stack **stack_a, t_stack **stack_b);
void ft_pa(t_stack **stack_a, t_stack **stack_b);
void ft_pb(t_stack **stack_a, t_stack **stack_b);
void ft_error(void);
void free_list(t_stack *stack);
void ft_free_split(char **str);
void ft_lstadd_back_ps(t_stack **lst, t_stack *new);
t_stack *check_nb_in_argv(char *str, t_stack **stack_a);
t_stack *check_and_save(char *str, t_stack **first_node);
t_stack *ft_lstnew_ps(int content);
t_stack *resort_ags(char **argv, t_stack **stack);
t_stack		*ft_get_penultimate(t_stack *stack);
void check_duplicated(t_stack **stack_a);
int check_commands(t_stack **stack_a, t_stack **stack_b);
int check_if_nb(char *str);
int ft_atoi_ps(const char *str);
char **ft_split(char const *s, char c);
char *ft_substr(char const *s, unsigned int start, size_t len);
size_t ft_strlen(const char *str);
char *ft_strdup(const char *s1);
size_t ft_strlcpy(char *dst, const char *src, size_t size);
void *ft_memcpy(void *dst, const void *src, size_t n);
int			ft_lstsize_ps(t_stack **stack);


#endif