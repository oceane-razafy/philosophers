/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafy <orazafy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 16:07:30 by orazafy           #+#    #+#             */
/*   Updated: 2023/09/04 14:23:21 by orazafy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <stdio.h>
# include <sys/time.h>

typedef struct s_philo	t_philo;

typedef enum e_philo_state
{
	STATE_TAKING_A_FORK,
	STATE_EATING,
	STATE_SLEEPING,
	STATE_THINKING,
}			t_philo_state;

typedef struct s_data
{
	long long			nb_of_philos;
	long long			time_to_die;
	long long			time_to_eat;
	long long			time_to_sleep;
	long long			number_of_times_each_philosopher_must_eat;
	t_philo				*philos;
	pthread_mutex_t		*forks;
	pthread_mutex_t		writing_lock;
	pthread_mutex_t		end_sim_lock;
	pthread_mutex_t		last_meal_lock;
	int					should_sim_stop;
	long long			philos_who_finished_his_meals;
	unsigned long long	start_time;
	pthread_t			check_sim_stop;
}				t_data;

typedef struct s_philo
{
	long long			id;
	long long			forks[2];
	int					flags_lock[2];
	long long			nb_meals;
	unsigned long long	last_meal_time;
	pthread_t			thread;
	t_data				*data;
	t_philo_state		state;
	int					meals_done;
}				t_philo;

// ft_all_thread_routines.c
void				*philo_thread(void *arg);
void				ft_only_one_philo(t_philo *philo);
void				*check_stop_sim(void *arg);
int					ft_check_all_philos_ate_enough(t_data *data);
int					ft_check_dead_philo(t_philo *philo);

// ft_atoi_with_checking.c
int					ft_strlen(char *str);
int					ft_check_zero(char *str);
int					ft_count_digits(long long nb);
long long			ft_char_to_int(char *str);
long long			ft_atoi(char *str);

// ft_check_end_sim
int					ft_check_end_sim(t_philo *philo);
int					ft_check_end_sim_2(t_data *data);

// ft_dead_condition
int					ft_dead_condition(t_philo *philo);

// ft_destroy_mutextes.c
void				ft_destroy_mutexes(t_data *data, long long nb_mutexes);

// ft_err_msg.c
void				ft_err_msg(char *str);

// fill_data_args.c
int					ft_fill_data(t_data *data, int argc, char **argv);
int					ft_check_error_args(t_data *data, int argc);
void				ft_swap(long long *a, long long *b);
int					ft_fill_data_philos(t_data *data);

// ft_free_data.c
void				ft_free(t_data *data);

// ft_get_current_time.c
unsigned long long	ft_get_current_time(void);

// ft_init_mutexes.c
int					ft_init_mutexes(t_data *data);
int					ft_init_mutexes_utils(t_data *data);

// ft_log_philo_state.c
void				ft_log_philo_state(t_philo *philo);
void				ft_printf_mutex(char *str, t_philo *philo);

// ft_philo_actions.c
void				ft_take_forks(t_philo *philo);
void				ft_eat(t_philo *philo);
void				ft_release_forks(t_philo *philo);
void				ft_sleep(t_philo *philo);
void				ft_think(t_philo *philo);

// ft_timer.c
void				ft_timer(unsigned long long curr_time, t_philo *philo);

// philosophers_simulation.c
int					philosophers_simulation(t_data *data);
int					ft_launch_philo_thread(t_data *data, int i);
int					ft_join_threads(t_data *data);

#endif