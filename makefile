all: wordstat

wordstat: wordstat.o node.o
	gcc wordstat.o node.o -o wordstat

wordstat.o: 
	gcc -c -g wordstat.c

node.o: 
	gcc -c -g node.c

clean: 
	rm -rf *o wordstat

