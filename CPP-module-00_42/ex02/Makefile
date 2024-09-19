# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oallan <oallan@student.42abudhabi.ae>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/18 21:15:57 by oallan            #+#    #+#              #
#    Updated: 2024/09/18 21:15:59 by oallan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = account
CC = c++ -Wall -Wextra -Werror -std=c++98
SRC = Account.cpp tests.cpp
$(NAME): $(SRC)
	$(CC) $(SRC) -o $(NAME)
all: $(NAME)
clean: 
	rm -f $(NAME)
fclean: clean
re: fclean all
./PHONY: clean fclean all re
