APP = tarea6 #Nombre del ejecutable
FUNCS =  #Definicion de metodos de la clase
OBJS =  tarea6.o $(FUNCS)  #Objetos
FLAGS = -ggdb -Wall #Parametros de la compilacion
CC = g++  #Compilador
CFLAGS = $(FLAGS)

ifdef v  #Modificador para compilar con todos los warning
	CFLAGS = $(FLAGS) -Wall -pedantic
endif

all: $(APP)

$(APP): $(OBJS)
	$(CC) $(CFLAGS)   -o $(APP)$(OBJS)

$(OBJS): defs.h $(CLASS)

clean:
	rm -f $(OBJS) $(APP)

.PHONY: clean mrproper denuevo

