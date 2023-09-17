/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dead_condition.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafy <orazafy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 14:24:11 by orazafy           #+#    #+#             */
/*   Updated: 2023/09/03 19:19:11 by orazafy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_dead_condition(t_philo *philo)
{
	unsigned long long	limit;

	pthread_mutex_lock(&philo->data->last_meal_lock);
	limit = philo->last_meal_time + philo->data->time_to_die;
	if (limit < ft_get_current_time())
		return (pthread_mutex_unlock(&philo->data->last_meal_lock), 1);
	return (pthread_mutex_unlock(&philo->data->last_meal_lock), 0);
}
