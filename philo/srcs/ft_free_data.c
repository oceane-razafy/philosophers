/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafy <orazafy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 17:58:43 by orazafy           #+#    #+#             */
/*   Updated: 2023/09/02 19:40:41 by orazafy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_free(t_data *data)
{
	ft_destroy_mutexes(data, data->nb_of_philos);
	free(data->philos);
	free(data->forks);
}
