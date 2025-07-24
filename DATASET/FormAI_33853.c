//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Create a custom hash function
unsigned long myHashFunction(const char *str) {
    int n = strlen(str);
    unsigned long hash = 5381;
    for (int i = 0; i < n; i++) {
        hash = ((hash << 5) + hash) + str[i];
    }
    return hash;
}

int main(void) {
    char *input = malloc(100);
    printf("Enter a string to hash: ");
    scanf("%s", input);
    unsigned long hash = myHashFunction(input);
    printf("Hash value: %lu\n", hash);
    free(input);
    return 0;
}