#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trie.h"
#include "intern.h"

int main(int argc, char **argv)
{
    struct intern pool;
    if (intern_init(&pool) != 0)
    {
        fprintf(stderr, "error: intern pool failure\n");
        return -1;
    }
    char line[128];
    printf("Enter line:");
    while (fgets(line, sizeof(line), stdin))
    {
        line[strlen(line) - 1] = '\0';
        if (intern(&pool, line) == NULL)
        {
            printf("error: could not insert '%s'\n", line);
            return 1;
        }
        printf("Enter line:");
    }

    printf("\nEnter to search:");
    char search[100];
    scanf("%s", search);

    printf("'%s' freq: %d\n", (char *)intern_soft(&pool, search), trie_searchFreq(pool.trie, search));
}
