# Write this Makefile
myas : main.o trans.o check.o
gcc -o myas main.o trans.o check.o
main.o  : myas.h main.c
gcc -c main.c
check.o : myas.h check.c
gcc -c check.c
trans.o : myas.h trans.c
gcc -c trans.c
