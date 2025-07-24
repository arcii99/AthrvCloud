//FormAI DATASET v1.0 Category: Syntax parsing ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_LEN 1000
#define MAX_THREADS 10

char input[MAX_LEN];
int input_len;

void* parse_c_syntax(void* arg) {
    int* thread_num_ptr = (int*) arg;
    int thread_num = *thread_num_ptr;

    // Create a copy of the input string for this thread to parse
    char input_copy[MAX_LEN];
    strncpy(input_copy, input, input_len);
    input_copy[input_len] = '\0';

    // Parse the C syntax for this thread's portion of the string
    int count = 0;
    char* token = strtok(input_copy, " ");
    while (token != NULL) {
        if (strcmp(token, "int") == 0 || strcmp(token, "float") == 0 || strcmp(token, "char") == 0) {
            count++;
        }
        token = strtok(NULL, " ");
    }

    // Print the thread's count
    printf("Thread %d found %d C syntax variables.\n", thread_num, count);

    // Free the thread num pointer to avoid memory leaks
    free(thread_num_ptr);

    pthread_exit(NULL);
}

int main() {
    // Get user input
    printf("Enter a string to parse C syntax: ");
    fgets(input, MAX_LEN, stdin);
    input_len = strlen(input) - 1;
    if (input[input_len] == '\n') {
        input[input_len] = '\0'; // remove newline character
    }

    // Create array of thread objects
    pthread_t threads[MAX_THREADS];

    // Create threads to parse the input string
    for (int i = 0; i < MAX_THREADS; i++) {
        int* thread_num_ptr = malloc(sizeof(int));
        *thread_num_ptr = i + 1;
        pthread_create(&threads[i], NULL, parse_c_syntax, (void*) thread_num_ptr);
    }

    // Join threads to ensure all parsing is complete before ending program
    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}