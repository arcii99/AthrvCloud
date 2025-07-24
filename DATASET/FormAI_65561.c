//FormAI DATASET v1.0 Category: Encryption ; Style: minimalist
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

char *encrypt(char *msg, int key) {
    int len = strlen(msg);
    char *enc_msg = (char*) malloc(sizeof(char) * (len + 1));
    for (int i = 0; i < len; i++) {
        enc_msg[i] = (char) (((int)msg[i] - 'A' + key) % 26 + 'A');
    }
    enc_msg[len] = '\0';
    return enc_msg;
}

int main() {
    char message[MAX], *encrypted_msg;
    int key;

    printf("Enter message to encrypt: ");
    fgets(message, MAX, stdin);
    message[strlen(message) - 1] = '\0';

    printf("Enter encryption key (1-25): ");
    scanf("%d", &key);

    encrypted_msg = encrypt(message, key);
    printf("Encrypted message: %s\n", encrypted_msg);

    free(encrypted_msg);
    return 0;
}