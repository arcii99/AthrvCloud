//FormAI DATASET v1.0 Category: Encryption ; Style: lively
#include <stdio.h>

char* encrypt(char message[], int key) {
    int i;
    char encryptedMsg[100];
    
    for(i=0; message[i] != '\0'; i++) {
        encryptedMsg[i] = message[i] + key;
    }
    encryptedMsg[i] = '\0';
    return encryptedMsg;
}

int main() {
    char message[] = "Hello, World!";
    int key = 5;
    char* encryptedMsg = encrypt(message, key);
    
    printf("Original Message: %s \n", message);
    printf("Key: %d \n", key);
    printf("Encrypted Message: %s \n", encryptedMsg);
    
    return 0;
}