//FormAI DATASET v1.0 Category: modern Encryption ; Style: grateful
#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    char encrypted[100];
    char decrypted[100];
    int key = 2;

    printf("Enter a string to encrypt: ");
    fgets(str, 100, stdin);

    // Encrypt the string
    for(int i = 0; i < strlen(str); i++) {
        if(str[i] >= 'a' && str[i] <= 'z') {
            encrypted[i] = ((str[i] - 'a' + key) % 26) + 'a';
        }
        else if(str[i] >= 'A' && str[i] <= 'Z') {
            encrypted[i] = ((str[i] - 'A' + key) % 26) + 'A';
        }
        else {
            encrypted[i] = str[i];
        }
    }

    printf("Encrypted string: %s", encrypted);

    // Decrypt the string
    for(int i = 0; i < strlen(encrypted); i++) {
        if(encrypted[i] >= 'a' && encrypted[i] <= 'z') {
            decrypted[i] = (((encrypted[i] - 'a') - key + 26) % 26) + 'a';
        }
        else if(encrypted[i] >= 'A' && encrypted[i] <= 'Z') {
            decrypted[i] = (((encrypted[i] - 'A') - key + 26) % 26) + 'A';
        }
        else {
            decrypted[i] = encrypted[i];
        }
    }

    printf("Decrypted string: %s", decrypted);

    return 0;
}