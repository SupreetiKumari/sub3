CFLAGS = -Wall
CC=g++


		
target1: yourcode.cpp
	$(CC)  ${CFLAGS} -g -I /home/parallels/Desktop/sub3-main/new/include -L /home/parallels/Desktop/sub3-main/new/lib -o yourcode.out yourcode.cpp -L . -laudio -lopenblas -lgfortran

yourcode.o: yourcode.cpp IO.h library.so library.cpp filecheck.h
	$(CC) -c yourcode.cpp

.PHONY: clean

clean:
	rm -f *.o yourcode.out
	
	
