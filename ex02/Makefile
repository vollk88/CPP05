# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hloki <hloki@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/13 17:17:09 by hloki             #+#    #+#              #
#    Updated: 2022/06/12 21:09:51 by hloki            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= bureaucrat

D_GREEN		= \033[32m
L_GREEN		= \033[32m
L_BLUE		= \033[36m
PURPLE		= \033[35m
NC			= \033[0m

CXX 		= c++

FLAGS		= -Wall -Wextra -Werror -std=c++98

HEADER		=	Bureaucrat.hpp \
				Colors.hpp \
				Form.hpp \
				PresidentialPardonForm.hpp \
				RobotomyRequestForm.hpp \
				ShrubberyCreationForm.hpp

SRCS		=	main.cpp \
				Bureaucrat.cpp \
				Form.cpp \
				PresidentialPardonForm.cpp \
				RobotomyRequestForm.cpp \
				ShrubberyCreationForm.cpp

OBJS_DIR 	= objs/

OBJS 		= $(addprefix $(OBJS_DIR), $(SRCS:.cpp=.o))

all: $(NAME)

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

$(OBJS_DIR)%.o: ./%.cpp $(HEADER)
	@$(CXX) $(FLAGS) -c $< -o $@
	@printf "$(L_BLUE)Object %-40.100s [$(D_GREEN)✔$(L_BLUE)]\r" $@

$(NAME): $(OBJS_DIR) $(OBJS) $(SRCS)
	@$(CXX) $(FLAGS) $(OBJS) -o $(NAME)

clean:
	@$(RM) $(OBJS) $(D_FILES)
	@rm -rf $(OBJS_DIR)

fclean: clean
	@$(RM) $(NAME)

re: fclean all