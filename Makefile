CC = cc 
CFLAGS = -Wall -Wextra -Werror 
INCLUDES = printf.h

NAME = libftprintf.a

CFILES = helpers/ft_putchar.c  helpers/ft_putnbr.c \
			helpers/ft_putnbr_u.c  helpers/ft_putstr.c \
			helpers/ft_puthexa.c helpers/ft_puthexa_nb.c \
			helpers/ft_strlen.c ft_printf.c

OFILES = $(CFILES:.c=.o)

all : $(NAME)

%.o : %.c  $(INCLUDES)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OFILES)
	ar rcs $(NAME) $(OFILES)

clean :
	rm -f $(OFILES) $(BOFILES)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY: clean