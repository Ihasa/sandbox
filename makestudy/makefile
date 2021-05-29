INCLUDES=\
	-Iinc/foo\
	-Iinc/hoge

CFILES=\
	main.c\
	hoge/*.c\
	foo/*.c\

COBJS=\
	obj/main.o\
	obj/hoge.o\
	obj/foo.o

DEST=bin

#以下はmake暗黙の規則の変数
CC=gcc
CFLAGS=$(INCLUDES)

all:bin/a.exe

bin/a.exe:$(COBJS)
	$(CC) $(COBJS) -o bin/a.exe

obj/main.o:main.c
	$(CC) main.c $(INCLUDES) -c -o obj/main.o

obj/hoge.o:hoge/hoge.c
	$(CC) hoge/hoge.c $(INCLUDES) -c -o obj/hoge.o

obj/foo.o:foo/foo.c
	$(CC) foo/foo.c $(INCLUDES) -c -o obj/foo.o

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
	rm -f -r bin/*
