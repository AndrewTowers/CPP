NAME: phonebook
CXX: clang++
FLAGS:  -Wall -Wextra -Werror -std=c++98
SRCS: phonebook.cpp
OBJS: $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(CXX) $(FLAGS) -o $(NAME) $(OBJS)

$(OBJS): %.o: %.cpp
    $(CXX) $(FLAGS) -c $< -o $@

clean:
    rm -f $(OBJS)

fclean: clean
    rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re