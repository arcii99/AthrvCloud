//FormAI DATASET v1.0 Category: Modern Encryption ; Style: beginner-friendly
#include <stdio.h>
#include <string.h>

char* encrypt(char* message, int key) {
    int len = strlen(message);
    char* encrypted = (char*)malloc((len+1)*sizeof(char));
    for(int i=0; i<len; i++) {
        if(message[i] >= 'A' && message[i] <= 'Z') {
            encrypted[i] = (((message[i] - 'A') + key) % 26) + 'A';
        }
        else if(message[i] >= 'a' && message[i] <= 'z') {
            encrypted[i] = (((message[i] - 'a') + key) % 26) + 'a';
        }
        else {
            encrypted[i] = message[i];
        }
    }
    encrypted[len] = '\0';
    return encrypted;
}

int main() {
    char message[100];
    int key;
    printf("Enter the message to be encrypted: ");
    scanf("%[^\n]s", message);        // allow whitespaces
    printf("Enter the key: ");
    scanf("%d", &key);
    char* encrypted = encrypt(message, key);
    printf("The encrypted message is: %s", encrypted);
    free(encrypted);              // release memory
    return 0;
}