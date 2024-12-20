credit: credit.c
	gcc -Wall -Wextra -std=c11 -o credit credit.c -lm

clean:
	rm -f credit