//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_INPUT_SIZE 100

void *sanitize_input(void *vargp);

int main() {
    char input[MAX_INPUT_SIZE];

    printf("Please enter your input: ");
    fgets(input, MAX_INPUT_SIZE, stdin);

    // create thread to sanitize input
    pthread_t input_thread;
    pthread_create(&input_thread, NULL, sanitize_input, input);

    // wait for thread to complete
    pthread_join(input_thread, NULL);

    printf("Sanitized input: %s", input);

    return 0;
}

void *sanitize_input(void *vargp) {
    char *input = (char *) vargp;

    // loop through input and replace any non-alphanumeric characters with spaces
    for (int i = 0; input[i] != '\0'; i++) {
        if (!isalnum(input[i])) {
            input[i] = ' ';
        }
    }

    return NULL;
}