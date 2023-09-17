/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_end_sim.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafy <orazafy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 13:19:12 by orazafy           #+#    #+#             */
/*   Updated: 2023/09/02 19:34:14 by orazafy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_check_end_sim(t_philo *philo)
{
	if (ft_check_end_sim_2(philo->data) == 1)
		return (1);
	return (0);
}

int	ft_check_end_sim_2(t_data *data)
{
	pthread_mutex_lock(&data->end_sim_lock);
	if (data->should_sim_stop == 1
		|| ft_check_all_philos_ate_enough(data) == 1)
		return (pthread_mutex_unlock(&data->end_sim_lock), 1);
	return (pthread_mutex_unlock(&data->end_sim_lock), 0);
}
