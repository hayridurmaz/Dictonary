make:
	gcc -c -g Trie.c
	gcc -c -g triedeneme.c
	gcc -Wall -g -o triedeneme triedeneme.o Trie.o -lpthread -lm