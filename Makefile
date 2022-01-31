# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gucamuze <gucamuze@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/15 02:21:09 by gucamuze          #+#    #+#              #
#    Updated: 2022/01/31 03:50:22 by gucamuze         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


EXEC_NAME		=	push_swap
CC				=	clang -Wall -Wextra -Werror
RM				=	rm -f

SRCS_PATH		=	./srcs/
LIBFT_PATH		=	./libft/
LIBFT			=	./libft/libft.a

INCLUDES		=	./includes/libft.h
					
SRC_FILES		=	${SRCS_PATH}main.c \
					${SRCS_PATH}checks.c \
					${SRCS_PATH}stack_operations.c \
					${SRCS_PATH}sort_operations.c \
					${SRCS_PATH}sort_states_operations.c \
					${SRCS_PATH}sort_utils.c \
					${SRCS_PATH}utils.c \
					${SRCS_PATH}push_swap.c 
SRC_OFILES		= 	$(SRC_FILES:.c=.o)

LIBFT_OFILES		=	$(LIBFT_PATH)ft_memset.o \
					$(LIBFT_PATH)ft_bzero.o \
					$(LIBFT_PATH)ft_memcpy.o \
					$(LIBFT_PATH)ft_memccpy.o \
					$(LIBFT_PATH)ft_memmove.o \
					$(LIBFT_PATH)ft_calloc.o \
					$(LIBFT_PATH)ft_atoi.o \
					$(LIBFT_PATH)ft_atol.o \
					$(LIBFT_PATH)ft_atod.o \
					$(LIBFT_PATH)ft_isdigit.o \
					$(LIBFT_PATH)ft_strlen.o \
					$(LIBFT_PATH)ft_strdup.o \
					$(LIBFT_PATH)ft_substr.o \
					$(LIBFT_PATH)ft_strjoin.o \
					$(LIBFT_PATH)ft_strtrim.o \
					$(LIBFT_PATH)ft_split.o \
					$(LIBFT_PATH)ft_strmapi.o \
					$(LIBFT_PATH)ft_putchar_fd.o \
					$(LIBFT_PATH)ft_putstr_fd.o \
					$(LIBFT_PATH)ft_isalpha.o \
					$(LIBFT_PATH)ft_isalnum.o \
					$(LIBFT_PATH)ft_isascii.o \
					$(LIBFT_PATH)ft_isprint.o \
					$(LIBFT_PATH)ft_itoa.o \
					$(LIBFT_PATH)ft_memchr.o \
					$(LIBFT_PATH)ft_memcmp.o \
					$(LIBFT_PATH)ft_tolower.o \
					$(LIBFT_PATH)ft_toupper.o \
					$(LIBFT_PATH)ft_strchr.o \
					$(LIBFT_PATH)ft_strrchr.o \
					$(LIBFT_PATH)ft_strncmp.o \
					$(LIBFT_PATH)ft_strnstr.o \
					$(LIBFT_PATH)ft_strlcpy.o \
					$(LIBFT_PATH)ft_strlcat.o \
					$(LIBFT_PATH)ft_putendl_fd.o \
					$(LIBFT_PATH)ft_putnbr_fd.o \
					$(LIBFT_PATH)ft_lstnew.o \
					$(LIBFT_PATH)ft_lstadd_front.o \
					$(LIBFT_PATH)ft_lstsize.o \
					$(LIBFT_PATH)ft_lstlast.o \
					$(LIBFT_PATH)ft_lstadd_back.o \
					$(LIBFT_PATH)ft_lstdelone.o \
					$(LIBFT_PATH)ft_lstclear.o \
					$(LIBFT_PATH)ft_lstiter.o \
					$(LIBFT_PATH)ft_lstmap.o

%.o: %.c
				$(CC) -Iincludes -Ilibft -c $< -o $@

all:			$(EXEC_NAME)

$(EXEC_NAME):	$(LIBFT) $(SRC_OFILES)
				$(CC) $(SRC_OFILES) -Iincludes $(LIBFT) -o $(EXEC_NAME)
							
$(LIBFT):		$(LIBFT_OFILES)
				make --directory=libft

clean:
				make clean --directory=libft
				$(RM) $(SRC_OFILES)

fclean:		clean
				$(RM) $(LIBFT) ${EXEC_NAME}

re:			fclean all

norminette:
			norminette srcs libft includes			

.PHONY:	all clean fclean re norminette

