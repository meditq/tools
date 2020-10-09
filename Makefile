PROGRAMS = testarray table readfile duptest sort

all: $(PROGRAMS)

testarray: testarray.o array.o libsplit.a
	gcc -o $@ $^ -lreadline

table: table.o
	gcc -o $@ $^

readfile: readfile.o array.o
	gcc -o $@ $^

duptest: duptest.o array.o
	gcc -o $@ $^

sort: sort.o array.o
	gcc -o $@ $^

.c.o:
	gcc -c $<

array.o: array.h
testarray.o: split.h

clean:
	rm -f $(PROGRAMS) *.o
