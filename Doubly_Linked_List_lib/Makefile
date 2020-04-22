TARGET:sample1


sample1: sample_app.o libdll.a
	gcc sample_app.o -L . -ldll -o sample1

sample2: programmable_lib/application.o libdll.a
	gcc programmable_lib/application.o -L . -ldll -o programmable_lib/sample2

programmable_lib/application.o: programmable_lib/application.c
	gcc -c -I lib programmable_lib/application.c -o programmable_lib/application.o
	
sample_app.o:sample_app.c
	gcc -c -I lib sample_app.c -o sample_app.o

libdll.a: dll.o dll_util.o
	ar rs libdll.a dll.o dll_util.o

dll.o: lib/dll.c
	gcc -c -I lib lib/dll.c -o dll.o

dll_util.o: lib/dll_util.c
	gcc -c -I lib lib/dll_util.c -o dll_util.o

clean:
	rm *.o \
	sample1 \
	programmable_lib/sample2 \
	programmable_lib/*.o \
	libdll.a
