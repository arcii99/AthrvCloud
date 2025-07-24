//FormAI DATASET v1.0 Category: Modern Encryption ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* encrypt(char* message, int key){
    char* encrypted = malloc(strlen(message) * sizeof(char));
    for (int i = 0; i < strlen(message); i++){
        if (message[i] >= 'a' && message[i] <= 'z'){
            encrypted[i] = ((message[i] - 'a' + key) % 26) + 'a';
        }
        else if (message[i] >= 'A' && message[i] <= 'Z'){
            encrypted[i] = ((message[i] - 'A' + key) % 26) + 'A';
        }
        else {
            encrypted[i] = message[i];
        }
    }
    return encrypted;
}

char* decrypt(char* message, int key){
    return encrypt(message, 26 - key);
}

int main(){
    char message[] = "Genius C Encryption Example";
    int key = 5;
    printf("Original message: %s\n", message);
 
    char* encrypted = encrypt(message, key);
    printf("Encrypted message: %s\n", encrypted);
    
    char* decrypted = decrypt(encrypted, key);
    printf("Decrypted message: %s\n", decrypted);
    
    free(encrypted);
    free(decrypted);
    
    return 0;
}