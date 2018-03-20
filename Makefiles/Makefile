.o.c:
	gcc -c $<
libstaticlib.a: first.o second.o
	ar rcs $@ $^
main: main.c libstaticlib.a
	gcc main.c -o $@ -L. libstaticlib.a
