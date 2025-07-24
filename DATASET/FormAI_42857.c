//FormAI DATASET v1.0 Category: Encryption ; Style: energetic
#include <stdio.h>

// Function to encrypt a string using the Caesar cipher technique
void caesarCipher(char *message, int key) {
    while (*message) {
        if (*message >= 'A' && *message <= 'Z')
            *message = (*message - 'A' + key) % 26 + 'A';
        else if (*message >= 'a' && *message <= 'z')
            *message = (*message - 'a' + key) % 26 + 'a';
        message++;
    }
}

int main() {
    char message[1000];
    int key;

    printf("\nWelcome to the Caesar Cipher Encryption Program!");
    printf("\nEnter the message to encrypt: ");
    fgets(message, 1000, stdin);

    printf("\nEnter the shift key: ");
    scanf("%d", &key);

    caesarCipher(message, key);
    printf("\nYour encrypted message: %s", message);

    return 0;
}