make:
	gcc -c -g trie.c
	gcc -c -g  main.c
	gcc -c -g  intern.c
	gcc -Wall -g -o trie trie.o main.o intern.o -lpthread -lm