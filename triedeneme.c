#include "Trie.h"
// Driver
int main()
{
    // Input keys (use only 'a' through 'z' and lower case)
    char keys[][100] = {"sa","sa","as","salak","sali"};

    char output[][32] = {"Not present in trie", "Present in trie"};

    struct TrieNode *root = getNode();

    // Construct trie
    int i;
    for (i = 0; i < ARRAY_SIZE(keys); i++)
        insert(root, keys[i]);
    // insert(root, "the");

    // Search for different keys
    // printf("%s --- %s %d\n", "HELLO", output[search(root, "HELLO")], searchCount(root, "HELLO"));
    // printf("%s --- %s %d\n", "ww.com/sa", output[search(root, "ww.com/sa")], searchCount(root, "ww.com/sa"));
    // printf("%s --- %s %d\n", "+++", output[search(root, "+++")], searchCount(root, "+++"));
    // printf("%s --- %s %d\n", "these", output[search(root, "these")], searchCount(root, "these"));
    // printf("%s --- %s\n", "their", output[search(root, "their")]);
    // printf("%s --- %s\n", "thaw", output[search(root, "thaw")]);

    char *str = (char *)malloc(1000);
    traverse(str, root);

    return 0;
}