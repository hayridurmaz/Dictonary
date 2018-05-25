#include "Trie.h"
// Returns new trie node (initialized to NULLs)
struct TrieNode *getNode(void)
{
    struct TrieNode *pNode = NULL;

    pNode = (struct TrieNode *)malloc(sizeof(struct TrieNode));

    if (pNode)
    {
        int i;

        pNode->isEndOfWord = false;

        for (i = 0; i < ALPHABET_SIZE; i++)
            pNode->children[i] = NULL;
        pNode->count = 0;
    }

    return pNode;
}

// If not present, inserts key into trie
// If the key is prefix of trie node, just marks leaf node
void insert(struct TrieNode *root, const char *key)
{
    int level;
    int length = strlen(key);
    int index;

    struct TrieNode *pCrawl = root;

    for (level = 0; level < length; level++)
    {
        index = CHAR_TO_INDEX(key[level]);
        if (index < ' ' || index > ' ' + ALPHABET_SIZE)
        {
            continue;
        }
        if (!pCrawl->children[index])
            pCrawl->children[index] = getNode();

        pCrawl = pCrawl->children[index];
    }

    // mark last node as leaf
    pCrawl->isEndOfWord = true;
    pCrawl->count++;
}

void insertCounted(struct TrieNode *root, const char *key, int c)
{
    int level;
    int length = strlen(key);
    int index;

    struct TrieNode *pCrawl = root;

    for (level = 0; level < length; level++)
    {
        index = CHAR_TO_INDEX(key[level]);
        if (index < ' ' || index > ' ' + ALPHABET_SIZE)
        {
            continue;
        }
        if (!pCrawl->children[index])
            pCrawl->children[index] = getNode();

        pCrawl = pCrawl->children[index];
    }

    // mark last node as leaf
    pCrawl->isEndOfWord = true;
    pCrawl->count += c;
}

// Returns true if key presents in trie, else false
bool search(struct TrieNode *root, const char *key)
{
    int level;
    int length = strlen(key);
    int index;
    struct TrieNode *pCrawl = root;

    for (level = 0; level < length; level++)
    {
        index = CHAR_TO_INDEX(key[level]);

        if (!pCrawl->children[index])
            return false;

        pCrawl = pCrawl->children[index];
    }

    return (pCrawl != NULL && pCrawl->isEndOfWord);
}
int searchCount(struct TrieNode *root, const char *key)
{
    int level;
    int length = strlen(key);
    int index;
    struct TrieNode *pCrawl = root;

    for (level = 0; level < length; level++)
    {
        index = CHAR_TO_INDEX(key[level]);

        if (!pCrawl->children[index])
            return 0;

        pCrawl = pCrawl->children[index];
    }
    if ((pCrawl != NULL && pCrawl->isEndOfWord))
    {
        return pCrawl->count;
    }
    return 0;
}

void traverse(char *prefix, struct TrieNode *node)
{

    if (node->isEndOfWord)
        printf("%s --- %d\n", prefix, node->count);

    for (char index = 0; index < ALPHABET_SIZE; ++index)
    {
        char next = ' ' + index;
        struct TrieNode *pChild = node->children[index];
        if (pChild)
        {
            // printf("%d",pChild->count);
            prefix[strlen(prefix)] = next;
            prefix[strlen(prefix) + 1] = '\0';
            traverse(prefix, pChild);
            prefix[strlen(prefix) - 1] = '\0';
        }
    }
}

void traverseAndWrite(char *prefix, struct TrieNode *node, FILE *fPtr)
{

    if (node->isEndOfWord)
    {
        // printf("%s --- %d\n", prefix, node->count);
        fprintf(fPtr, "%s : %d\n", prefix, node->count);
    }

    for (char index = 0; index < ALPHABET_SIZE; ++index)
    {
        char next = ' ' + index;
        struct TrieNode *pChild = node->children[index];
        if (pChild)
        {
            prefix[strlen(prefix)] = next;
            prefix[strlen(prefix) + 1] = '\0';
            traverseAndWrite(prefix, pChild, fPtr);
            prefix[strlen(prefix) - 1] = '\0';
        }
    }
}

void trieMerge(struct TrieNode *tries, struct TrieNode *root, char *prefix)
{

    if (root == NULL)
    {
        printf("file is NULL");
    }
    if (tries->isEndOfWord)
    {
        // printf("%s --- %d\n", prefix, node->count);
        // fprintf(fPtr, "%s : %d\n", prefix, node->count);
        // printf("%s :   %d \n", prefix, tries->count);
        insertCounted(root,prefix,tries->count);
        // insert(root, prefix);
    }

    for (char index = 0; index < ALPHABET_SIZE; ++index)
    {
        char next = ' ' + index;
        struct TrieNode *pChild = tries->children[index];
        if (pChild)
        {
            prefix[strlen(prefix)] = next;
            prefix[strlen(prefix) + 1] = '\0';
            trieMerge(pChild, root, prefix);
            prefix[strlen(prefix) - 1] = '\0';
        }
    }
}
