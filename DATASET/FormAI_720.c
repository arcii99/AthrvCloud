//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: future-proof
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define HASH_SIZE 32

/*
 * The function takes in a string and returns a hash value
 * Using SHA256 Algorithm.
 */

unsigned char* sha256_hash(const char* str)
{
    unsigned char* hash = (unsigned char*)calloc(HASH_SIZE, sizeof(unsigned char));
    char command[1024];

    // Create command to execute SHA256 command.
    sprintf(command, "echo -n \"%s\" | sha256sum | awk '{ print $1 }'", str);

    // Execute the command and get the output string.
    FILE *pipe = popen(command, "r");
    if (pipe != NULL) {
        fread(hash, sizeof(unsigned char), HASH_SIZE, pipe);
        pclose(pipe);
    }

    return hash;
}

int main()
{
    char str[100];
    unsigned char* hash;

    printf("Enter the string to hash: ");
    scanf("%s", str);

    hash = sha256_hash(str);
    printf("The SHA256 hash of the string '%s' is: ", str);

    for (int i = 0; i < HASH_SIZE; i++) {
        printf("%02x", hash[i]);
    }

    free(hash);

    printf("\n");
    return 0;
}