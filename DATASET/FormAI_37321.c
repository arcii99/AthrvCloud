//FormAI DATASET v1.0 Category: Encryption ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    char message[100];
    int key, length, i;

    printf("Welcome to the Caesar Cipher!\n");

    printf("Please enter a message to encrypt: ");
    scanf("%[^\n]s", message);

    printf("Please enter a key (positive integer): ");
    scanf("%d", &key);

    length = strlen(message);

    for(i=0; i<length; i++) {

        if(message[i] >= 'a' && message[i] <= 'z') {

            message[i] = message[i] + key;

            if(message[i] > 'z') {
                message[i] = message[i] - 'z' + 'a' - 1;
            }

        } else if(message[i] >= 'A' && message[i] <= 'Z') {

            message[i] = message[i] + key;

            if(message[i] > 'Z') {
                message[i] = message[i] - 'Z' + 'A' - 1;
            }

        }

    }

    printf("Encrypted message: %s\n", message);

    return 0;
}