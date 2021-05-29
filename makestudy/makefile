INCLUDES=\
	-Iinc/foo\
	-Iinc/hoge

CFILES=\
	main.c\
	hoge/*.c\
	foo/*.c\

COBJS=\
	main.o\
	hoge.o\
	foo.o

DEST=bin

CC=gcc

CFLAGS=$(INCLUDES)

all:objfile
	cd ./obj;$(CC) $(COBJS) -o ../bin/a.exe

objfile:
	#-cつけないと他のファイルで定義しているような関数が見つけられない
	#またはmain関数がないという理由でエラーになる
	#$(CC) main.c $(INCLUDES)   -o main.o
	#$(CC) hoge/hoge.c $(INCLUDES)  -o hoge.o
	#$(CC) foo/foo.c $(INCLUDES)  -o foo.o
	$(CC) main.c $(INCLUDES) -c -o obj/main.o
	$(CC) hoge/hoge.c $(INCLUDES) -c -o obj/hoge.o
	$(CC) foo/foo.c $(INCLUDES) -c -o obj/foo.o

clean:
	rm -f -r obj/*.o
	rm -f -r bin/*
