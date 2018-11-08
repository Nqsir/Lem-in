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

NAME= libft.a

FLAGS= -Wall -Wextra -Werror

DIR_SRC= ./srcs/
DIR_INC= ./includes/
DIR_OBJ= ./objs/

FILE_SRC_LIBFT=	ft_atoi.c \
		ft_bzero.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isblank.c \
		ft_iscntrl.c \
		ft_isdigit.c \
		ft_isgraph.c \
		ft_islower.c \
		ft_isprint.c \
		ft_isspace.c \
		ft_isupper.c \
		ft_isxdigit.c \
		ft_itoa.c \
		ft_lstadd.c \
		ft_lstcat.c \
		ft_lstdel.c \
		ft_lstdelone.c \
		ft_lstdup.c \
		ft_lstfree.c \
		ft_lstisalnum.c \
		ft_lstisalpha.c \
		ft_lstisdigit.c \
		ft_lstiter.c \
		ft_lstlen.c \
		ft_lstmap.c \
		ft_lstncat.c \
		ft_lstndup.c \
		ft_lstnew.c \
		ft_lstsplit.c \
		ft_memalloc.c \
		ft_memcat.c \
		ft_memccpy.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memdel.c \
		ft_memjoin.c \
		ft_memmove.c \
		ft_memset.c \
		ft_putchar.c \
		ft_putchar_fd.c \
		ft_putendl.c \
		ft_putendl_fd.c \
		ft_putnbr.c \
		ft_putnbr_fd.c \
		ft_putstr.c \
		ft_putstr_fd.c \
		ft_strcat.c \
		ft_strchr.c \
		ft_strclr.c \
		ft_strcmp.c \
		ft_strcpy.c \
		ft_strdel.c \
		ft_strdup.c \
		ft_strequ.c \
		ft_strisalnum.c \
		ft_strisalpha.c \
		ft_strisascii.c \
		ft_strisdigit.c \
		ft_strisdigit_pos_neg.c \
		ft_strislower.c \
		ft_strisprint.c \
		ft_strisspace.c \
		ft_strisupper.c \
		ft_strisxdigit.c \
		ft_striter.c \
		ft_striteri.c \
		ft_strjoin.c \
		ft_strlcat.c \
		ft_strlen.c \
		ft_strmap.c \
		ft_strmapi.c \
		ft_strncat.c \
		ft_strncmp.c \
		ft_strncpy.c \
		ft_strndup.c \
		ft_strnequ.c \
		ft_strnew.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_strsplit.c \
		ft_strstr.c \
		ft_strsub.c \
		ft_strtrim.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_uitoa_base.c \
		ft_realloc.c

FILE_OBJ_LIBFT= $(FILE_SRC_LIBFT:.c=.o)

SRC_LIBFT = $(addprefix $(DIR_SRC), $(FILE_SRC_LIBFT))
OBJ_LIBFT = $(addprefix $(DIR_OBJ), $(FILE_OBJ_LIBFT))

all: $(NAME)

$(NAME):  obj $(DIR_OBJ)

obj:
	@mkdir -p $(DIR_OBJ)

$(DIR_OBJ)%.o:$(DIR_SRC)%.c
	@gcc $(FLAGS) -I $(DIR_INC) -o $@ -c $<

clean:
	@rm -Rf $(DIR_OBJ)

fclean: clean

re: fclean all

.PHONY: all clean fclean re
