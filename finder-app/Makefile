#CC ?= $(CROSS_COMPILE)gcc

CC := $(CROSS_COMPILE)gcc

#$(info Using compiler: $(CC))


all: writer writer.o 

writer: writer.o
	$(CC) writer.o -o writer

writer.o: writer.c
	$(CC) -c writer.c -o writer.o

clean:
	rm -f writer.o
	rm -f writer

