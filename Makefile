OFILES = administrador.o main.o bodeguero.o vendedor.o

Taller1: ${OFILES}
	gcc -o Taller1 ${OFILES}

administrador.o: administrador.c administrador.h usuarios.h

main.o: main.c administrador.h vendedor.h bodeguero.h usuarios.h data.h

bodeguero.o: bodeguero.h usuarios.h bodeguero.c

vendedor.o: vendedor.c vendedor.h bodeguero.h

clear: 
	rm *.o Taller1