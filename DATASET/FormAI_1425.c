//FormAI DATASET v1.0 Category: Encryption ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    srand(time(NULL));
    char message[100], encrypted[100], decrypted[100], key[100];
    printf("Enter message to encrypt: ");
    fgets(message, 100, stdin);
    printf("Encrypting message...\n");
    int i, len = strlen(message);

    for (i = 0; i < len; i++) {
        int rand_num = rand() % 100;
        encrypted[i] = message[i] + rand_num;
        key[i] = rand_num;
    }
    encrypted[i] = '\0';
    key[i] = '\0';
    printf("Encrypted message: %s\n", encrypted);
    printf("Key: %s\n", key);

    printf("Decrypting message...\n");
    for (i = 0; i < len; i++) {
        decrypted[i] = encrypted[i] - key[i];
    }
    decrypted[i] = '\0';
    printf("Decrypted message: %s\n", decrypted);
    return 0;
}