//FormAI DATASET v1.0 Category: Modern Encryption ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char msg[1000], key[1000], cipher[1000];
    int msg_len, key_len, i, j, k;

    printf("Enter message to encrypt: ");
    fgets(msg, sizeof(msg), stdin);
    printf("Enter encryption key: ");
    fgets(key, sizeof(key), stdin);

    msg_len = strlen(msg) - 1;
    key_len = strlen(key) - 1;

    // fill cipher array with NULL characters
    for(i = 0; i < msg_len; i++) {
        cipher[i] = '\0';
    }

    // encrypt message
    for(i = 0, j = 0, k = 0; i < msg_len; i++, j++, k++) {
        if(j >= key_len) {
            j = 0;
        }
        if(k >= msg_len) {
            k = 0;
        }

        cipher[i] = ((msg[k] + key[j]) % 26) + 'A';
    }

    printf("\nEncrypted message: %s\n", cipher);

    return 0;
}