objects = test.o hash.o 
target = test

#main : main.o add.o minus.o
main : $(objects)
	cc -rdynamic -o $(target) $(objects)
test.o : src/test.c
	cc -I header/ -c src/test.c
hash.o : src/hash.c
	cc -I header/ -c src/hash.c
clean : 
	rm $(target) $(objects)
