#compilation parametres/flags
CFLAGS = -Wall -ansi -pedantic

all: data3 data6 data9

data3: 
	gcc $(CFLAGS) createdata3.c -o createdata3
	./createdata3
	
data6:
	gcc $(CFLAGS) createdata6.c -o createdata6
	./createdata6	
	
data9:
	gcc $(CFLAGS) createdata9.c -o createdata9
	./createdata9
	
clean:
	rm -rf createdata3 createdata6 createdata9 
	rm -rf data3 data6 data9