scanner: main.c scan.c
	cc -o scanner -g main.c scan.c

parser: expr.c interp.c main.c scan.c tree.c
	cc -o parser -g expr.c interp.c main.c scan.c tree.c

clean:
	rm -f scanner *.o