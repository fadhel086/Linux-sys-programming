TARGET:exe

exe: sample_app.o libdll.a
	gcc sample_app.o -L . -ldll -o exe
	
sample_app.o:sample_app.c
	gcc -c -I $PWD sample_app.c -o sample_app.o

libdll.a: dll.o dll_util.o
	ar rs libdll.a dll.o dll_util.o

dll.o: dll.c
	gcc -c -I $PWD dll.c -o dll.o

dll_util.o:dll_util.c
	gcc -c -I $PWD dll_util.c -o dll_util.o

clean:
	rm *.o \
	exe
