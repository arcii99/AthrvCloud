//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: puzzling
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* hash(char* message) {
    int length = strlen(message);
    int i;
    int sum = 0;
    for (i = 0; i < length; i++) {
        sum += message[i];
    }
    char* output = malloc(sizeof(char) * (length + 1));
    for (i = 0; i < length; i++) {
        output[i] = message[i] + sum;
    }
    output[length] = '\0';
    for (i = 0; i < length; i++) {
        output[i] ^= sum;
    }
    return output;
}

int main() {
    char message[100];
    printf("Enter a message to hash:\n");
    fgets(message, 100, stdin);
    char* hashed = hash(message);
    printf("Hashed message: %s", hashed);
    free(hashed);
    return 0;
}