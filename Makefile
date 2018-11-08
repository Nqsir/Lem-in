# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: vsteyaer <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/06/29 17:49:25 by vsteyaer     #+#   ##    ##    #+#        #
#   Updated: 2018/10/23 16:43:24 by fpupier     ###    #+. /#+    ###.fr     # #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = lem-in

FLAGS = -Wall -Wextra -Werror -o2

DIR_SRC = ./srcs/
DIR_ANTHILL = ./srcs/anthill/
DIR_BINARY = ./srcs/binary/
DIR_CLEAR = ./srcs/clear/
DIR_CREATE = ./srcs/create/
DIR_FREE = ./srcs/free/
DIR_UTILS = ./srcs/utils/
DIR_INC = ./includes/
DIR_OBJ = ./objs/
DIR_LIBFT = ./libft/

INC = ./includes/lem_in.h

SRC_FILES =  main.c\

SRC_ANTHILL = checker.c\
              commande.c\
              fourmis.c\
              liaison.c\
              parser.c\
              salle.c

SRC_BINARY =  get_path.c\
              get_path_2.c\
              init_binary_lemin.c\
              match_path.c\
              match_path_2.c\
              start_bin.c\
              write_flags_bin.c

SRC_CLEAR =   clear_anthill.c\
              clear_loop_path.c\
              clear_multi_path.c\
              clear_room.c\
              find_road.c

SRC_CREATE =  create_box.c\
              create_group_path.c\
              create_instruction.c\
              create_link.c\
              create_lst.c\
              create_path.c\
              create_room.c

SRC_FREE =    free_bin.c\
              free_box.c\
              free_group_path.c\
              free_instruction.c\
              free_link.c\
              free_lst.c\
              free_path.c\
              free_room.c\
              last_free.c

SRC_UTILS =   calc.c\
              simplify.c\
              send_ant.c\
              utils_binary.c\
              print.c

SRC = $(addprefix $(DIR_SRC), $(SRC_FILES))\
      $(addprefix $(DIR_ANTHILL), $(SRC_ANTHILL))\
      $(addprefix $(DIR_BINARY), $(SRC_BINARY))\
      $(addprefix $(DIR_CLEAR), $(SRC_CLEAR))\
      $(addprefix $(DIR_CREATE), $(SRC_CREATE))\
      $(addprefix $(DIR_FREE), $(SRC_FREE))\
      $(addprefix $(DIR_UTILS), $(SRC_UTILS))

OBJ = $(addprefix $(DIR_OBJ), $(SRC_FILES:.c=.o))\
      $(addprefix $(DIR_OBJ), $(SRC_ANTHILL:.c=.o))\
      $(addprefix $(DIR_OBJ), $(SRC_BINARY:.c=.o))\
      $(addprefix $(DIR_OBJ), $(SRC_CLEAR:.c=.o))\
      $(addprefix $(DIR_OBJ), $(SRC_CREATE:.c=.o))\
      $(addprefix $(DIR_OBJ), $(SRC_FREE:.c=.o))\
      $(addprefix $(DIR_OBJ), $(SRC_UTILS:.c=.o))

LIBFT = $(addprefix $(DIR_LIBFT), libft.a)
LIB = -L $(DIR_LIBFT) -lft

all : compile $(NAME)

$(NAME) : $(LIBFT) $(DIR_OBJ) $(OBJ)
	@gcc $(OBJ) $(LIB) -o $(NAME)
	@echo "💎  EXECUTABLE LEM-IN CREATED 💎"

compile:
	@make -C $(DIR_LIBFT)

$(DIR_OBJ):
	@printf "Compilation of \033[1m$(NAME)\033[0m ...⌛️  \n"
	@mkdir -p $(DIR_OBJ)


$(DIR_OBJ)%.o: $(DIR_SRC)%.c
	@gcc $(FLAGS) -I $(DIR_LIBFT) -I $(DIR_INC) -o $@ -c $<

$(DIR_OBJ)%.o: $(DIR_ANTHILL)%.c
	@gcc $(FLAGS) -I $(DIR_LIBFT) -I $(DIR_INC) -o $@ -c $<

$(DIR_OBJ)%.o: $(DIR_BINARY)%.c
	@gcc $(FLAGS) -I $(DIR_LIBFT) -I $(DIR_INC) -o $@ -c $<

$(DIR_OBJ)%.o: $(DIR_CLEAR)%.c
	@gcc $(FLAGS) -I $(DIR_LIBFT) -I $(DIR_INC) -o $@ -c $<

$(DIR_OBJ)%.o:$(DIR_CREATE)%.c
	@gcc $(FLAGS) -I $(DIR_LIBFT) -I $(DIR_INC) -o $@ -c $<

$(DIR_OBJ)%.o:$(DIR_FREE)%.c
	@gcc $(FLAGS) -I $(DIR_LIBFT) -I $(DIR_INC) -o $@ -c $<

$(DIR_OBJ)%.o:$(DIR_UTILS)%.c
	@gcc $(FLAGS) -I $(DIR_LIBFT) -I $(DIR_INC) -o $@ -c $<

clean:
	@rm -Rf $(DIR_OBJ)
	@make -C $(DIR_LIBFT) clean
	@echo "❌  OBJS DELETED ❌\n"

fclean: clean
	@rm -f $(NAME)
	@make -C $(DIR_LIBFT) fclean
	@echo "⛔️  EXECUTABLE DELETED ⛔️\n"

re: fclean all

.PHONY: all clean fclean re
