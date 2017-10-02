CC = gcc
CFLAGS = -I.
DEPS = MyToc.h
OBJ = MyToc.o shell.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
	
shell: $(OBJ)
	gcc -o $@ $^ $(CFLAGS)
	
clean:
	rm -f *.o shell

