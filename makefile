CC = gcc
AR = ar
CFLAGS = -g -Wall
ALL_OBJFILES = isort txtfind txtfind.o isort.o


all : $(ALL_OBJFILES)

isort: isort.o
	$(CC) $(CFLAGS) isort.o -o isort

txtfind: txtfind.o
	$(CC) $(CFLAGS) txtfind.o -o txtfind

isort.o: isort.c isort.h
	$(CC) $(CFLAGS) -c isort.c isort.h -o isort.o

txtfind.o: txtfind.c txtfind.h
	$(CC) $(CFLAGS) -c txtfind.c txtfind.h -o txtfind.o


.PHONY: clean all

clean:
	rm -f *.o $(ALL_OBJFILES)






# $(CONNECTIONS) : my_mat.a main.o
#         $(CC) $(CFLAGS) main.o my_mat.a -o $(CONNECTIONS)

# mymat: my_mat.a

# my_mat.a: my_mat.o
#         $(AR) -rcs my_mat.a my_mat.o

# main.o : $(OBJECTS_MAIN)
#         $(CC) $(CFLAGS) -c main.c

# my_mat.o : $(MY_MAT_OBJECTS)
#         $(CC) $(CFLAGS) -c my_mat.c

