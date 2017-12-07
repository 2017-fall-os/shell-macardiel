CC = gcc
CFLAGS = -I.
DEPS = MyToc.h shellExecution.h EnvpOps.h
OBJ = MyToc.o shellExecution.o EnvpOps.o shell.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
	
shell: $(OBJ)
	gcc -o $@ $^ $(CFLAGS)
	
test: $(OBJ)
	gcc -o $@ $^ $(CFLAGS)
	
clean:
	rm -f *.o shell

