#include "Trie.h"
// Driver

int main(int argc, char const *argv[])
{
    char keys[][100] = {"sa", "sa", "as", "salak", "sali"};

    char output[][32] = {"Not present in trie", "Present in trie"};

    struct TrieNode *root = getNode();

    // Construct trie
    int i;
    for (i = 0; i < ARRAY_SIZE(keys); i++)
        insert(root, keys[i]);

    char *str = (char *)malloc(1000);
    memset(str, '\0', sizeof(char) * 1000); //Windows doesnt do that automotically!
    traverse(str, root);

    return 0;
}