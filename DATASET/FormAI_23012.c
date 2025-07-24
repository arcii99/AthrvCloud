//FormAI DATASET v1.0 Category: Encryption ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* encrypt(char* message, int key)
{
    int len = strlen(message);
    char* encrypted = (char*) malloc(len+1);
    
    for(int i=0; i<len; i++)
        encrypted[i] = message[i] + key;
        
    encrypted[len] = '\0';
    return encrypted;
}

char* decrypt(char* encrypted, int key)
{
    int len = strlen(encrypted);
    char* message = (char*) malloc(len+1);
    
    for(int i=0; i<len; i++)
        message[i] = encrypted[i] - key;
    
    message[len] = '\0';
    return message;
}

int main()
{
    char* message = "Attack at dawn!";
    int key = 5;
    
    char* encrypted = encrypt(message, key);
    printf("Encrypted message: %s\n", encrypted);
    
    char* decrypted = decrypt(encrypted, key);
    printf("Decrypted message: %s\n", decrypted);
    
    free(encrypted);
    free(decrypted);
    
    return 0;
}