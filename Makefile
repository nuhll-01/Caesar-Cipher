main: main.c caesar.c
	gcc -Wall -Wextra -std=c99 -o main main.c caesar.c

clean:
	rm -f main