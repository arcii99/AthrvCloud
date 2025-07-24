//FormAI DATASET v1.0 Category: Syntax parsing ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_THREADS 50

struct thread_data {
    int thread_id;
    char* file_name;
};

void* parse_file(void* arg) {
    struct thread_data* data = (struct thread_data*) arg;
    int id = data->thread_id;
    char* file_name = data->file_name;

    printf("Thread %d is parsing %s\n", id, file_name);

    FILE* file = fopen(file_name, "r");
    if (file == NULL) {
        perror("File error");
        pthread_exit(NULL);
    }

    char current_char, prev_char;
    int line_count = 1, char_count = 0;
    while ((current_char = getc(file)) != EOF) {
        if (current_char == '\n') {
            line_count++;
        }
        else if (current_char == ';') {
            if (prev_char != '"' && prev_char != '\'') {
                char_count++;
            }
        }
        prev_char = current_char;
    }

    printf("Thread %d parsed %d lines and %d semicolons in %s\n", id, line_count, char_count, file_name);
    fclose(file);
    pthread_exit(NULL);
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("USAGE: %s file1 file2 ...\n", argv[0]);
        return 1;
    }

    int num_threads = argc - 1;
    if (num_threads > MAX_THREADS) {
        num_threads = MAX_THREADS;
    }

    pthread_t threads[num_threads];
    struct thread_data thread_data_array[num_threads];

    for (int i = 0; i < num_threads; i++) {
        thread_data_array[i].thread_id = i;
        thread_data_array[i].file_name = argv[i+1];
        pthread_create(&threads[i], NULL, parse_file, (void*) &thread_data_array[i]);
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}