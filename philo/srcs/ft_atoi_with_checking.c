/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_with_checking.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafy <orazafy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 17:21:12 by orazafy           #+#    #+#             */
/*   Updated: 2023/08/29 19:11:36 by orazafy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_check_zero(char *str)
{
	int	i;

	i = 0;
	while (str[i] == '0')
		i++;
	if (str[i] == 0)
		return (-1);
	else
		return (i);
}

int	ft_count_digits(long long nb)
{
	int	i;

	i = 0;
	while (nb > 0)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

long long	ft_char_to_int(char *str)
{
	long long	nb;
	int			i;
	int			len;

	if (ft_check_zero(str) == -1)
		return (-1);
	else
		str = str + ft_check_zero(str);
	len = ft_strlen(str);
	i = 1;
	nb = str[0] % '0';
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = (nb * 10) + (str[i] % '0');
		i++;
	}
	if (i < len || ft_count_digits(nb) != len)
		return (-1);
	return (nb);
}

long long	ft_atoi(char *str)
{
	long long	result;

	if (*str == 0)
		return (-1);
	if ((*str < '0' || *str > '9') && (*str != '-') && (*str != '+'))
		return (-1);
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			return (-1);
		str++;
		if (*str < '0' || *str > '9')
			return (-1);
	}
	result = ft_char_to_int(str);
	return (result);
}
