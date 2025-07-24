//FormAI DATASET v1.0 Category: Syntax parsing ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Maximum size of the input
#define MAX_SIZE 1000

// Structure for the input string and index
typedef struct InputBuffer {
    char input[MAX_SIZE];
    int index;
} InputBuffer;

// Function to parse an identifier
void parse_identifier(char* input) {
    printf("Identifier: ");
    int i = 0;
    while ((input[i] >= 'a' && input[i] <= 'z') || (input[i] >= 'A' && input[i] <= 'Z') || (input[i] >= '0' && input[i] <= '9') || input[i] == '_') {
        printf("%c", input[i]);
        i++;
    }
    printf("\n");
}

// Function to parse a number
void parse_number(char* input) {
    printf("Number: ");
    int i = 0;
    while (input[i] >= '0' && input[i] <= '9') {
        printf("%c", input[i]);
        i++;
    }
    printf("\n");
}

// Function to parse a symbol
void parse_symbol(char* input) {
    printf("Symbol: %c\n", input[0]);
}

// Function to parse the input string
void* parse_input(void* arg) {
    InputBuffer* inputBuffer = (InputBuffer*)arg;
    while (inputBuffer->index < MAX_SIZE && inputBuffer->input[inputBuffer->index] != '\0') {
        if ((inputBuffer->input[inputBuffer->index] >= 'a' && inputBuffer->input[inputBuffer->index] <= 'z') || (inputBuffer->input[inputBuffer->index] >= 'A' && inputBuffer->input[inputBuffer->index] <= 'Z') || inputBuffer->input[inputBuffer->index] == '_') {
            parse_identifier(&inputBuffer->input[inputBuffer->index]);
        } else if (inputBuffer->input[inputBuffer->index] >= '0' && inputBuffer->input[inputBuffer->index] <= '9') {
            parse_number(&inputBuffer->input[inputBuffer->index]);
        } else {
            parse_symbol(&inputBuffer->input[inputBuffer->index]);
        }
        inputBuffer->index++;
    }
    return NULL;
}

int main() {
    // Initialize inputBuff
    InputBuffer inputBuffer;
    printf("Enter input: ");
    fgets(inputBuffer.input, MAX_SIZE, stdin);
    inputBuffer.index = 0;

    // Create a thread to parse the input
    pthread_t thread;
    int result = pthread_create(&thread, NULL, parse_input, &inputBuffer);
    if (result != 0) {
        printf("Error starting thread: %d\n", result);
        exit(EXIT_FAILURE);
    }

    // Wait for the thread to complete
    result = pthread_join(thread, NULL);
    if (result != 0) {
        printf("Error joining thread: %d\n", result);
        exit(EXIT_FAILURE);
    }

    return 0;
}