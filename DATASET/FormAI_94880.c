//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned long hash(const char *str);

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Please enter a string to hash as an argument.\n");
        exit(1);
    }

    unsigned long hashed_value = hash(argv[1]);

    printf("Hashed value is: %lu\n", hashed_value);

    return 0;
}

unsigned long hash(const char *str) {
    unsigned long hash_val = 5381;

    for(int i=0; i<strlen(str); i++)
        hash_val = ((hash_val << 5) + hash_val) + str[i];

    return hash_val;
}