make:
	gcc -c -g Trie.c
	gcc -c -g triedeneme.c
	gcc -Wall -g -o triedeneme triedeneme.o Trie.o -lpthread -lm
	gcc -c -g task2.c
	gcc -Wall -g -o task2 task2.o Trie.o -lpthread -lm