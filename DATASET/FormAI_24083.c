//FormAI DATASET v1.0 Category: Memory management ; Style: minimalist
#include <stdlib.h>
#include <stdio.h>

#define MAX_INPUT_SIZE 100

int main() {
    printf("Enter the number of bytes to allocate: ");
    char input[MAX_INPUT_SIZE];
    fgets(input, MAX_INPUT_SIZE, stdin);

    int bytes = atoi(input);
    printf("Allocating %d bytes...\n", bytes);

    char* buffer = (char*)malloc(bytes);

    if (buffer == NULL) {
        printf("Error: Failed to allocate memory.\n");
        return -1;
    }

    printf("Memory allocated successfully!\n");

    printf("Writing 'Hello, World!' to memory...\n");
    const char* message = "Hello, World!";
    for (int i = 0; i < sizeof(message); i++) {
        buffer[i] = message[i];
    }

    printf("Reading from memory: %s\n", buffer);

    free(buffer);
    printf("Memory freed successfully!\n");

    return 0;
}