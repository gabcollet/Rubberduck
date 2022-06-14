# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gcollet <gcollet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/07 21:09:53 by gcollet           #+#    #+#              #
#    Updated: 2022/06/14 18:11:00 by gcollet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 			=	test

INC_PATH		=	Rubberduck/

RED				=	\033[31;1m
YELLOW			=	\033[93;1m
GREEN			=	\033[32;1m
BLUE			=	\033[34;1m
END				=	\033[0m

CC 				=	clang++
CFLAGS			=	-Wall -Werror -Wextra

RM				=	rm -rf

SRCS_FILES		=	Application.cpp

OBJS_FILES		= 	$(SRCS_FILES:.cpp=.o)
OBJS 			=	$(addprefix $(OBJS_PATH), $(OBJS_FILES))

$(OBJS_PATH)%.o: %.cpp
	$(CC) $(CFLAGS) -I$(INC_PATH) -c $< -o $@
	@echo "$(YELLOW) CREATING OBJECTS \n $(END)"

$(NAME):	$(OBJS_PATH) $(OBJS)
	$(CC) -o $(NAME) $(OBJS) -I$(INC_PATH)
	@echo "$(GREEN) TESTER READY $(END)\n"

$(OBJS_PATH):
	mkdir -p $(OBJS_PATH)

VPATH = Sandbox 

all:	$(NAME)

debug:	CFLAGS += -g
debug:	$(NAME)

clean:
	$(RM) $(OBJS_FILES) $(OBJS_PATH) 
	echo "$(RED) CLEAN DONE $(END)\\n"

fclean: clean
	$(RM) $(NAME)
	echo "$(RED) FCLEAN DONE $(END)\\n"

re: fclean all

redebug: fclean debug

.PHONY: all clean fclean re debug redebug test
