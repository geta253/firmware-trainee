CC = gcc
CFLAGS = -g -Wall

default: Atv1

Atv1:  Atv1.o hAtv1.o
	$(CC) $(CFLAGS) -o Atv1 Atv1.o hAtv1.o

Atv1.o:  Atv1.c hAtv1.h 
	$(CC) $(CFLAGS) -c Atv1.c

hAtv1.o:  hAtv1.c hAtv1.h 
	$(CC) $(CFLAGS) -c hAtv1.c

clean: 
	$(RM) count *.o *~