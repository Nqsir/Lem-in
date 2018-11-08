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

NAME = ft_printf.a

FLAGS = -Wall -Wextra -Werror

DIR_SRC= ./srcs/
DIR_INC= ./includes/
DIR_OBJ= ./objs/

FILE_SRC= ft_b.c \
		ft_c.c \
		ft_color.c \
		ft_conversion.c \
		ft_d_i.c \
		ft_gestion.c \
		ft_lx.c \
		ft_n.c \
		ft_o.c \
		ft_p.c \
		ft_pourcent.c \
		ft_printf.c \
		ft_read_format.c \
		ft_read_params.c \
		ft_s.c \
		ft_switch.c \
		ft_u.c \
		ft_wchar.c \
		ft_x.c

FILE_OBJ= $(FILE_SRC:.c=.o)

SRC= $(addprefix $(DIR_SRC), $(FILE_SRC))
OBJ= $(addprefix $(DIR_OBJ), $(FILE_OBJ))

all: obj $(NAME)

obj:
	@mkdir -p $(DIR_OBJ)

$(DIR_OBJ)%.o:$(DIR_SRC)%.c 
	@gcc $(FLAGS) -I $(DIR_INC) -I ../libft/includes -o $@ -c $<

$(NAME): $(OBJ)

clean:
	@rm -Rf $(DIR_OBJ)

fclean: clean

re: fclean all

.PHONY: all clean fclean re
