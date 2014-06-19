#
#    * Author: Samuel "MrOverkill" Meyers
#    * License: GPL v3
#    * Version: 0.3.0
#    * Date: 06/18/2014
#

INCLUDE_DIRECTORY=include
FHA_SRC=src/fha.c
MAIN_SRC=src/main.c
FHA_OBJECT=src/fha.o
MAIN_OBJECT=src/main.o
NAME_STATIC=fha-static
NAME_DYNAMIC=fha-dynamic
NAME_EXECUTABLE=fha

default:
	make lib
	make test
	make dynamic

lib:
	gcc -c -I${INCLUDE_DIRECTORY} ${FHA_SRC} -o ${FHA_OBJECT}
	ar -rcs lib${NAME_STATIC}.a ${FHA_OBJECT}

dynamic:
	gcc -c -fPIC -I${INCLUDE_DIRECTORY} ${FHA_SRC} -o ${FHA_OBJECT}
	gcc -shared ${FHA_OBJECT} -o lib${NAME_DYNAMIC}.so

test:
	gcc -c -I${INCLUDE_DIRECTORY} ${MAIN_SRC} -o ${MAIN_OBJECT}
	gcc ${FHA_OBJECT} ${MAIN_OBJECT} -o ${NAME_EXECUTABLE} -L. -l${NAME_STATIC}

clean:
	rm ${MAIN_OBJECT} ${FHA_OBJECT} ${NAME_EXECUTABLE} lib${NAME_STATIC}.a lib${NAME_DYNAMIC}.so
