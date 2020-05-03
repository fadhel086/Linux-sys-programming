TARGET: exe

exe: serialize.o
	gcc -c serialize.c -o serialize.o

serialize.o: serialize.c
	gcc -c serialize.c -o serialize.o

clean:
	rm *.o
	rm *.*~
	rm Makefile~
