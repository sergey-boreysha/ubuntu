
all: 	exe lib

exe: 	main.c hello.h lib
	gcc main.c -fPIC -ldl -o hello	

lib:
	gcc -o libHello.so -shared hello.c

clean:
	-rm hello libHello.so 2>/dev/null
