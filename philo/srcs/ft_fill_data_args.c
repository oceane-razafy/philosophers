/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_data_args.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafy <orazafy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 17:20:41 by orazafy           #+#    #+#             */
/*   Updated: 2023/09/03 19:25:20 by orazafy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_fill_data(t_data *data, int argc, char **argv)
{
	if (argc < 5)
		return (ft_err_msg("Error: Too few arguments\n"), -1);
	if (argc > 6)
		return (ft_err_msg("Error: Too many arguments\n"), -1);
	data->nb_of_philos = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->number_of_times_each_philosopher_must_eat = ft_atoi(argv[5]);
	if (ft_check_error_args(data, argc) == -1)
		return (ft_err_msg("Error: Invalid input format\n"), -1);
	if (argc < 6)
		data->number_of_times_each_philosopher_must_eat = -1;
	data->should_sim_stop = 0;
	data->philos_who_finished_his_meals = 0;
	if (ft_fill_data_philos(data) == -1)
		return (-1);
	return (0);
}

int	ft_check_error_args(t_data *data, int argc)
{
	if (data->nb_of_philos <= 0
		|| data->time_to_die <= 0
		|| data->time_to_eat <= 0
		|| data->time_to_sleep <= 0)
		return (-1);
	if (argc == 6)
	{
		if (data->number_of_times_each_philosopher_must_eat <= 0)
			return (-1);
	}
	return (0);
}

void	ft_swap(long long *a, long long *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	ft_fill_data_philos(t_data *data)
{
	long long	i;

	data->philos = (t_philo *)malloc(sizeof(t_philo) * data->nb_of_philos);
	if (data->philos == NULL)
		return (ft_err_msg("Error: Memory allocation failed\n"), -1);
	i = 0;
	while (i < data->nb_of_philos)
	{
		data->philos[i].id = i + 1;
		data->philos[i].forks[0] = i;
		data->philos[i].forks[1] = i + 1;
		if (i == data->nb_of_philos - 1)
			data->philos[i].forks[1] = 0;
		if (i % 2 == 1)
			ft_swap(&data->philos[i].forks[0], &data->philos[i].forks[1]);
		data->philos[i].nb_meals = 0;
		data->philos[i].meals_done = 0;
		i++;
	}
	return (0);
}
