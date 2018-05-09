make:
	gcc -c -g trie.c
	gcc -c -g  main.c
	gcc -c -g  intern.c
	gcc -c -g  seqExecution2.c
	gcc -Wall -g -o trie trie.o main.o intern.o -lpthread -lm
	gcc -Wall -g -o task2 seqExecution2.o trie.o intern.o -lpthread -lm