//FormAI DATASET v1.0 Category: modern Encryption ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char original_msg[100], encrypted_msg[100], decrypted_msg[100];
    int i, key;

    printf("Hooray! Let's Encrypt some messages!\n");
    printf("Enter the message you want to encrypt: ");
    fgets(original_msg, 100, stdin);

    printf("Enter the key for encryption: ");
    scanf("%d", &key);

    // Encrypting the message
    for (i = 0; original_msg[i] != '\0'; i++) {
        if (original_msg[i] >= 'a' && original_msg[i] <= 'z') {
            encrypted_msg[i] = ((original_msg[i] - 'a' + key) % 26) + 'a';
        } else if (original_msg[i] >= 'A' && original_msg[i] <= 'Z') {
            encrypted_msg[i] = ((original_msg[i] - 'A' + key) % 26) + 'A';
        } else if (original_msg[i] == ' ') {
            encrypted_msg[i] = ' ';
        }
    }
    encrypted_msg[i] = '\0';

    printf("Your encrypted message is: %s\n", encrypted_msg);

    // Decrypting the message
    for (i = 0; encrypted_msg[i] != '\0'; i++) {
        if (encrypted_msg[i] >= 'a' && encrypted_msg[i] <= 'z') {
            decrypted_msg[i] = (((encrypted_msg[i] - 'a') - key + 26) % 26) + 'a';
        } else if (encrypted_msg[i] >= 'A' && encrypted_msg[i] <= 'Z') {
            decrypted_msg[i] = (((encrypted_msg[i] - 'A') - key + 26) % 26) + 'A';
        } else if (encrypted_msg[i] == ' ') {
            decrypted_msg[i] = ' ';
        }
    }
    decrypted_msg[i] = '\0';

    printf("Your decrypted message is: %s\n", decrypted_msg);

    printf("Hurrah! Our encryption is awesome!\n");

    return 0;
}