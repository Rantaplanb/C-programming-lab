#	Loukas Mertzanis 4457
#	HY255 - Ex03
#	Makefile

CFLAGS = -Wall -ansi -pedantic

clean:
	rm -rf *.o
	rm -rf testsymtab

list: symtablelist.o testsymtab.o
	gcc $(CFLAGS) -o testsymtab testsymtab.o symtablelist.o
	
hash: symtablehash.o testsymtab.o
	gcc $(CFLAGS) -o testsymtab testsymtab.o symtablehash.o
	
symtablehash.o: symtablehash.c symtable.h
	gcc $(CFLAGS) -c symtablehash.c
	
symtablelist.o: symtablelist.c symtable.h 
	gcc $(CFLAGS) -c symtablelist.c
	
testsymtab.o: testsymtab.c symtable.h 
	gcc $(CFLAGS) -c testsymtab.c