# ***************************************************************************** #
#                  *#########                                                   #
#                 ##........../##           KWAK!                               #
#               *#,.......,##....#######  /                                     #
#               ##........./....##////##                                        #
#     ##          ##...........,##((##                                          #
#    #.###/        ##,..........*                                               #
#   #(.....(######(###*........,##                                              #
#  ##.............................##      File    : Makefile                     #
#  ##.    __       __  o       __  ##                                           #
#  ##.   |_  |\ | | __ | |\ | |_    *#.   Created : gcollet                     #
#   ##   |__ | \| |__| | | \| |__   ,#,             2022/06/15                  #
#    ##.............................##                                          #
#     /##........................*##      Updated : gcollet                     #
#        ###/................*###.                  2022/06/15                  #
#             ##############.                                                   #
# ***************************************************************************** #

NAME 			=	test

RED				=	\033[31;1m
YELLOW			=	\033[93;1m
GREEN			=	\033[32;1m
BLUE			=	\033[34;1m
END				=	\033[0m

CC 				=	clang++
CFLAGS			=	-Wall -Werror -Wextra -std=c++11 -Isubmodule -IRubberduck

RM				=	rm -rf

SRC_DIR		=	.
OBJ_PATH	=	obj
DIRS		=	$(shell find $(SRC_DIR) -type d)
OBJ_DIRS	=	$(foreach d, $(DIRS), $(addprefix $(OBJ_PATH)/, $(d)))
INCS		=	$(shell find $(SRC_DIR) -type f -name *.hpp)
SRCS		=	$(shell find $(SRC_DIR) -type f -name *.cpp)

OBJ_FILES		= 	$(SRCS:.cpp=.o)
OBJS 			=	$(addprefix $(OBJ_PATH)/, $(OBJ_FILES))

all:	$(NAME)

$(OBJ_PATH)/%.o: %.cpp
	$(CC) $(CFLAGS) -I$(SRC_DIR) -c $< -o $@
	@echo "$(YELLOW) CREATING OBJECTS \n $(END)"

$(NAME):	$(OBJ_PATH) $(OBJS)
	$(CC) -o $(NAME) submodule/glfw/lib-universal/libglfw3.a $(OBJS)
	@echo "$(GREEN) TESTER READY $(END)\n"

$(OBJ_PATH):
	mkdir -p $(OBJ_PATH) $(OBJ_DIRS) $(DIRS)

VPATH = $(SRC_DIR) $(DIRS)

debug:	CFLAGS += -g
debug:	$(NAME)

clean:
	$(RM) $(OBJ_PATH)
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
