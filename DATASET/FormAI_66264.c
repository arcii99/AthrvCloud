//FormAI DATASET v1.0 Category: Modern Encryption ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* encrypt(char* message, int key);

int main() {
    char message[1000];
    int key;

    printf("Enter message to encrypt: ");
    fgets(message, sizeof(message), stdin);

    printf("Enter encryption key: ");
    scanf("%d", &key);

    char* encrypted_message = encrypt(message, key);

    printf("Encrypted message: %s", encrypted_message);

    free(encrypted_message);

    return 0;
}

char* encrypt(char* message, int key) {
    int len = strlen(message);

    char* encrypted_message = (char*) malloc((len+1) * sizeof(char));

    for(int i=0; i<len; i++) {
        if(message[i] >= 'a' && message[i] <= 'z') {
            encrypted_message[i] = ((message[i]-'a'+key)%26)+'a';
        } else if(message[i] >= 'A' && message[i] <= 'Z') {
            encrypted_message[i] = ((message[i]-'A'+key)%26)+'A';
        } else {
            encrypted_message[i] = message[i];
        }
    }

    encrypted_message[len] = '\0';

    return encrypted_message;
}