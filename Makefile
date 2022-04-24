# ThunderLisp - Systems level implementation of Common Lisp
# See LICENSE file for copyright and license details

include config.mk

OBJ = tl.o parse.o std.o gen.o

all: ${BIN}

${BIN}: ${OBJ}
	${CC} ${CFLAGS} -o $@ ${OBJ}

%.o: src/%.c 
	${CC} ${CFLAGS} -c -o $@ $<

install: ${BIN}
	mv ${BIN} ${INSTALL}/${BIN}

.PHONY: clean
clean:
	rm -rf ${BIN} ${OBJ}
