INCLUDES=\
	-Iinc/foo\
	-Iinc/hoge\

CFILES=\
	main.c\
	hoge/*.c\
	foo/*.c

COBJS=\
	hoge.o\
	foo.o

EXEMAINOBJ=main.o
TESTMAINOBJ=testmain.o

DEST=bin

#以下はmake暗黙の規則の変数
CC=gcc
CFLAGS=$(INCLUDES)
VPATH=\
	foo\
	hoge

all:a.exe

a.exe:$(COBJS) $(EXEMAINOBJ)
	cd obj;$(CC) $^ -lcunit -o ../bin/$@

.SUFFIXES: .o .c
.c.o:
	$(CC) -c $(CFLAGS) $^ -o obj/$@

test:clean test.exe
test.exe:CFLAGS=$(INCLUDES) -ftest-coverage -fprofile-arcs
test.exe:$(COBJS) $(TESTMAINOBJ)
	cd obj;$(CC) $^ -ftest-coverage -fprofile-arcs -lcunit -o ../test/$@
	./test/test.exe
	lcov -c -d obj -o "test/test.info"
	genhtml -o test/coverage test/test.info

.PHONY: objfiles
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

.PHONY: clean
clean:
	rm -f -r obj/*
	rm -f *.o
	rm -f -r bin/*
	rm -f *.gcda
	rm -f *.gcno
	rm -f *.info
	rm -f -r test/*
