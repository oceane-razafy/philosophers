/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_actions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafy <orazafy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 17:59:33 by orazafy           #+#    #+#             */
/*   Updated: 2023/09/03 19:52:47 by orazafy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_take_forks(t_philo *philo)
{	
	if (ft_check_end_sim(philo) == 1)
		return ;
	pthread_mutex_lock(&philo->data->forks[philo->forks[0]]);
	philo->flags_lock[0] = 1;
	philo->state = STATE_TAKING_A_FORK;
	ft_log_philo_state(philo);
	pthread_mutex_lock(&philo->data->forks[philo->forks[1]]);
	philo->flags_lock[1] = 1;
	philo->state = STATE_TAKING_A_FORK;
	ft_log_philo_state(philo);
}

void	ft_eat(t_philo *philo)
{	
	long long	nb_of_times_to_eat;

	if (ft_check_end_sim(philo) == 1)
		return ;
	pthread_mutex_lock(&philo->data->last_meal_lock);
	philo->last_meal_time = ft_get_current_time();
	pthread_mutex_unlock(&philo->data->last_meal_lock);
	philo->state = STATE_EATING;
	ft_log_philo_state(philo);
	if (ft_check_end_sim(philo) == 1)
		return ;
	ft_timer(ft_get_current_time() - philo->data->start_time, philo);
	philo->nb_meals++;
	pthread_mutex_lock(&philo->data->end_sim_lock);
	nb_of_times_to_eat = philo->data->number_of_times_each_philosopher_must_eat;
	if (philo->nb_meals >= nb_of_times_to_eat
		&& philo->meals_done == 0)
	{
		philo->data->philos_who_finished_his_meals++;
		philo->meals_done = 1;
	}
	pthread_mutex_unlock(&philo->data->end_sim_lock);
}

void	ft_release_forks(t_philo *philo)
{
	if (philo->flags_lock[0] == 1)
		pthread_mutex_unlock(&philo->data->forks[philo->forks[0]]);
	if (philo->flags_lock[1] == 1)
		pthread_mutex_unlock(&philo->data->forks[philo->forks[1]]);
}

void	ft_sleep(t_philo *philo)
{
	if (ft_check_end_sim(philo) == 1)
		return ;
	philo->state = STATE_SLEEPING;
	ft_log_philo_state(philo);
	if (ft_check_end_sim(philo) == 1)
		return ;
	ft_timer(ft_get_current_time() - philo->data->start_time, philo);
}

void	ft_think(t_philo *philo)
{
	if (ft_check_end_sim(philo) == 1)
		return ;
	philo->state = STATE_THINKING;
	ft_log_philo_state(philo);
}
