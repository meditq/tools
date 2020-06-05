PROGRAMS = testsplit testarray table readfile

all: $(PROGRAMS)

testsplit: testsplit.o split.o
	gcc -o $@ $^ -lreadline

testarray: testarray.o split.o array.o
	gcc -o $@ $^ -lreadline

table: table.o
	gcc -o $@ $^

readfile: readfile.o array.o
	gcc -o $@ $^

.c.o:
	gcc -c $<

split.o: split.h
array.o: array.h

clean:
	rm $(PROGRAMS) *.o
