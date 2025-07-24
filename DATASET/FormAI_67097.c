//FormAI DATASET v1.0 Category: Cryptographic hash fucntion ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* getHash(char *input) {
    int length = strlen(input);
    char *hash = (char *) malloc(length + 1);
    int i;
    for (i = 0; i < length; i++) {
        hash[i] = input[length - i - 1];
    }
    hash[length] = '\0';

    return hash;
}

int main() {
    char input[100];
    printf("Enter your name: ");
    scanf("%s", input);

    char *hash = getHash(input);
    printf("Your secret hash is: %s\n", hash);

    free(hash);

    return 0;
}