//FormAI DATASET v1.0 Category: Log analysis ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_LINES 1000
#define MAX_LENGTH 100

char *log_file[MAX_LINES];
int number_of_lines = 0;

void *read_log_file(void *filename) {
    char buffer[MAX_LENGTH];
    char *log_line;

    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Failed to open file %s\n", (char *) filename);
        pthread_exit(NULL);
    }

    while (fgets(buffer, sizeof(buffer), file)) {
        log_line = malloc(strlen(buffer) + 1);
        strcpy(log_line, buffer);
        log_file[number_of_lines++] = log_line;
    }

    fclose(file);
    pthread_exit(NULL);
}

void *parse_log_file(void *arg) {
    int *thread_id = (int *) arg;
    char buffer[MAX_LENGTH];
    char *token;

    for (int i = *thread_id; i < number_of_lines; i += 4) {
        strcpy(buffer, log_file[i]);

        token = strtok(buffer, " ");
        while (token != NULL && strcmp(token, "[ERROR]") != 0) {
            token = strtok(NULL, " ");
        }
        if (token != NULL && strcmp(token, "[ERROR]") == 0) {
            printf("Thread %d: Error found in line %d - %s", *thread_id, i+1, log_file[i]);
        }
    }
    pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
    pthread_t threads[4];
    int thread_args[4] = {0, 1, 2, 3};
    char *filename = argv[1];

    // read log file into memory
    pthread_create(&threads[0], NULL, read_log_file, (void *) filename);
    pthread_join(threads[0], NULL);

    // search for errors in log file using multiple threads
    for (int i = 0; i < 4; i++) {
        pthread_create(&threads[i], NULL, parse_log_file, (void *) &thread_args[i]);
    }

    for (int i = 0; i < 4; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}