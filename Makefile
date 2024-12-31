# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ilevy <ilevy@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/28 15:15:59 by ilevy             #+#    #+#              #
#    Updated: 2024/12/28 15:38:54 by ilevy            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Program Name
NAME:= philo
NAME_BONUS:= philo_bonus

# Flags and Compiler

CC:= cc
CFLAGS:= -Wall -Wextra -Werror

# Folders

H_FILES:= h_files/
O_FILES:= o_files/
BONUS_O_FILES:= b_o_files/
MANDATORY:= philo/
BONUS:= philo_bonus/

# Files in isolation

OBLIG_FILES:= main.c ft_utils.c
BONUS_FILES:= main.c

# Files relative to Makefile



# Rules:

all:	{NAME}

{NAME}
