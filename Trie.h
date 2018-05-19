// C implementation of search and insert operations
// on Trie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#define ARRAY_SIZE(a) sizeof(a) / sizeof(a[0])

// Alphabet size (# of symbols)
#define ALPHABET_SIZE (93)

// Converts key current character into index
// use only 'a' through 'z' and lower case
#define CHAR_TO_INDEX(c) ((int)c - (int)' ')

// trie node
struct TrieNode
{
    struct TrieNode *children[ALPHABET_SIZE];

    // isEndOfWord is true if the node represents
    // end of a word
    bool isEndOfWord;
    int count;
};

// Returns new trie node (initialized to NULLs)
extern struct TrieNode *getNode(void);

// If not present, inserts key into trie
// If the key is prefix of trie node, just marks leaf node
extern void insert(struct TrieNode *root, const char *key);

// Returns true if key presents in trie, else false
extern bool search(struct TrieNode *root, const char *key);
extern int searchCount(struct TrieNode *root, const char *key);
extern void traverse(char *prefix, struct TrieNode *node);
extern void traverseAndWrite(char *prefix, struct TrieNode *node, FILE *fPtr);