all: test_lldeque

test_lldeque: lldeque.o test_lldeque.c
	gcc -std=c99 -g test_lldeque.c lldeque.o -o test_lldeque

lldeque.o: lldeque.c lldeque.h
	gcc -std=c99 -g -c lldeque.c

clean:
	rm -f lldeque.o test_lldeque
	rm -rf *.dSYM/
