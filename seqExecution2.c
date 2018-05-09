#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trie.h"
#include "intern.h"

static int
visitor_counter(const char *key, void *data, void *arg)
{
    (void)key;
    (void)data;
    size_t *count = arg;
    count[0]++;
    return 0;
}

int main(int argc, char const *argv[])
{
    FILE *fPtr = NULL;
    FILE *toWrt = NULL;
    fPtr = fopen("sa", "r");
    toWrt = fopen("/Desktop/written.txt", "w+");
    if (fPtr == NULL)
    {
        printf("OKUNACAK DOSYA AÇILAMADI!!\n");
        exit(1);
    }
    // if (toWrt == NULL)
    // {
    //     printf("YAZILACAK DOSYA AÇILAMADI!!\n");
    //     exit(1);
    // }
    char line[100];
    struct intern pool;
    if (intern_init(&pool) != 0)
    {
        fprintf(stderr, "error: intern pool failure\n");
        return -1;
    }

int i=0;
    while ((fscanf(fPtr,"%s", line)) != EOF)
    {
        // printf("%s\n%d\n",line,i++);
        

        if (intern(&pool, line) == NULL)
        {
            printf("error: could not insert '%s'\n", line);
            return 1;
        }
        // fgets(line, 100, fPtr);
    }

    fclose(fPtr);


int count=0;
    visitWrite(pool.trie,"",visitor_counter,&count);


    return 0;
}
