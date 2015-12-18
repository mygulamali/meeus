CC = clang

SRC_DIR = ${PWD}/src
INCLUDE_DIR = ${PWD}/include
LIB_DIR = ${PWD}/lib

CFLAGS += -O2 -g -Wall -Wextra
LDFLAGS += -lm

SOURCES =

.SUFFIXES:
.SUFFIXES: .c .o

OBJECTS = ${SOURCES:.c=.o}

all: meeus.a

.c.o:
	${CC} -c ${CFLAGS} -I${INCLUDE_DIR} ${SRC_DIR}/$<

meeus.a: ${OBJECTS}
	${AR} ${LD_FLAGS} ${LIB_DIR}/$@ ${SRC_DIR}/$^

.PHONY: clean
clean:
	rm ${SRC_DIR}/*.o ${LIB_DIR}/*.a

.PHONY: distclean
distclean: clean
