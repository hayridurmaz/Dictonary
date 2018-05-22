#include "Trie.h"
#include <unistd.h>
#include <dirent.h>
#include <pthread.h>

struct arguments {
    FILE *file;
    struct TrieNode *root;
    pthread_t self;
};

struct TrieNode *root;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
void *threadedRead(void *file)
{
    int a = 400000;
    char line[1000];
    FILE *readFile = (FILE *)file;
    // struct TrieNode *root = (struct TrieNode *)r;
    while (a > 0)
    {
        if (fgets(line, 1000, readFile) == NULL)
        {
            break;
        }
        strtok(line, "\n"); // Otherwise it reads \n toooo :(!
        printf("%s\n", line);
        // printf("%s --- threadID:%d");
        pthread_mutex_lock(&mutex);
        insert(root, line);
        pthread_mutex_unlock(&mutex);
        a--;
    }
    pthread_exit(NULL);
}
int main(int argc, char const *argv[])
{

    clock_t begin = clock();
    // Construct trie
    // root = getNode();
    DIR *d;

    struct dirent *dir;

    d = opendir("./files");

    FILE *readFile = NULL;
    FILE *writeFile = fopen("./outputs/outputTask5.txt", "w+");
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
        pthread_t threads[10];
        struct TrieNode *roots[10];
        
        for(size_t i = 0; i < 10; i++)
        {
            roots[i]=getNode();
        }
        
        int j = 0;
        while ((dir = readdir(d)) != NULL)
        {
            // printf("%s\n", dir->d_name);
            if (!strstr(dir->d_name, "data"))
            {
                continue;
            }
            // printf("%s\n", dir->d_name);
            char filename[] = "files/";
            strcat(filename, dir->d_name);
            printf("%s\n", filename);
            readFile = fopen(filename, "r");
            // printf("%s\n", filename);
            pthread_mutex_lock(&mutex);
            int rc = pthread_create(&threads[j++], NULL, threadedRead, (void *)readFile);
            pthread_mutex_unlock(&mutex);
            if (rc)
            {
                printf("ERROR; return code from pthread_create() is %d\n", rc);
                exit(-1);
            }
        }
        for(int k=0;k<10;k++){
            pthread_join(threads[k], NULL);
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
    pthread_exit(NULL);
    return 0;
}
