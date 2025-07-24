//FormAI DATASET v1.0 Category: Encryption ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024

void cryptize(char* buffer, int key) {
    int i;

    for (i = 0; buffer[i] != '\0'; i++) {
        buffer[i] += key;

        if (buffer[i] > 126) {
            buffer[i] -= 94;
        }
    }
}

int main() {
    char buffer[MAX_BUFFER_SIZE];
    int key;

    printf("Enter a string to encrypt: ");
    fgets(buffer, MAX_BUFFER_SIZE, stdin);

    printf("Enter an encryption key (1-94): ");
    scanf("%d", &key);

    cryptize(buffer, key);

    printf("\nEncrypted String: %s", buffer);

    return 0;
}