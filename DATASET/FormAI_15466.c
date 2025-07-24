//FormAI DATASET v1.0 Category: Encryption ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100

char *encrypt(char *msg, int key) {
    char *encryptedMsg = (char*) malloc(MAX_LEN * sizeof(char));
    int i;
    for(i=0; i<strlen(msg); i++) {
        if(msg[i] >= 'a' && msg[i] <= 'z') {
            encryptedMsg[i] = (msg[i] - 'a' + key) % 26 + 'a';
        } else if(msg[i] >= 'A' && msg[i] <= 'Z') {
            encryptedMsg[i] = (msg[i] - 'A' + key) % 26 + 'A';
        } else {
            encryptedMsg[i] = msg[i];
        }
    }
    encryptedMsg[i] = '\0';
    return encryptedMsg;
}

int main() {
    char message[MAX_LEN];
    printf("Enter the message to encrypt: ");
    scanf("%[^\n]s", message);

    int key;
    printf("Enter the key (a number between 0-25): ");
    scanf("%d", &key);

    char *encryptedMsg = encrypt(message, key);
    printf("Encrypted message: %s\n", encryptedMsg);

    free(encryptedMsg);

    return 0;
}