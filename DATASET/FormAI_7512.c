//FormAI DATASET v1.0 Category: modern Encryption ; Style: relaxed
#include <stdio.h>
#include <string.h>

#define MAX_LEN 50

int main() {
    char message[MAX_LEN], encrypted[MAX_LEN], decrypted[MAX_LEN];
    int key = 3; // Shift key

    printf("Enter message to encrypt: ");
    fgets(message, MAX_LEN, stdin);

    // Encryption
    for(int i = 0; i < strlen(message); i++) {
        if(message[i] == '\n') {
            encrypted[i] = message[i];
            continue;
        }
        if(message[i] >= 'a' && message[i] <= 'z') {
            encrypted[i] = (message[i] - 'a' + key) % 26 + 'a';
        } else if(message[i] >= 'A' && message[i] <= 'Z') {
            encrypted[i] = (message[i] - 'A' + key) % 26 + 'A';
        } else {
            encrypted[i] = message[i];
        }
    }
    printf("Encrypted message: %s\n", encrypted);

    // Decryption
    for(int i = 0; i < strlen(encrypted); i++) {
        if(encrypted[i] == '\n') {
            decrypted[i] = encrypted[i];
            continue;
        }
        if(encrypted[i] >= 'a' && encrypted[i] <= 'z') {
            decrypted[i] = (encrypted[i] - 'a' - key + 26) % 26 + 'a';
        } else if(encrypted[i] >= 'A' && encrypted[i] <= 'Z') {
            decrypted[i] = (encrypted[i] - 'A' - key + 26) % 26 + 'A';
        } else {
            decrypted[i] = encrypted[i];
        }
    }
    printf("Decrypted message: %s\n", decrypted);

    return 0;
}