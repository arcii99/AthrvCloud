//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INIT_HASH 5381
#define PRIME 33

unsigned long hash(char *str) {
    unsigned long h = INIT_HASH;
    while (*str) {
        h = ((h << 5) + h) + (*str++);
    }
    return h;
}

char *hash_to_str(unsigned long h) {
    char *str = malloc(sizeof(char) * 9);
    sprintf(str, "%lx", h);
    return str;
}

int main() {
    char input[256];
    printf("Enter a string to hash: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';

    unsigned long h = hash(input);
    char *hash_str = hash_to_str(h);

    printf("The input string \"%s\" has a hash of %s\n", input, hash_str);

    free(hash_str);
    return 0;
}