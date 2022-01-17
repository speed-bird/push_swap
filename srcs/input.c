/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobert <jrobert@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 18:01:01 by jrobert           #+#    #+#             */
/*   Updated: 2021/07/03 21:20:48 by jrobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	_is_int(char *argv)
{
	long unsigned	val;
	long unsigned	limit;
	int				sign;

	val = 0;
	limit = 2147483647;
	sign = 1;
	if (*argv == '-')
		sign *= -1;
	if (*argv == '-' || *argv == '+')
		argv++;
	while (*argv >= '0' && *argv <= '9' && val < limit)
		val = val * 10 + *argv++ - 48;
	if ((sign > 0 && val > limit) || (sign < 0 && val > limit + 1))
		return (0);
	else
		return (1);
}

int	_is_duplic(int j, char **argv)
{
	int	i;

	i = j;
	while (i-- > 1)
		if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
			return (1);
	return (0);
}

int	_valid_input(int argc, char **argv)
{
	int	i;
	int	j;

	j = 0;
	while (++j < argc)
	{
		i = -1;
		if (!_is_int(argv[j]))
			return (0);
		if (_is_duplic(j, argv))
			return (0);
		while (argv[j][++i])
			if ((!ft_isdigit(argv[j][i])) && (!(argv[j][i] == '-' && i == 0)))
				return (0);
	}
	return (1);
}
