# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: orazafy <orazafy@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/29 15:53:45 by orazafy           #+#    #+#              #
#    Updated: 2023/09/04 14:43:04 by orazafy          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra -g
IFLAGS = -I$(INCDIR)
LFLAGS = -pthread

SRCDIR = srcs
OBJDIR = objs
BINDIR = bin
INCDIR = include

SRCS_FILES = ft_all_thread_routines.c \
			ft_atoi_with_checking.c \
			ft_check_end_sim.c \
			ft_dead_condition.c \
			ft_destroy_mutexes.c \
			ft_err_msg.c \
			ft_fill_data_args.c \
			ft_free_data.c \
			ft_get_current_time.c \
			ft_init_mutexes.c \
			ft_log_philo_state.c \
			ft_philo_actions.c \
			ft_timer.c \
			main.c \
			philosophers_simulation.c

SRCS = $(addprefix $(SRCDIR)/, $(SRCS_FILES))
OBJS = $(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

INCS = $(INCDIR)/philo.h

NAME = $(BINDIR)/philo

RMR = rm -rf
MKDIR_P = mkdir -p

all: $(NAME)

$(NAME): $(OBJS) $(MLX) | $(BINDIR)
	$(CC) $(CFLAGS) $(OBJS) $(IFLAGS) $(LFLAGS) -o $(NAME) 

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(INCS) | $(OBJDIR)
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@ 

$(BINDIR):
	$(MKDIR_P) $(BINDIR)

$(OBJDIR):
	$(MKDIR_P) $(OBJDIR)

clean:
		$(RMR) $(OBJDIR)

fclean: clean
		$(RMR) $(BINDIR)

re: fclean all

.PHONY: all clean fclean re