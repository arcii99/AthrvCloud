//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: Cyberpunk
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// The Cyberpunk Hash Function

int main(int argc, char *argv[]) {

    char message[100];
    printf("Enter a string to be hashed: ");
    scanf("%s", message);

    int length = strlen(message);
    int hash = 0;

    for (int i = 0; i < length; i++) {
        hash += (((int) message[i] + i) * (length - i)) ^ i;
        hash %= 1000000;  // Limit the hash to 6 digits
    }

    printf("The Cyberpunk Hash of '%s' is: %d\n", message, hash);
    return 0;
}