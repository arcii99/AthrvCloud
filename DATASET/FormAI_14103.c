//FormAI DATASET v1.0 Category: Cryptographic hash fucntion ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned long cheerful_hash(const char *str) {
    unsigned long hash = 5381;
    int c;

    while ((c = *str++)) {
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
    }

    return hash;
}

int main(int argc, char *argv[]) {
    char *input;

    printf("Welcome to the Cheerful Hash function!\n");
    printf("Please enter a string to hash: ");

    scanf("%m[^\n]", &input);

    printf("\nYour hash is: %lu\n", cheerful_hash(input));

    free(input);

    return 0;
}