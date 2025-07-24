//FormAI DATASET v1.0 Category: File handling ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_THREADS 3

void *file_operation(void *arg);

int main() {
    pthread_t threads[MAX_THREADS];
    char files[MAX_THREADS][20] = {"file1.txt", "file2.txt", "file3.txt"};
    int i, rc;

    for (i = 0; i < MAX_THREADS; i++) {
        rc = pthread_create(&threads[i], NULL, file_operation, files[i]);
        if (rc != 0) {
            printf("Error: pthread_create() failed\n");
            exit(EXIT_FAILURE);
        }
    }

    for (i = 0; i < MAX_THREADS; i++) {
        rc = pthread_join(threads[i], NULL);
        if (rc != 0) {
            printf("Error: pthread_join() failed\n");
            exit(EXIT_FAILURE);
        }
    }

    printf("All file operations completed\n");

    exit(EXIT_SUCCESS);
}

void *file_operation(void *arg) {
    char *filename = (char *) arg;
    FILE *file;
    char ch;

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open %s for reading\n", filename);
        pthread_exit(NULL);
    }

    printf("Contents of %s:\n", filename);

    while ((ch = fgetc(file)) != EOF) {
        putchar(ch);
    }

    fclose(file);

    pthread_exit(NULL);
}