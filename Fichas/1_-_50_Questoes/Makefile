##
# Project 50 Questoes
#
# @file
# @version 0.1

OPT = -flto -Ofast -march=native -mtune=native
CFLAGS = -std=c17 -Wall -Wextra -Wdouble-promotion -Werror=pedantic -Werror=vla -pedantic-errors -Wfatal-errors -g $(OPT)
# CFLAGS = -g
CC = gcc
OBJS = 1_-_50_Questoes.o menu.o
NAME = questoes_50
QUESTOES = 1_-_50_Questoes.c menu.c

all: $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(QUESTOES)

run: all
	./$(NAME)

clean:
	@rm -rf *.o $(NAME)

# end
