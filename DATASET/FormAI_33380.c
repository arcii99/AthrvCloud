//FormAI DATASET v1.0 Category: Modern Encryption ; Style: post-apocalyptic
#include <stdio.h>
#include <string.h>

int main() {
    char message[100];
    char password[25];

    printf("Enter your message: ");
    fgets(message, 100, stdin);

    printf("Enter your password: ");
    fgets(password, 25, stdin);
    password[strcspn(password, "\n")] = 0;

    int len = strlen(password);
    for (int i = 0; i < strlen(message); i++) {
        message[i] = message[i] ^ password[i % len];
    }

    printf("The encrypted message is: %s\n", message);

    for (int i = 0; i < strlen(message); i++) {
        message[i] = message[i] ^ password[i % len];
    }

    printf("The decrypted message is: %s\n", message);

    return 0;
}