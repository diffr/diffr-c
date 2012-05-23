CC=clang
CFLAGS=`pkg-config --cflags glib-2.0`

all: patch

patch: patch.o instruction.o
	$(CC) patch.o instruction.o `pkg-config --libs glib-2.0` -o patch

patch.o: patch.c
	$(CC) $(CFLAGS) -c patch.c

instruction.o: instruction.c
	$(CC) $(CFLAGS) -c instruction.c

clean:
	rm -rf *.o patch
