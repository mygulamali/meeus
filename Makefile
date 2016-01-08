CC = clang

SRC_DIR = ${PWD}/src
INCLUDE_DIR = ${PWD}/include
BUILD_DIR = ${PWD}/build
LIB_DIR = ${PWD}/lib

CFLAGS += -O2 -g -Wall -Wextra -Wpedantic -std=c11 -march=native
LDFLAGS += -lm

SOURCES = ${SRC_DIR}/julian_day.c

CMOCKA_DIR = /usr/local/Cellar/cmocka/1.0.1
TEST_DIR = ${PWD}/tests

TEST_CFLAGS = -I${INCLUDE_DIR} -Werror -Wshadow
TEST_LDFLAGS = -L${LIB_DIR} -lmeeus -L${CMOCKA_DIR}/lib -lcmocka

TEST_SOURCES = ${TEST_DIR}/main.c

.SUFFIXES:
.SUFFIXES: .c .o

OBJECTS = ${SOURCES:.c=.o}

TEST_OBJECTS = ${TEST_SOURCES:.c=.o}

all: libmeeus.a

.c.o:
	${CC} -c ${CFLAGS} -I${INCLUDE_DIR} $< -o $@

libmeeus.a: ${OBJECTS}
	mkdir -p ${LIB_DIR}
	${AR} -cq ${LD_FLAGS} ${LIB_DIR}/$@ $^

tests: clean libmeeus.a
	mkdir -p ${BUILD_DIR}
	${CC} ${TEST_SOURCES} ${TEST_CFLAGS} ${TEST_LDFLAGS} -o ${BUILD_DIR}/$@
	${BUILD_DIR}/$@

.PHONY: clean
clean:
	rm -f ${SRC_DIR}/*.o
	rm -f ${LIB_DIR}/libmeeus.a
	rm -f ${BUILD_DIR}/tests

.PHONY: distclean
distclean: clean
	rmdir ${LIB_DIR}
	rmdir ${BUILD_DIR}
