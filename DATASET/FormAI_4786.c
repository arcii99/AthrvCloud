//FormAI DATASET v1.0 Category: Modern Encryption ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Welcome message
    printf("Hello, I am an encryption program. But don't worry, I won't tell your secrets to anyone!\n");

    // Input message to be encrypted
    char message[100];
    printf("Please tell me your secret message: ");
    fgets(message, 100, stdin);

    // Input encryption key
    int key;
    printf("Now, give me a number to use as a key: ");
    scanf("%d", &key);

    // Encryption algorithm
    int len = strlen(message);
    for (int i = 0; i < len - 1; i++) {
        message[i] += key;
    }

    // Output encrypted message
    printf("Your encrypted message is: %s\n", message);

    // Bonus feature: reverse encryption
    char answer;
    printf("Do you want to decrypt your message? (y/n) ");
    scanf(" %c", &answer);
    if (answer == 'y') {
        for (int i = 0; i < len - 1; i++) {
            message[i] -= key;
        }
        printf("Your decrypted message is: %s\n", message);
    } else {
        printf("OK, bye!\n");
    }

    return 0;
}