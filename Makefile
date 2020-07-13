#Makefile
all: add-nbo

add_nbo: add-nbo.o
	g++ -o add-nbo add-nbo.o

add_nbo.o: add-nbo.cpp

clean:
	rm -f add-nbo
	rm -f *.o