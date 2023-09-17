/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_all_thread_routines.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafy <orazafy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 18:02:24 by orazafy           #+#    #+#             */
/*   Updated: 2023/09/03 19:18:58 by orazafy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo_thread(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->data->nb_of_philos == 1)
		return (ft_only_one_philo(philo), NULL);
	while (ft_check_end_sim(philo) == 0)
	{
		philo->flags_lock[0] = 0;
		philo->flags_lock[1] = 0;
		ft_take_forks(philo);
		ft_eat(philo);
		ft_release_forks(philo);
		ft_sleep(philo);
		ft_think(philo);
		usleep(200);
	}
	return (NULL);
}

void	ft_only_one_philo(t_philo *philo)
{
	printf("%llu %lld has taken a fork\n",
		ft_get_current_time() - philo->data->start_time, philo->id);
	usleep(philo->data->time_to_die * 1000);
	printf("%llu %lld died\n",
		ft_get_current_time() - philo->data->start_time, philo->id);
}

void	*check_stop_sim(void *arg)
{
	t_data	*data;
	int		i;

	data = (t_data *)arg;
	if (data->nb_of_philos == 1)
		return (NULL);
	while (1)
	{
		if (ft_check_end_sim_2(data) == 1)
			return (NULL);
		i = 0;
		while (i < data->nb_of_philos
			&& (ft_check_end_sim_2(data) == 0))
		{
			if (ft_check_dead_philo(&data->philos[i]) == 1)
				return (NULL);
			i++;
		}
		usleep(100);
	}
	return (NULL);
}

int	ft_check_all_philos_ate_enough(t_data *data)
{
	if (data->number_of_times_each_philosopher_must_eat != -1)
	{
		if (data->philos_who_finished_his_meals == data->nb_of_philos)
		{
			data->should_sim_stop = 1;
			return (1);
		}	
	}
	return (0);
}

int	ft_check_dead_philo(t_philo *philo)
{
	if (ft_dead_condition(philo) == 1)
	{
		pthread_mutex_lock(&philo->data->writing_lock);
		if (ft_check_end_sim(philo) == 1)
			return (pthread_mutex_unlock(&philo->data->writing_lock), 1);
		pthread_mutex_lock(&philo->data->end_sim_lock);
		philo->data->should_sim_stop = 1;
		pthread_mutex_unlock(&philo->data->end_sim_lock);
		printf("%llu %lld died\n",
			ft_get_current_time() - philo->data->start_time, philo->id);
		pthread_mutex_unlock(&philo->data->writing_lock);
		return (1);
	}
	return (0);
}
