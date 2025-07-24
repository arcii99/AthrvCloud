//FormAI DATASET v1.0 Category: Encryption ; Style: imaginative
#include <stdio.h>

int main() {
    char message[1000], key[1000], encryptedMsg[1000];
    int msgLen, keyLen, i, j;

    printf("Enter message: ");
    fgets(message, 1000, stdin);
    printf("Enter key: ");
    fgets(key, 1000, stdin);

    msgLen = strlen(message)-1;
    keyLen = strlen(key)-1;

    for(i = 0, j = 0; i < msgLen; ++i, ++j) {
        if(j == keyLen) {
            j = 0;
        }

        encryptedMsg[i] = ((message[i] + key[j]) % 26) + 'A';
    }

    encryptedMsg[i] = '\0';

    printf("\nEncrypted message: %s\n", encryptedMsg);

    return 0;
}