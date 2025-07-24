//FormAI DATASET v1.0 Category: Encryption ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char input[], int key) {
    int i;
    char encrypted[strlen(input)];
    
    // loop through each character
    for (i = 0; i < strlen(input); i++) {
        // if uppercase
        if (input[i] >= 'A' && input[i] <= 'Z') {
            encrypted[i] = ((input[i] - 'A') + key) % 26 + 'A'; // shift by key
        }
        // if lowercase
        else if (input[i] >= 'a' && input[i] <= 'z') {
            encrypted[i] = ((input[i] - 'a') + key) % 26 + 'a'; // shift by key
        }
        // if not a letter, keep the same
        else {
            encrypted[i] = input[i];
        }
    }
    printf("Encrypted message: %s\n", encrypted);
}

int main() {
    char message[100];
    int key;

    printf("Enter message to be encrypted: ");
    fgets(message, sizeof(message), stdin); // get user input
    strtok(message, "\n"); // remove trailing newline character

    printf("Enter key: ");
    scanf("%d", &key); // get user input

    encrypt(message, key);
    
    return 0;
}