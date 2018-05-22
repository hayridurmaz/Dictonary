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
    FILE *writeFile = fopen("./outputs/outputTask3.txt", "w+");
    char *str = (char *)malloc(1000);
    char line[1000];
    memset(str, '\0', sizeof(char) * 1000); //Windows doesnt do that automotically!

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
            int a = 40000;
            while (a > 0)
            {
                char arr[10][1000];
                for (int i = 0; i < 10; i++)
                {
                    if (fgets(arr[i], 1000, readFile) == NULL)
                    {
                        break;
                    }
                    strtok(arr[i], "\n"); // Otherwise it reads \n toooo :(!
                }

                // printf("%s\n", line);
                for (int i = 0; i < 10; i++)
                {
                    // printf("%s\n",arr[i]);
                    insert(root, arr[i]);
                }

                a--;
            }
        }

        closedir(d);
    }

    // printf("sa");

    traverseAndWrite(str, root, writeFile);

    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Time spent: %f sec\n", time_spent);
    fprintf(writeFile, "%s : %f sec\n", "Time spent: ", time_spent);
    fclose(writeFile);
    return 0;
}
