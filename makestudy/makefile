INCLUDES=\
	-Iinc/foo\
	-Iinc/hoge

CFILES=\
	main.c\
	hoge/*.c\
	foo/*.c

COBJS=\
	main.o\
	hoge.o\
	foo.o

DEST=bin

#以下はmake暗黙の規則の変数
CC=gcc
CFLAGS=$(INCLUDES)
VPATH=\
	foo\
	hoge

all:a.exe

a.exe:$(COBJS)
	cd obj;$(CC) $^ -o ../bin/$@

.SUFFIXES: .o .c
.c.o:
	$(CC) -c $(INCLUDES) $^ -o obj/$@


.PHONY: clean objfiles

objfiles:
	#-cつけないと他のファイルで定義しているような関数が見つけられない
	#またはmain関数がないという理由でエラーになる
	#$(CC) main.c $(INCLUDES)   -o main.o
	#$(CC) hoge/hoge.c $(INCLUDES)  -o hoge.o
	#$(CC) foo/foo.c $(INCLUDES)  -o foo.o
	
	$(CC) main.c $(INCLUDES) -c -o obj/main.o
	$(CC) hoge/hoge.c $(INCLUDES) -c -o obj/hoge.o
	$(CC) foo/foo.c $(INCLUDES) -c -o obj/foo.o

	#$(CC) foo/foo.c $(INCLUDES) -c -o obj/foo.o

clean:
	rm -f -r obj/*.o
	rm -f *.o
	rm -f -r bin/*
