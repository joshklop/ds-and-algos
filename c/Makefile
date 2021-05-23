CC = gcc

CFLAGS = -ggdb -Wall

list: linked-list.c
	${CC} ${CFLAGS} linked-list.c -o list

test-list: test-linked-list.o linked-list.o munit.o
	${CC} ${CFLAGS} test-linked-list.o linked-list.o munit.o -o test-list

munit.o: munit.c
	${CC} ${CFLAGS} -c munit.c

test-linked-list.o: test-linked-list.c
	${CC} ${CFLAGS} -c test-linked-list.c

linked-list.o: linked-list.c
	${CC} ${CFLAGS} -c linked-list.c

clean:
	rm *.o list test-list
