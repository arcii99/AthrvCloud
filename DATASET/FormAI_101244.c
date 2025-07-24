//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to perform XOR operation
char *XOR(char *str, char key) {
    int len = strlen(str);
    int i;
    for (i = 0; i < len; i++) {
        str[i] = str[i] ^ key;
    }
    return str;
}

int main() {
    char message[1000];
    char key;
    char encrypted_message[1000];
    char decrypted_message[1000];

    printf("Enter the message to be encrypted: ");
    fgets(message, sizeof(message), stdin);
    printf("Enter the key used for encryption: ");
    scanf("%c", &key);

    // Encrypting the message
    strcpy(encrypted_message, XOR(message, key));

    printf("Encrypted message: %s\n", encrypted_message);

    // Decrypting the message by using the same key
    strcpy(decrypted_message, XOR(encrypted_message, key));

    printf("Decrypted message: %s\n", decrypted_message);

    return 0;
}