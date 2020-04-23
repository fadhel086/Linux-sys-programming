TARGET: exe

exe: evaluation.o diff.o libdll.a
	gcc evaluation.o diff.o -L . -ldll -o exe

libdll.a: dll.o
	ar rs libdll.a dll.o

evaluation.o: evaluation.c
	gcc -c evaluation.c -o evaluation.o

diff.o: diff.c
	gcc -c diff.c -o diff.o

dll.o: dll.c
	gcc -c dll.c -o dll.o


clean:
	rm *.o
	rm *.*~
	rm exe
	rm libdll.a
	
