cuitest: cuitest.o split.o
	gcc -o $@ $^ -lreadline

.c.o:
	gcc -c $<

split.o: split.h
array.o: array.h
