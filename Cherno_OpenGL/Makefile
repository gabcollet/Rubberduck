
PROJECT_NAME	= "Rubberduck Engine"
EXE_NAME		= rubberduck

CC		= clang++
CFLAGS	= -Wextra -Wall -Wshadow -Wconversion -Wpedantic
C_OBJS	= $(CC) $(CFLAGS) $(INCL_FLAGS) $(LIBS) $(FRAME) -c $< -o $@
C_MAIN	= $(CC) $(CFLAGS) $(INCL_FLAGS) $(LIBS) $(FRAME) $(OBJ)  -o $(EXE_NAME)

FRAME	= -framework IOKit -framework OpenGL -framework Appkit -framework Cocoa 

LIBS	= $(DIR_GLFW)/libglfw3.a

INCL			= $(DIR_INC) $(DIR_GLFW)/include
INCL_FLAGS	= $(patsubst %,-I%,$(INCL))


DIR_SRC		= ./src
DIR_OBJ		= ./obj
DIR_INC		= ./include
DIR_DEP		= ./dependency
DIR_GLFW	= $(DIR_DEP)/GLFW

MAIN	= application.cpp

_HEAD	= 	
HEAD	=	$(patsubst %.hpp, $(DIR_INC)/%.hpp, $(_HEAD))

_SRC	= application.cpp
SRC	=	$(patsubst %.cpp, $(DIR_SRC)/%.cpp, $(_SRC))
vpath %.cpp $(DIR_SRC)

_OBJ	= $(_SRC:.cpp=.o)
OBJ	= $(patsubst %.o, $(DIR_OBJ)/%.o, $(_OBJ))

$(DIR_OBJ)/%.o : %.cpp
		$(C_OBJS)

all		: $(EXE_NAME)

$(EXE_NAME)	: $(HEAD) $(SRC) $(DIR_OBJ) $(OBJ) 
		$(C_MAIN)

$(DIR_OBJ)	: 
		@ mkdir $(DIR_OBJ)

clean	:
		@ rm -rf $(DIR_OBJ)

fclean	: clean
		@ rm -f $(NAME)

re		: fclean all

.PHONY	: all clean fclean re
