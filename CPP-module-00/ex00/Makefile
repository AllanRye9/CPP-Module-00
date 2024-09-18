# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oallan <oallan@student.42abudhabi.ae>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/18 21:11:54 by oallan            #+#    #+#              #
#    Updated: 2024/09/18 21:12:03 by oallan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Megaphone
SRC = megaphone.cpp
CC = c++ -Wall -Wextra -Werror -std=c++98
all: $(NAME)
$(NAME):
	$(CC) $(SRC) -o $(NAME)
clean:
	rm -f $(NAME)
fclean: clean
re: fclean all
./PHONY : clean fclean re all
