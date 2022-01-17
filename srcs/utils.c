/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobert <jrobert@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 18:01:59 by jrobert           #+#    #+#             */
/*   Updated: 2021/07/08 10:42:39 by jrobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*_order(int size, t_list *stack)
{
	t_list	*stack_o;
	int		max;

	stack_o = NULL;
	max = _max(stack);
	while (size--)
	{
		ft_lstadd_front(&stack_o, ft_lstnew(max));
		if (size)
			max = _submax(stack, max);
	}
	return (stack_o);
}

int	_is_ordered(t_list *stack)
{
	if (_seq_len(stack) == ft_lstsize(stack) - 1)
		return (1);
	else
		return (0);
}

int	_seq_len(t_list *stack)
{
	int		pos;
	int		seq_len;
	t_list	*tmp;

	tmp = stack;
	seq_len = 0;
	while (tmp)
	{
		pos = 0;
		while (tmp && tmp->next
			&& (tmp->content < tmp->next->content
				|| (tmp->content == _max(stack)
					&& tmp->next->content == _min(stack)))
			&& (tmp->content != _min(stack) || tmp->content == stack->content)
			&& ++pos)
			tmp = tmp->next;
		while (tmp && tmp->next && tmp->content < tmp->next->content
			&& tmp->next->content < stack->content && ++pos)
			tmp = tmp->next;
		if (pos > seq_len)
			seq_len = pos;
		tmp = tmp->next;
	}
	return (seq_len);
}

int	_slot_hightop_p(t_list *stack, int val)
{
	int	pos;

	pos = 0;
	if (ft_lstsize(stack) > 1 && (val > _max(stack) || val < _min(stack)))
	{
		while (stack->content != _max(stack))
		{
			stack = stack->next;
			pos++;
		}
		return (pos);
	}
	while (stack && stack->next
		&& val > stack->content && val > ft_lstlast(stack)->content)
	{
		pos++;
		stack = stack->next;
	}
	while (stack && stack->next && val < stack->content)
	{
		pos++;
		stack = stack->next;
	}
	return (pos);
}

int 	_val_p(t_list *stack, int val)
{
	int	pos;

	pos = 0;
	while (stack && stack->content != val)
	{
		stack = stack->next;
		pos++;
	}
	return (pos);
}
