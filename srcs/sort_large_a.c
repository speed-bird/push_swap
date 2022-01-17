/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobert <jrobert@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 18:01:39 by jrobert           #+#    #+#             */
/*   Updated: 2021/07/08 10:39:38 by jrobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	_best_move(t_list *stack_a, t_list *stack_b, int f_val, int b_val)
{
	int	ff;
	int	fb;
	int	bf;
	int	bb;	

	ff = _val_p(stack_a, f_val);
	if (ff < _slot_hightop_p(stack_b, f_val))
		ff = _slot_hightop_p(stack_b, f_val);
	fb = _val_p(stack_a, f_val) + 0;
	if (ft_lstsize(stack_b) > 1)
		fb = _val_p(stack_a, f_val) + ft_lstsize(stack_b)
			- _slot_hightop_p(stack_b, f_val);
	bf = ft_lstsize(stack_a) - _val_p(stack_a, b_val)
		+ _slot_hightop_p(stack_b, b_val);
	bb = ft_lstsize(stack_a) - _val_p(stack_a, b_val);
	if (bb < ft_lstsize(stack_b) - _slot_hightop_p(stack_b, f_val))
		bb = ft_lstsize(stack_b) - _slot_hightop_p(stack_b, f_val);
	if ((!stack_b && ff < bb) || (ff <= fb && ff <= bf && ff <= bb))
		return (1);
	if ((!stack_b && bb < ff) || (bb <= ff && bb <= fb && bb <= bf))
		return (4);
	else if (fb <= ff && fb <= bf && fb <= bb)
		return (2);
	else
		return (3);
}

void	_rotate_send(t_list **stack_a, t_list **stack_b, int f_val, int b_val)
{
	if (_best_move(*stack_a, *stack_b, f_val, b_val) == 1)
	{
		while ((*stack_a)->content != f_val && _slot_hightop_p(*stack_b, f_val))
			_r_all(stack_a, stack_b);
		while ((*stack_a)->content != f_val)
			_r(stack_a, 'a');
	}
	else if (_best_move(*stack_a, *stack_b, f_val, b_val) == 2)
		while ((*stack_a)->content != f_val)
			_r(stack_a, 'a');
	else if (_best_move(*stack_a, *stack_b, f_val, b_val) == 3)
		while ((*stack_a)->content != b_val)
			_rr(stack_a, 'a');
	else if (_best_move(*stack_a, *stack_b, f_val, b_val) == 4)
	{
		while ((*stack_a)->content != b_val && _slot_hightop_p(*stack_b, b_val))
			_rr_all(stack_a, stack_b);
		while ((*stack_a)->content != b_val)
			_rr(stack_a, 'a');
	}
	if (*stack_b && (*stack_b)->next && (*stack_a)->content == f_val)
		_slot_highttop(stack_b, f_val, 'b');
	else if (*stack_b && (*stack_b)->next && (*stack_a)->content == b_val)
		_slot_highttop(stack_b, b_val, 'b');
	_pb(stack_a, stack_b);
}

void	_sort_into_b(t_list **stack_a, t_list **stack_b, t_list *stack_o)
{
	int	f_val;
	int	b_val;
	int	min;
	int	max;

	_next_layer(&stack_o, &min, &max, ft_lstsize(*stack_a));
	while (*stack_a
		&& (!_is_ordered(*stack_a) || _min(*stack_a) < _max(*stack_b)))
	{
		_simple_fill(stack_a, stack_b);
		_double_fill(stack_a, stack_b);
		if (!*stack_a || (_is_ordered(*stack_a)
				&& _min(*stack_a) > _max(*stack_b)))
			return ;
		if (_front_item_index(*stack_a, &f_val, min, max)
			<= _back_item_index(*stack_a, &b_val, min, max))
			_rotate_send(stack_a, stack_b, f_val, b_val);
		else
			_next_layer(&stack_o, &min, &max, ft_lstsize(*stack_a));
	}
}

void	_sort_large(int size, t_list **stack_a, t_list **stack_b)
{
	t_list	*stack_o;

	if (_seq_len(*stack_a) == size - 1)
		return ;
	else if (_seq_len(*stack_a) * 100 / (size - 1) >= 70)
	{
		_sort_few(size, stack_a, stack_b);
		return ;
	}
	stack_o = _order(size, *stack_a);
	_sort_into_b(stack_a, stack_b, stack_o);
	while (*stack_b)
	{
		_maxtop(stack_b, 'b');
		_lowtop(stack_a, 'a');
		_pa(stack_a, stack_b);
	}
}
