//FormAI DATASET v1.0 Category: Modern Encryption ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Recursive encryption function
void encrypt(char str[], int key, int i) {
    if(str[i] == '\0') // Base case: stop recursion when end of string is reached
        return;
    else {
        str[i] += key; // Encrypt current character
        encrypt(str, key, i+1); // Recursively call function for next character
    }
}

int main() {
    char message[100];
    int key;

    printf("Enter message to be encrypted: ");
    fgets(message, 100, stdin);
    message[strcspn(message, "\n")] = 0; // Remove newline character from input

    printf("Enter encryption key: ");
    scanf("%d", &key);
    getchar(); // Remove newline character from input buffer

    encrypt(message, key, 0); // Call recursive encryption function

    printf("Encrypted message using key %d: %s\n", key, message);

    return 0;
}