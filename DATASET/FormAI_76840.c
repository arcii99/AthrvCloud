//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LENGTH 100

void hash(const char *input, char *output) {
    // Initializes variables
    int l = strlen(input);
    unsigned long long int h = 5381;
    int i;

    // Hash function calculation
    for (i = 0; i < l; i++) {
        h = ((h << 5) + h) ^ input[i];
    }
    
    // Formats the output
    snprintf(output, MAX_INPUT_LENGTH + 1, "%016llx", h);
}

int main() {
    // Gets an input string from the user
    char input[MAX_INPUT_LENGTH + 1];
    printf("Please enter a string to hash: ");
    fgets(input, MAX_INPUT_LENGTH + 1, stdin);
    input[strcspn(input, "\n")] = '\0'; // Removes the trailing newline character (if any)

    // Calculates and prints the hash
    char hash_output[MAX_INPUT_LENGTH + 1];
    hash(input, hash_output);
    printf("The hash of \"%s\" is: %s\n", input, hash_output);

    return 0;
}