NAME = megaphone
CXX = c++
FLAGS = -Wall -Wextra -Werror -std=c++98
SCRS = Megaphone.cpp
OBJS = $(SCRS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(FLAGS) -o $(NAME) $(OBJS)

%.o: %.cpp
	$(CXX) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
