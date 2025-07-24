//FormAI DATASET v1.0 Category: File handling ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAXTHREADS 5
#define MAXFILENAMES 10

void *fileHandler(void *filename);

int main()
{
    pthread_t threads[MAXTHREADS];
    char *filenames[MAXFILENAMES] = {"file1.txt", "file2.txt", "file3.txt", "file4.txt", "file5.txt", "file6.txt", "file7.txt", "file8.txt", "file9.txt", "file10.txt"};
    int i;

    for(i = 0; i < MAXTHREADS; i++) {
        pthread_create(&threads[i], NULL, fileHandler, (void *)filenames[i]);
    }

    for(i = 0; i < MAXTHREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}

void *fileHandler(void *filename)
{
    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    fp = fopen(filename, "r");

    if(fp == NULL) {
        printf("Error: Unable to open file: %s\n", (char *)filename);
        pthread_exit(NULL);
    }

    printf("File: %s opened successfully\n", (char *)filename);

    printf("Contents of %s:\n", (char *)filename);

    while((read = getline(&line, &len, fp)) != -1) {
        printf("%s", line);
    }

    printf("\n");

    free(line);
    fclose(fp);
    pthread_exit(NULL);
}