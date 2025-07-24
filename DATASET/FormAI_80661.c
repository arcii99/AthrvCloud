//FormAI DATASET v1.0 Category: Encryption ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY "mysecretkey"

int main() {
    char Message[100];
    char Encrypted[100];
    char Decrypted[100];

    printf("Enter a message to encrypt: ");
    fgets(Message, 100, stdin);

    // Encryption
    for(int i = 0; i < strlen(Message); i++) {
        Encrypted[i] = Message[i] ^ KEY[(i % strlen(KEY))];
    }
    printf("Encrypted Message: %s\n", Encrypted);

    // Decryption
    for(int i = 0; i < strlen(Message); i++) {
        Decrypted[i] = Encrypted[i] ^ KEY[(i % strlen(KEY))];
    }
    printf("Decrypted Message: %s\n", Decrypted);

    return 0;
}