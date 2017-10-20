## MAKEFILE OF THE PROJECT
 
CC=gcc
 
CPPFLAGS=  -MMD
CFLAGS= -Wall -Wextra -g -std=c99 -O3
LDFLAGS=
LDLIBS= 

SRC = neuro.c main.c

OBJ= ${SRC:.c=.o}
 
all: main
 
main: ${OBJ}
 
clean:
		rm -f *.o *.d *~
		rm -f main 
-include ${DEP}
 
# END
