all: mean.o libmath.a

mean.o: mean.c mean.h
	cc -c mean.c 

libmath.a: mean.o
	ar cr libmath.a mean.o 
