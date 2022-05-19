# ThunderLisp - Systems level implementation of Common Lisp
# See LICENSE file for copyright and license details

include config.mk

SRC := $(wildcard src/*.c)
TLIB := $(wildcard src/std/*.c)

all: ${BIN} std clean

${BIN}: ${SRC}
	${CC} ${CFLAGS} -o $@ ${SRC}

std: ${TLIB}
	${CC} ${CFLAGS} -c -fpic ${TLIB}
	${CC} ${CFLAGS} -shared -o libtlisp.so ${TLIB}

install: std ${BIN}
	cp libtlisp.so ${INSTALL}/lib/
	cp ${BIN} ${INSTALL}/bin/${BIN}

.PHONY: clean
clean:
	rm -rf ${BIN} ${wildcard *.o} libtlisp.so
