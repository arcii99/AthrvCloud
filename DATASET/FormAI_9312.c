//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void surrealist_hash(char *message)
{
    int i, j, len = strlen(message);
    char hash[len + 1];
    memset(hash, 0, len + 1);

    for (i = 0; i < len; i++) {
        for (j = 0; j < i + 1; j++) {
            hash[j] = message[j] ^ (i + j) << (i % 8);
        }
    }

    printf("Your surrealist hash is: \n");
    for (i = 0; i < len; i++) {
        printf("%02hhx", hash[i]);
    }
    printf("\n");
}

int main()
{
    char message[256];

    printf("Welcome to the Surrealist Hash Function Program!\n\n");
    printf("Please enter the message you wish to hash: ");
    fgets(message, 256, stdin);
    surrealist_hash(message);

    return 0;
}