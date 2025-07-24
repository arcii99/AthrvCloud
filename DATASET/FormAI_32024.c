//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Define your unique cryptographic hash function here
char* my_hash(char* input) {
    int len = strlen(input);
    int sum = 0;
    for(int i = 0; i < len; i++) {
        sum += pow(input[i], i+1);
    }
    char* hash = (char*) malloc(64 * sizeof(char));
    sprintf(hash, "%X", sum);
    return hash;
}

int main() {
    char* input = "my message to hash";
    char* hash = my_hash(input);
    printf("Input message: %s\n", input);
    printf("Hashed output: %s\n", hash);
    free(hash);
    return 0;
}