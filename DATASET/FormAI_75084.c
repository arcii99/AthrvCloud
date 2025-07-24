//FormAI DATASET v1.0 Category: Encryption ; Style: Sherlock Holmes
#include <stdio.h>
#include <string.h>

int main() {

    char message[100], key[100];
    int i;

    printf("Enter message to encrypt: ");
    scanf("%s", message);

    printf("Enter secret key: ");
    scanf("%s", key);

    int keyLength = strlen(key);

    for (i = 0; message[i] != '\0'; ++i) {
        message[i] = message[i] + key[i % keyLength] - 'a';
    }

    printf("Encrypted message: %s", message);

    return 0;
}