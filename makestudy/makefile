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

CFLAGS4TEST=-ftest-coverage -fprofile-arcs

DEST=bin

#以下はmake暗黙の規則の変数
CC=g++
CFLAGS=$(INCLUDES)
VPATH=\
	foo\
	hoge

all:a.exe

a.exe:$(COBJS) $(EXEMAINOBJ)
	cd obj;$(CC) $^ -o ../bin/$@

.SUFFIXES: .o .c
.c.o:
	$(CC) -c $(CFLAGS) $^ -o obj/$@

.PHONY:test
test:clean test.exe
test.exe:CFLAGS=$(INCLUDES) $(CFLAGS4TEST)
test.exe:$(COBJS) $(TESTMAINOBJ)
	cd obj;$(CC) $^ $(CFLAGS4TEST) -lcunit -o ../test/$@
	./test/test.exe
	lcov -c -d obj -o "test/test.info"
	genhtml -o test/coverage test/test.info

.PHONY:statictest
statictest:CFLAGS4TEST+= -Dstatic=""
statictest:test

.PHONY:test_g
test_g:clean test_g.exe
test_g.exe:CFLAGS=$(INCLUDES) $(CFLAGS4TEST)
test_g.exe:$(COBJS) testmaing.o
	cd obj;$(CC) $^ $(CFLAGS4TEST) -L /usr/local/lib -lgtest -lgtest_main -o ../test/$@
	./test/test_g.exe --gtest_output="xml:./report.xml"
	lcov -c -d obj -o "test/test_g.info"
	lcov -r test/test_g.info */googletest/* */c++/* */usr/local/* -o test/test_g_filtered.info
	genhtml -o test/coverage_g test/test_g_filtered.info

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
