/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_mutexes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafy <orazafy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 22:51:34 by orazafy           #+#    #+#             */
/*   Updated: 2023/09/03 20:17:29 by orazafy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_init_mutexes(t_data *data)
{
	long long	i;

	if (ft_init_mutexes_utils(data) == -1)
		return (free(data->philos), -1);
	data->forks = malloc(sizeof(pthread_mutex_t) * data->nb_of_philos);
	if (data->forks == NULL)
	{
		ft_err_msg("Error: Memory allocation failed\n");
		return (free(data->philos), ft_destroy_mutexes(data, 0), -1);
	}
	i = 0;
	while (i < data->nb_of_philos)
	{
		if (pthread_mutex_init(&data->forks[i], NULL) != 0)
		{
			free(data->philos);
			free(data->forks);
			break ;
		}
		i++;
	}
	if (i < data->nb_of_philos)
		return (ft_destroy_mutexes(data, i), -1);
	return (0);
}

int	ft_init_mutexes_utils(t_data *data)
{
	if (pthread_mutex_init(&data->writing_lock, NULL) != 0)
		return (-1);
	if (pthread_mutex_init(&data->end_sim_lock, NULL) != 0)
	{
		if (pthread_mutex_destroy(&data->writing_lock) != 0)
			return (ft_err_msg("Error: Mutex destruction failed 1\n"), -1);
		return (-1);
	}
	if (pthread_mutex_init(&data->last_meal_lock, NULL) != 0)
	{
		if (pthread_mutex_destroy(&data->writing_lock) != 0)
			ft_err_msg("Error: Mutex destruction failed 1\n");
		if (pthread_mutex_destroy(&data->end_sim_lock) != 0)
			ft_err_msg("Error: Mutex destruction failed 1\n");
		return (-1);
	}
	return (0);
}
