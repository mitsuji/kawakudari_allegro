all:
	gcc -c ichigojam.c -o out/ichigojam.o
	gcc -c kawakudari.c -o out/kawakudari.o
	gcc -lallegro -lallegro_primitives -o kawakudari out/ichigojam.o out/kawakudari.o

clean:
	rm kawakudari
	rm out/ichigojam.o
	rm out/kawakudari.o
