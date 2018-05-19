#include "Trie.h"
#include <unistd.h>
int main(int argc, char const *argv[])
{

    clock_t begin = clock();
    // Construct trie
    struct TrieNode *root = getNode();

    FILE *readFile = fopen("./files/data1.txt", "r");
    FILE *writeFile = fopen("outputTask2.txt", "w+");
    char *str = (char *)malloc(1000);
    char line[1000];
    memset(str, '\0', sizeof(char) * 1000); //Windows doesnt do that automotically!

    if (readFile == NULL)
    {
        printf("readfile null");
    }
    if (writeFile == NULL)
    {
        printf("write file null");
    }

    while (1)
    {
        if (fgets(line, 1000, readFile) == NULL)
        {
            break;
        }
        strtok(line, "\n"); // Otherwise it reads \n toooo :(!
        // printf("%s\n", line);
        insert(root, line);
    }



    // printf("sa");

    traverseAndWrite(str, root, writeFile);

    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Time spent: %f sec", time_spent);
    fprintf(writeFile, "%s : %f sec\n", "Time spent: ", time_spent);
    return 0;
}
