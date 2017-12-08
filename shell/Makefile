CC = gcc
CFLAGS = -I.
DEPS = MyToc.h shellExecution.h EnvpOps.h
OBJ = MyToc.o shellExecution.o EnvpOps.o shell.o

%.o: %.c $(DEPS)
	$(CC) -g -c -o $@ $< $(CFLAGS)
	
shell: $(OBJ)
	gcc -g -o $@ $^ $(CFLAGS)
	
test: $(OBJ)
	gcc -g -o $@ $^ $(CFLAGS)
	
clean:
	rm -f *.o shell

