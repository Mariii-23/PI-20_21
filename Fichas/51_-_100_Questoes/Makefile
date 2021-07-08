##
# Project 50 Questoes
#
# @file
# @version 0.1

OPT = -flto -Ofast -march=native -mtune=native
CFLAGS = -std=c99 -Wall -Wextra -Wdouble-promotion $(OPT)
# CFLAGS = -g
CC = gcc
OBJS = 51_-_100_Questoes.o
NAME = questoes_51_and_more
QUESTOES = 51_-_100_Questoes.c

all: $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(QUESTOES)

run: all
	./$(NAME)

clean:
	@rm -rf *.o $(NAME)

# end
