# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gcollet <gcollet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/07 21:09:53 by gcollet           #+#    #+#              #
#    Updated: 2022/06/15 12:20:11 by gcollet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 			=	test

INC_PATH		=	Rubberduck/
INC_ALL			=	$(patsubst %,-I%,$(INC_PATH))

RED				=	\033[31;1m
YELLOW			=	\033[93;1m
GREEN			=	\033[32;1m
BLUE			=	\033[34;1m
END				=	\033[0m

CC 				=	clang++
CFLAGS			=	

RM				=	rm -rf

SRCS_FILES		=	Sandbox.cpp Rubberduck/src/Application.cpp

OBJS_FILES		= 	$(SRCS_FILES:.cpp=.o)
OBJS 			=	$(addprefix $(OBJS_PATH), $(OBJS_FILES))

$(OBJS_PATH)%.o: %.cpp
	$(CC) $(CFLAGS) $(INC_ALL) -c $< -o $@
	@echo "$(YELLOW) CREATING OBJECTS \n $(END)"

$(NAME):	$(OBJS_PATH) $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(INC_ALL)
	@echo "$(GREEN) TESTER READY $(END)\n"

$(OBJS_PATH):
	mkdir -p $(OBJS_PATH)

VPATH = Sandbox 

all:	$(NAME)

debug:	CFLAGS += -Wall -Werror -Wextra -std=c++11 -g
debug:	$(NAME)

clean:
	$(RM) $(OBJS_FILES) $(OBJS_PATH) 
	echo "$(RED) CLEAN DONE $(END)\\n"

fclean: clean
	$(RM) $(NAME)
	echo "$(RED) FCLEAN DONE $(END)\\n"

re: fclean all

redebug: fclean debug

git: fclean
	git add . 
	@echo "$(GREEN)Enter commit log message:$(END) "
	@read COMMIT; \
	git commit -m "$$COMMIT"
	git push

.PHONY: all clean fclean re debug redebug
