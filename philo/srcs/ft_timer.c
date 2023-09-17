/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_timer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafy <orazafy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 13:47:09 by orazafy           #+#    #+#             */
/*   Updated: 2023/09/03 20:19:53 by orazafy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_timer(unsigned long long curr_time, t_philo *philo)
{
	unsigned long long	time_to_wait;
	unsigned long long	limit;

	if (philo->state == STATE_SLEEPING)
		time_to_wait = (unsigned long long)philo->data->time_to_sleep;
	else
		time_to_wait = (unsigned long long)philo->data->time_to_eat;
	limit = curr_time + time_to_wait;
	while (limit > (ft_get_current_time() - philo->data->start_time))
	{
		if (ft_check_end_sim(philo) == 1)
			return ;
		usleep(100);
	}
}
