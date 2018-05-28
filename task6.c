#include "Trie.h"
#include <unistd.h>
#include <dirent.h>

int main(int argc, char const *argv[])
{

    clock_t begin = clock();
    // Construct trie
    struct TrieNode *root = getNode();
    DIR *d;

    struct dirent *dir;

    d = opendir("./files");

    FILE *readFile = NULL;
    FILE *writeFile = fopen("./outputs/outputTask6.txt", "w+");
    char *str = (char *)malloc(1000);
    char line[1000];
    memset(str, '\0', sizeof(char) * 1000); //Windows doesnt do that automotically!
    char *strings = malloc(sizeof(char) * 10000000000);

    // if (readFile == NULL)
    // {
    //     printf("read file null");
    // }
    if (writeFile == NULL)
    {
        printf("write file null");
    }

    if (d)

    {

        while ((dir = readdir(d)) != NULL)
        {
            // printf("%s\n", dir->d_name);
            if (!strstr(dir->d_name, "data"))
            {
                continue;
            }
            printf("%s\n", dir->d_name);
            char filename[] = "files/";
            strcat(filename, dir->d_name);
            printf("%s\n", filename);
            readFile = fopen(filename, "r");
            // printf("%s\n", filename);
            int a = 100000;
            while (a > 0)
            {
                if (fgets(line, 1000, readFile) == NULL)
                {
                    break;
                }
                strtok(line, "\n"); // Otherwise it reads \n toooo :(!
                // printf("%s\n", line);
                // insert(root, line);
                strcat(strings, line);
                strings[strlen(strings)] = '\n';
                a--;
            }
        }

        closedir(d);
    }

    // printf("sa");

    char *ch;
    ch = strtok(strings, "\n");
    // insert(root,ch);
    while (ch != NULL)
    {
        insert(root,ch);
        // printf("%s\n", ch);
        ch = strtok(NULL, "\n");
        
    }

    traverseAndWrite(str, root, writeFile);

    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Time spent: %f sec\n", time_spent);
    fprintf(writeFile, "%s : %f sec\n", "Time spent: ", time_spent);
    fclose(writeFile);

    // char line[1000];

    // while (1)
    // {
    //     printf("str gir:");

    //     if (scanf("%s", line) == EOF)
    //     {
    //         break;
    //     }

    //     strcat(strings, line);
    //     strings[strlen(strings)] = '\n';
    // }

    return 0;
}
