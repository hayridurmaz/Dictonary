make:
	gcc -c -g Trie.c
	gcc -c -g triedeneme.c
	gcc -c -g task2.c
	gcc -c -g task3.c
	gcc -c -g task4.c
	gcc -c -g task5.c
	gcc -Wall -g -o triedeneme triedeneme.o Trie.o -lpthread -lm
	gcc -Wall -g -o task2 task2.o Trie.o -lpthread -lm
	gcc -Wall -g -o task3 task3.o Trie.o -lpthread -lm
	gcc -Wall -g -o task4 task4.o Trie.o -lpthread -lm
	gcc -Wall -g -o task5 task5.o Trie.o -lpthread -lm