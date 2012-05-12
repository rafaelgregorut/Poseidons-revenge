# *******************************************************************************

CFLAGS = -g -I. -Wall -pedantic -ansi
LDFLAGS = -L.
LDLIBS = -lm 

RM = /bin/rm -f
CC = gcc

#================================================================================

.c.o:
	$(CC) $(CFLAGS) -c $*.c

.c:
	make $*.o
	$(CC) $(CFLAGS) -o $* $*.o $(LDLIBS) 

#================================================================================

clean:
	$(RM) *~ \#~ .\#* *.o core a.out

#================================================================================

fase1: flecha.o pedra.o barco.o  formulas.o fase1.o
	$(CC) $(CFLAGS) -o fase1 flecha.o pedra.o barco.o formulas.o fase1.o $(LDLIBS) 