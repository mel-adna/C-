# **************************************************************************** #
#                                   Makefile                                   #
# **************************************************************************** #

CXX      = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 #-g -fsanitize=address

NAME     = a.out

SRCS     = main.cpp \
           AMateria.cpp \
           Ice.cpp \
           Cure.cpp \
           Character.cpp \
           MateriaSource.cpp

OBJS     = $(SRCS:.cpp=.o)

HEADERS  = AMateria.hpp \
           Ice.hpp \
           Cure.hpp \
           Character.hpp \
           MateriaSource.hpp \
           ICharacter.hpp \
           IMateriaSource.hpp

# ======================= Rules ======================= #

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
