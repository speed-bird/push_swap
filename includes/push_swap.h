/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobert <jrobert@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 14:36:35 by jrobert           #+#    #+#             */
/*   Updated: 2021/07/07 15:57:35 by jrobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "unistd.h"
int		_is_ordered(t_list *stack);
void	_sa(t_list **stack_a);
void	_pa(t_list **stack_a, t_list **stack_b);
void	_pb(t_list **stack_a, t_list **stack_b);
int		_is_int(char *argv);
int		_is_duplic(int j, char **argv);
int		_valid_input(int argc, char **argv);
int		_max(t_list *stack);
int		_submax(t_list *stack, int val);
int		_min(t_list *stack);
void	_fast_rotate(int size, int pos, t_list **stack, char stk);
void	_lowtop(t_list **stack, char stk);
void	_maxtop(t_list **stack, char stk);
void	_slot_highttop(t_list **stack, int val, char stk);
void	_slot_lowtop(t_list **stack, int val, char stk);
void	_solve(t_list **stack_a, t_list **stack_b);
void	_r(t_list **stack, char stk);
void	_r_all(t_list **stack_a, t_list **stack_b);
void	_rr(t_list **stack, char stk);
void	_rr_all(t_list **stack_a, t_list **stack_b);
void	_sort_three(t_list **stack_a);
int		_front_end_few(t_list *stack);
int		_back_end_few(t_list *stack);
void	_sort_few(int size, t_list **stack_a, t_list **stack_b);
int		_best_move(t_list *stack_a, t_list *stack_b, int f_val, int b_val);
void	_rotate_send(t_list **stack_a, t_list **stack_b, int f_val, int b_val);
void	_sort_into_b(t_list **stack_a, t_list **stack_b, t_list *stack_o);
void	_sort_large(int size, t_list **stack_a, t_list **stack_b);
void	_double_fill(t_list **stack_a, t_list **stack_b);
void	_simple_fill(t_list **stack_a, t_list **stack_b);
void	_next_layer(t_list **stack_o, int *min, int *max, int size);
int		_front_item_index(t_list *stack, int *front_val, int min, int max);
int		_back_item_index(t_list *stack, int *back_val, int min, int max);
void	_sort_medium(int size, t_list **stack_a, t_list **stack_b);
t_list	*_order(int size, t_list *stack);
int		_seq_len(t_list *stack);
int		_slot_hightop_p(t_list *stack, int val);
int		_val_p(t_list *stack, int val);

#endif