## Simple SDL mini code
 
CC=gcc
 
CPPFLAGS=  -MMD
CFLAGS= -Wall -Wextra -g -std=c99 -O3
LDFLAGS=
LDLIBS= 
 
OBJ= neuro.o main.o
DEP= ${SRC:.o=.d}
 
all: main
 
main: ${OBJ}
 
clean:
		${RM} ${OBJ} ${DEP} *~
		${RM} main
 
-include ${DEP}
 
# END
