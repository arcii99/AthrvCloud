//FormAI DATASET v1.0 Category: Text processing ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_LINES 10
#define MAX_LENGTH 100

char* text[MAX_LINES];
int num_lines = 0;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void* process_text(void* arg) {
    char* line = (char*) arg;

    // Process text
    int length = strlen(line);
    for (int i = 0; i < length; i++) {
        line[i] = toupper(line[i]);
    }

    // Print processed text
    printf("%s\n", line);

    pthread_exit(NULL);
}

int main() {
    // Read input text
    char line[MAX_LENGTH];
    while (num_lines < MAX_LINES && fgets(line, MAX_LENGTH, stdin) != NULL) {
        text[num_lines++] = strdup(line);
    }

    // Create threads to process text
    pthread_t threads[num_lines];
    for (int i = 0; i < num_lines; i++) {
        pthread_create(&threads[i], NULL, process_text, (void*) text[i]);
    }

    // Wait for threads to finish
    for (int i = 0; i < num_lines; i++) {
        pthread_join(threads[i], NULL);
    }

    // Cleanup
    for (int i = 0; i < num_lines; i++) {
        free(text[i]);
    }

    return 0;
}