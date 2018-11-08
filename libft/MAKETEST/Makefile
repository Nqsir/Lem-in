# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: fpupier <marvin@le-101.fr>                 +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/03/27 17:13:20 by fpupier      #+#   ##    ##    #+#        #
#   Updated: 2018/10/23 16:30:40 by fpupier     ###    #+. /#+    ###.fr     # #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = libft.a

DIR_LIBFT = ./libft/
DIR_PRINTF = ./ft_printf/
DIR_GNL = ./ft_gnl/
DIR_OBJ_LIBFT = ./libft/objs/
DIR_OBJ_PRINTF = ./ft_printf/objs/
DIR_OBJ_GNL = ./ft_gnl/objs/

all: $(NAME)

$(NAME): $(DIR_OBJ_LIBFT) $(DIR_OBJ_PRINTF) $(DIR_OBJ_GNL)
	@ar rcs $(NAME) $(addprefix $(DIR_LIBFT), objs/*.o) $(addprefix $(DIR_PRINTF), objs/*.o) $(addprefix $(DIR_GNL), objs/*.o)
	@ranlib $(NAME)

$(DIR_OBJ_LIBFT):
	@make -C $(DIR_LIBFT)

$(DIR_OBJ_PRINTF):
	@make -C $(DIR_PRINTF)

$(DIR_OBJ_GNL):
	@make -C $(DIR_GNL)

clean:
	@make -C $(DIR_LIBFT) clean
	@make -C $(DIR_PRINTF) clean
	@make -C $(DIR_GNL) clean

fclean: clean
	@rm -f $(NAME)
	@make -C $(DIR_LIBFT) fclean
	@make -C $(DIR_PRINTF) fclean
	@make -C $(DIR_GNL) fclean

re: fclean all

.PHONY: all clean fclean re

#$(NAME):  $(LIBFT) $(DIR_OBJ) $(OBJ)

#$(DIR_OBJ):
#	@mkdir -p $(DIR_OBJ)

#$(DIR_OBJ)%.o: $(DIR_SRC)%.c
#	@gcc $(FLAGS) -I $(DIR_LIBFT) -I $(DIR_INC) -o $@ -c $<

#$(DIR_OBJ)%.o: $(DIR_ANTHILL)%.c
#	@gcc $(FLAGS) -I $(DIR_LIBFT) -I $(DIR_INC) -o $@ -c $<