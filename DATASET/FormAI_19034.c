//FormAI DATASET v1.0 Category: File handling ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define BUFFER_SIZE 1024

void* read_file(void* args);
void* write_file(void* args);

int main(int argc, char* argv[]) {
    if (argc < 3) {
        printf("Usage: ./threaded_file_handling <input_file_path> <output_file_path>\n");
        exit(1);
    }

    char* input_file_path = argv[1];
    char* output_file_path = argv[2];

    pthread_t threads[2];
    int thread_ids[2] = {0, 1};

    pthread_create(&threads[0], NULL, read_file, (void*) input_file_path);
    pthread_create(&threads[1], NULL, write_file, (void*) output_file_path);

    for (int i = 0; i < 2; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}

void* read_file(void* args) {
    char* file_path = (char*) args;
    FILE* fp = fopen(file_path, "r");

    if (fp == NULL) {
        printf("Failed to open file.\n");
        pthread_exit(NULL);
    }

    char buffer[BUFFER_SIZE];
    while (fgets(buffer, BUFFER_SIZE, fp)) {
        printf("%s", buffer);
    }

    fclose(fp);
    pthread_exit(NULL);
}

void* write_file(void* args) {
    char* file_path = (char*) args;
    FILE* fp = fopen(file_path, "w");

    if (fp == NULL) {
        printf("Failed to open file.\n");
        pthread_exit(NULL);
    }

    char buffer[BUFFER_SIZE];
    fgets(buffer, BUFFER_SIZE, stdin);
    fputs(buffer, fp);

    fclose(fp);
    pthread_exit(NULL);
}