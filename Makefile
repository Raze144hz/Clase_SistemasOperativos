###########################################################################
#Pontificia Universidad Javeriana
#Autor: Galindo, David
#Fcihero: atomatizacion de compilacion
###########################################################################

GCC= gcc
FLAGS = -lm
MODULO = modulo

PROGRAMAS = principal

principal:
	 $(GCC) $@.c $(MODULO).c -o $@ $(FLAGS)


clean:
	 $(RM) $(PROGRAMAS) 

