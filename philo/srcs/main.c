/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafy <orazafy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 17:30:47 by orazafy           #+#    #+#             */
/*   Updated: 2023/09/03 20:07:35 by orazafy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (ft_fill_data(&data, argc, argv) == -1)
		return (1);
	if (ft_init_mutexes(&data) == -1)
		return (ft_err_msg("Error: Mutexes initialization failed\n"), 1);
	if (philosophers_simulation(&data) == -1)
	{
		ft_free(&data);
		return (ft_err_msg("Error: Simulation processing failed"), 1);
	}	
	ft_free(&data);
	return (0);
}
