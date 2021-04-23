
CC=			gcc

AR=			ar

ARFLAGS=	rcs

CFLAGS=		-Wall -Wextra -Werror 

NAME=		libftprintf.a

SRC=		src/ft_printf.c src/ft_parsflags.c src/ft_allocate.c src/ft_apply_bis.c \
			src/ft_apply.c src/ft_num.c src/ft_num_bis.c src/ft_parse.c src/ft_parsflags.c \
			src/ft_printf.c src/ft_utils.c src/ft_utils_bis.c src/ft_string.c src/ft_pointer.c \
			src/ft_parsbonusflags.c src/ft_applybonus.c

OBJ=		$(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
	$(AR) $(ARFLAGS) $(NAME) $(OBJ)

bonus:		$(NAME)

%.o:		%.c
	$(CC) -I ./includes -c $(CFLAGS) -o $@ $<

clean:
	rm -f $(OBJ) $(OBJBONUS)

fclean:		clean
	rm -f $(NAME)

re:			fclean all

.PHONY:	all bonus clean fclean re so
