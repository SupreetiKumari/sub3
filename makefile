CFLAGS = -Wall
CC=g++


		
target1: yourcode.cpp
	$(CC)  ${CFLAGS} -g -I $(MKL_BLAS_PATH)/include -L $(MKL_BLAS_PATH)/lib -o yourcode.out yourcode.cpp -L . -laudio -lopenblas -lgfortran

yourcode.o: yourcode.cpp IO.h libaudio.so audio.cpp 
	$(CC) -c yourcode.cpp

.PHONY: clean

clean:
	rm -f *.o yourcode.out
	
