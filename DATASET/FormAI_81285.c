//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <pthread.h>

#define MAX_INPUT_LENGTH 100

// struct to store input and sanitized output
typedef struct {
    char input[MAX_INPUT_LENGTH];
    char output[MAX_INPUT_LENGTH];
} InputData;

// function to sanitize input - removes spaces and nonalpha characters
void *sanitizeInput(void *arg) {
    InputData *data = (InputData*) arg;

    int i, j = 0;
    for (i = 0; i < strlen(data->input); i++) {
        if (isalpha(data->input[i])) {
            data->output[j++] = tolower(data->input[i]);
        }
    }
    data->output[j] = '\0';

    pthread_exit(NULL);
}

int main() {
    InputData data;
    pthread_t thread;

    // get input from user
    printf("Enter input: ");
    fgets(data.input, MAX_INPUT_LENGTH, stdin);

    // create thread to sanitize input
    if (pthread_create(&thread, NULL, sanitizeInput, (void*) &data)) {
        fprintf(stderr, "Error creating thread\n");
        return 1;
    }

    // wait for thread to complete
    if (pthread_join(thread, NULL)) {
        fprintf(stderr, "Error joining thread\n");
        return 1;
    }

    // print sanitized output
    printf("Sanitized input: %s\n", data.output);

    return 0;
}