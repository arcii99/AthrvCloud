//FormAI DATASET v1.0 Category: Text processing ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_THREADS 5

typedef struct {
    char* filename;
    char* search_word;
} search_params;

void* search_file(void* args) {
    search_params* sp = (search_params*) args;

    FILE* fp = fopen(sp->filename, "r");
    if (!fp) {
        printf("Unable to open file %s\n", sp->filename);
        pthread_exit(NULL);
    }

    char* line = NULL;
    size_t len = 0;
    ssize_t read;

    while ((read = getline(&line, &len, fp)) != -1) {
        if (strstr(line, sp->search_word) != NULL) {
            printf("%s: %s", sp->filename, line);
        }
    }

    fclose(fp);
    free(line);
    pthread_exit(NULL);
}

int main(int argc, char** argv) {
    if (argc != 3) {
        printf("Usage: %s <search_word> <file1> <file2> ... <fileN>\n", argv[0]);
        return 1;
    }

    char* search_word = argv[1];
    int i, num_files = argc - 2;
    pthread_t threads[num_files > MAX_THREADS ? MAX_THREADS : num_files];
    search_params params[num_files];

    for (i = 0; i < num_files; i++) {
        params[i].filename = argv[i+2];
        params[i].search_word = search_word;

        if (i < MAX_THREADS) {
            pthread_create(&threads[i], NULL, search_file, (void*) &params[i]);
        } else {
            search_file(&params[i]);
        }
    }

    for (i = 0; i < num_files && i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}