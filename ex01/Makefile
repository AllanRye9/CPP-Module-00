NAME = head
CC = c++ -Wall -Wextra -Werror -std=c++98
SRC =	src/Contact.cpp \
		src/main.cpp \
		src/PhoneBook.cpp
$(NAME): $(SRC)
	$(CC) $(SRC) -o $(NAME)
all: $(NAME)
clean: 
	rm -f $(NAME)
fclean: clean
re: fclean all
./PHONY: clean fclean all re