/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destroy_mutexes.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafy <orazafy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 22:40:37 by orazafy           #+#    #+#             */
/*   Updated: 2023/09/03 19:43:18 by orazafy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_destroy_mutexes(t_data *data, long long nb_mutexes)
{
	long long	i;

	if (pthread_mutex_destroy(&data->writing_lock) != 0)
		ft_err_msg("Error: Mutex destruction failed\n");
	if (pthread_mutex_destroy(&data->end_sim_lock) != 0)
		ft_err_msg("Error: Mutex destruction failed\n");
	if (pthread_mutex_destroy(&data->last_meal_lock) != 0)
		ft_err_msg("Error: Mutex destruction failed\n");
	i = 0;
	while (i < nb_mutexes)
	{
		if (pthread_mutex_destroy(&data->forks[i++]) != 0)
			ft_err_msg("Error: Mutex destruction failed\n");
	}
}
