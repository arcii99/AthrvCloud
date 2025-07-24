//FormAI DATASET v1.0 Category: Encryption ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* cEncrypt(char* message, char* key) {
    int len = strlen(message);
    char* result = (char*) malloc(sizeof(char) * len);

    for(int i = 0; i < len; i++) {
        char c = message[i];
        int pos = c - 'a';
        result[i] = key[pos];
    }

    result[len] = '\0';
    return result;
}

int main() {
    char message[100];
    char key[26] = "qazwsxedcrfvtgbyhnujmikolp";

    printf("Enter your message: ");
    fgets(message, 100, stdin);

    char* encryptedMessage = cEncrypt(message, key);
    printf("Encrypted message: %s", encryptedMessage);

    free(encryptedMessage);
    return 0;
}