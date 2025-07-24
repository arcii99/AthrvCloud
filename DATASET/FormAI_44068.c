//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Hash function
unsigned int hash(char *str) {
    unsigned int hash = 0;
    unsigned int i;

    for (i = 0; i < strlen(str); ++i) {
        hash += str[i];
        hash += (hash << 10);
        hash ^= (hash >> 6);
    }

    hash += (hash << 3);
    hash ^= (hash >> 11);
    hash += (hash << 15);

    return hash;
}

int main() {
    char *password = "secret_password";
    unsigned int hashed_password = hash(password);

    printf("Password: %s\n", password);
    printf("Hashed Password: %u\n", hashed_password);

    return 0;
}