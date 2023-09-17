/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_simulation.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafy <orazafy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 23:05:13 by orazafy           #+#    #+#             */
/*   Updated: 2023/09/03 20:15:47 by orazafy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philosophers_simulation(t_data *data)
{
	int	i;

	data->start_time = ft_get_current_time();
	i = 0;
	if (ft_launch_philo_thread(data, i) == -1)
		return (-1);
	usleep(100);
	i = 1;
	if (ft_launch_philo_thread(data, i) == -1)
		return (-1);
	if (data->nb_of_philos > 1)
	{
		if (pthread_create(&data->check_sim_stop, NULL,
				check_stop_sim, data) != 0)
			return (ft_err_msg("Creation thread failed\n"), ft_free(data), -1);
	}
	return (ft_join_threads(data));
}

int	ft_launch_philo_thread(t_data *data, int i)
{
	while (i < data->nb_of_philos)
	{
		data->philos[i].data = data;
		data->philos[i].last_meal_time = data->start_time;
		if (pthread_create(&data->philos[i].thread, NULL,
				philo_thread, &data->philos[i]) != 0)
			return (ft_err_msg("Creation thread failed\n"), ft_free(data), -1);
		i = i + 2;
	}
	return (0);
}

int	ft_join_threads(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_of_philos)
	{
		if (pthread_join(data->philos[i].thread, NULL))
			return (ft_err_msg("Joining thread failed\n"), ft_free(data), -1);
		i++;
	}
	if (data->nb_of_philos > 1)
	{
		if (pthread_join(data->check_sim_stop, NULL) != 0)
			return (ft_err_msg("Joining thread failed\n"), ft_free(data), -1);
	}
	return (0);
}
