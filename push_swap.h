/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkasimi <nkasimi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 18:24:01 by nkasimi           #+#    #+#             */
/*   Updated: 2025/02/02 19:46:21 by nkasimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct t_list
{
	int				content;
	int				index;
	int				n_price;
	int				ta_price;
	int				to_price;
	float			rank;
	int				above_m;
	int				best_choice;
	struct t_list	*target;
	struct t_list	*next;
}					t_list;
/*###################################################################
	* ft_printf_functions
###################################################################*/
void				format_specifier(va_list arguements, char specifier,
						int *counter, int fd);
int					ft_printf(int fd, const char *str, ...);
void				ft_putchar(char c, int *counter, int fd);
void				ft_putstr(char *str, int *counter, int fd);
void				ft_putnbr(int n, int *counter, int fd);
/*###################################################################
	* split
###################################################################*/
char				*ft_strdup(const char *s);
char				**ft_split(const char *s, char c);
char				*ft_substr(char const *s, unsigned int start, size_t len);
size_t				ft_strlen(const char *s);
void				*free_sp(char **a);
long				ft_atoi(const char *nptr);
int					ft_strcmp(char *s, char *z);
/*###################################################################
	* linked_list
###################################################################*/
t_list				*ft_lstnew(int content);
void				ft_lstadd_back(t_list **lst, t_list *new);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstclear(t_list **lst);
/*###################################################################
	* instrunctions
###################################################################*/
void				sa(t_list **stack_a);
void				sb(t_list **stack_b);
void				ss(t_list **stack_b, t_list **stack_a);
void				pa(t_list **stack_2, t_list **stack_1);
void				pb(t_list **stack_2, t_list **stack_1);
void				ra(t_list **stack);
void				rb(t_list **stack);
void				rr(t_list **stack_2, t_list **stack_1);
void				rra(t_list **stack);
void				rrb(t_list **stack);
void				rrr(t_list **stack_2, t_list **stack_1);

/*###################################################################
	* stack's f unctions
###################################################################*/
void				put_in_stack(t_list **stack, int number);
t_list				put(t_list **stack, char **av, int number);
void				push_in_stack(t_list **stack_2, t_list **stack_1);
void				swap(t_list **stack);
void				rotate(t_list **stack);
void				reverse_rotate(t_list **stack);
/*###################################################################
	* auther functions
###################################################################*/
t_list				*min_n(t_list **stack);
int					stack_len(t_list *stack);
/*###################################################################
	* ErrorS HUNDLING FUNCTIONS
###################################################################*/
int					str_checker(char **s);
int					error_checker(char **s);
int					sign_checker(char **s);
int					ch_checker(char **s);
int					check_min_max(const char *s, long *number);
int					dup_error(t_list **list);
/*###################################################################
	* hogogo
###################################################################*/
void				fill_the_stack(t_list **list, char **av);
int					sorted(t_list *a);
/*###################################################################
	* put data
###################################################################*/
void				put_data(t_list *b, t_list *a);
void				number_position(t_list *s);
void				get_target(t_list *b, t_list *a);
void				count_price(t_list *b, t_list *a);
t_list				*find_best_price(t_list *a);
void				divide(t_list **a, t_list **b);
/*###################################################################
	* sort functions
###################################################################*/
void				sort_3(t_list **a);
void				sort(t_list **a, t_list **b);
void				return_to_a(t_list **a, t_list **b);
void				sort_min(t_list **a);
/*###################################################################
		bonus part
###################################################################*/
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 13
# endif
/*###################################################################
	get next line
###################################################################*/
char				*ft_strjoin(char const *s1, char const *s2);
int					serch_new_line(char *str);
char				*get_next_line(int fd);
void				apply_instraction(t_list **s1, t_list **s2,
						char *instraction);
/*###################################################################
	double movement for checker
###################################################################*/
void				double_swap(t_list **stack_b, t_list **stack_a);
void				double_re_rotate(t_list **stack_2, t_list **stack_1);
void				double_rotate(t_list **stack_2, t_list **stack_1);

#endif