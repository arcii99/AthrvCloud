//FormAI DATASET v1.0 Category: Encryption ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char *message, int key) {
    int len = strlen(message);
    char result[len];

    for(int i=0;i<len;i++) {
        if(message[i] >= 'a' && message[i] <= 'z') {
            result[i] = ((message[i] - 'a' + key) % 26) + 'a';
        } 
        else if (message[i] >= 'A' && message[i] <= 'Z') {
            result[i] = ((message[i] - 'A' + key) % 26) + 'A';
        }
        else {
            result[i] = message[i];
        }
    }

    strcpy(message, result);
}

int main() {
    char message[100];
    int key;

    printf("Enter message to encrypt: ");
    fgets(message, sizeof(message), stdin);
    message[strcspn(message, "\n")] = 0;

    printf("\nEnter key: ");
    scanf("%d", &key);

    encrypt(message, key);

    printf("\nEncrypted Message: %s", message);

    return 0;
}