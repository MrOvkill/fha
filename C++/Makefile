#
#    * Author: Samuel "MrOverkill" Meyers
#    * License: GPL v3
#    * Version: 0.2.0
#    * Date: 06/18/2014
#

INCLUDE_DIRECTORY=include
FHA_SRC=src/fha.cxx
MAIN_SRC=src/main.cxx
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
	g++ -c -I${INCLUDE_DIRECTORY} ${FHA_SRC} -o ${FHA_OBJECT}
	ar -rcs lib${NAME_STATIC}.a ${FHA_OBJECT}

dynamic:
	g++ -c -fPIC -I${INCLUDE_DIRECTORY} ${FHA_SRC} -o ${FHA_OBJECT}
	g++ -shared ${FHA_OBJECT} -o lib${NAME_DYNAMIC}.so

test:
	g++ -c -I${INCLUDE_DIRECTORY} ${MAIN_SRC} -o ${MAIN_OBJECT}
	g++ ${FHA_OBJECT} ${MAIN_OBJECT} -o ${NAME_EXECUTABLE} -L. -l${NAME_STATIC}

clean:
	rm ${MAIN_OBJECT} ${FHA_OBJECT} ${NAME_EXECUTABLE} lib${NAME_STATIC}.a lib${NAME_DYNAMIC}.so
