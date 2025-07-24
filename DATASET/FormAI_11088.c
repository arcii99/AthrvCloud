//FormAI DATASET v1.0 Category: modern Encryption ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define KEY 3

int main(){
    char message[100];
    int i, length;
    printf("Enter message to be encrypted: ");
    scanf("%[^\n]", message);
    length = strlen(message);
    // Encryption
    for(i = 0; i < length; i++){
        message[i] += KEY; 
    }
    printf("\nEncrypted message: %s\n", message);
    // Decryption
    for(i = 0; i < length; i++){
        message[i] -= KEY; 
    }
    printf("Decrypted message: %s\n", message);
    return 0;
}