/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_log_philo_state.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafy <orazafy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 18:03:43 by orazafy           #+#    #+#             */
/*   Updated: 2023/09/02 19:41:54 by orazafy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_log_philo_state(t_philo *philo)
{
	if (ft_check_end_sim(philo) == 1)
		return ;
	if (philo->state == STATE_TAKING_A_FORK)
		ft_printf_mutex("%llu %lld has taken a fork\n", philo);
	else if (philo->state == STATE_EATING)
		ft_printf_mutex("%llu %lld is eating\n", philo);
	else if (philo->state == STATE_SLEEPING)
		ft_printf_mutex("%llu %lld is sleeping\n", philo);
	else if (philo->state == STATE_THINKING)
		ft_printf_mutex("%llu %lld is thinking\n", philo);
}

void	ft_printf_mutex(char *str, t_philo *philo)
{
	if (ft_check_end_sim(philo) == 1)
		return ;
	pthread_mutex_lock(&philo->data->writing_lock);
	if (ft_check_end_sim(philo) == 1)
	{
		pthread_mutex_unlock(&philo->data->writing_lock);
		return ;
	}
	printf(str, ft_get_current_time() - philo->data->start_time, philo->id);
	pthread_mutex_unlock(&philo->data->writing_lock);
}
