/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 15:44:04 by seongjko          #+#    #+#             */
/*   Updated: 2023/08/10 15:44:05 by seongjko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "./libft/libft.h"

# define BUFFER_SIZE 5
# define SUCCESS 0
# define FAILURE 1
# define INT_MIN -2147483648
# define INT_MAX 2147483647

typedef struct s_stack {
	int		*a;
	int		*b;
	int		i;
	int		j;
	int		min_cost_a;
	int		min_cost_b;
	int		min_i;
	int		min_j;
	int		element_cnt;
	int		*pivot_ary;
	int		pivot_cnt;
	int		instruction_cnt;
	int		temp;
}	t_stack;

int			check_valid(int argc, char **argv, t_stack *s);
void		put_in_a(char **ary, t_stack *s);
char		*make_ary(int argc, char **argv);
char		*first_ary(char **ary);
int			cnt_second_ary(char **ary);
void		double_freedom(char **ary);
int			is_dup(char **ary);
int			is_number(char **ary);
char		*strjoin_stdin(int element_cnt, char **argv);
char		*get_next_line(int fd);
char		*line(char **rest, int fd);
char		*cut(char **rest, int new_pos, int i);
char		*ft_strrest(char *buff, int new_pos);
int			ft_strchr_g(const char *s, int c);
char		*ft_strndup_g(char *str, int len);
char		*ft_strjoin_g(char *dest, char *append);
size_t		ft_strlen_g(const char *str);
int			read_instruction(t_stack *s);
void		execute_instruction(char *ins, t_stack *s);
int			check_instruction(char *ins);
void		find_pivot(t_stack *s, int pivot_cnt);
void		sort(int *stack_a_copy, int element_cnt);
int			*stackdup(int *stack_a, int element_cnt);
int			find_max(t_stack *s);
void		send_max_to_stack_a(t_stack *s);
int			find_last(t_stack *s);
int			find_middle(t_stack *s, int g_cnt);
int			find_first(t_stack *s);
void		find_last_and_send_to_b(t_stack *s);
void		find_middle_and_send_to_b(t_stack *s);
void		find_first_and_send_to_b(t_stack *s);
int			find_pivot_index(t_stack *s, int pivot);
void		send_pivot_to_stack_b(t_stack *s, int index);
void		send_groups_to_stack_b(t_stack *s);
int			find_cost_b(t_stack *s, int j, int *min_j);
int			find_cost_a(t_stack *s, int j, int *min_i);
int			find_min_pos_among_bigger_than_b(t_stack *s, int j);
int			abs(int num);
void		find_min_cost_combi(t_stack *s);
void		min_cost_value_to_top_a(t_stack *s);
void		min_cost_value_to_top_b(t_stack *s);
int			find_min_value_index_in_a(t_stack *s);
int			find_max_i_b(t_stack *s);
void		send_b_max_to_a_top(t_stack *s);
void		sort_ascending(t_stack *s);
void		sort_groups(t_stack *s);
int			check_instruction(char	*ins);
int			check_stack_a_sorted(t_stack *s);
int			is_it_sorted(t_stack *s);
long long	ft_atoi_p(const char *str);
int			ft_strcmp_p(char *s1, char *s2);
void		*ft_calloc_p(size_t count, size_t size);
void		swap_a(t_stack *s, int flag);
void		swap_b(t_stack *s, int flag);
void		sa_and_sb(t_stack *s);
void		push_a(t_stack *s);
void		push_b(t_stack *s);
void		rotate_a(t_stack *s, int flag);
void		rotate_b(t_stack *s, int flag);
void		ra_and_rb(t_stack *s);
void		reverse_rotate_a(t_stack *s, int flag);
void		reverse_rotate_b(t_stack *s, int flag);
void		rra_and_rrb(t_stack *s);
void		swap_a_bonus(t_stack *s);
void		swap_b_bonus(t_stack *s);
void		sa_and_sb_bonus(t_stack *s);
void		push_a_bonus(t_stack *s);
void		push_b_bonus(t_stack *s);
void		rotate_a_bonus(t_stack *s);
void		rotate_b_bonus(t_stack *s);
void		ra_and_rb_bonus(t_stack *s);
void		reverse_rotate_a_bonus(t_stack *s);
void		reverse_rotate_b_bonus(t_stack *s);
void		rra_and_rrb_bonus(t_stack *s);
void		hard_coding(t_stack *s);
void		element_two(t_stack *s);
void		element_three(t_stack *s);
void		third_first_second(t_stack *s);
void		third_second_first(t_stack *s);
void		first_third_second(t_stack *s);
void		second_first_third(t_stack *s);
void		second_third_first(t_stack *s);
void		element_four(t_stack *s);
void		element_five(t_stack *s);
void		send_max_to_stack_b(t_stack *s);

#endif
