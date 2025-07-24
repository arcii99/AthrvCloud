//FormAI DATASET v1.0 Category: Encryption ; Style: Cyberpunk
#include <stdio.h>

// Cyberpunk encryption algorithm
void encrypt(char *str, int key) {
    int i;
    for(i = 0; str[i] != '\0'; ++i) {
        str[i] += key;
        if(str[i] > 'z') {
            str[i] = str[i] - 'z' + 'a' - 1;
        }
    }
}

int main() {
    char message[50];
    int key;

    // Read message and key from user
    printf("Enter message to encrypt: ");
    gets(message);
    printf("Enter encryption key: ");
    scanf("%d", &key);

    // Encrypt message
    encrypt(message, key);

    // Print encrypted message
    printf("\nEncrypted message: %s\n", message);

    return 0;
}