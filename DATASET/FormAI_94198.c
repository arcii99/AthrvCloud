//FormAI DATASET v1.0 Category: Encryption ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* encrypt(char* message, char* key);

int main()
{
    char* message = "Hello World";
    char* key = "SecretPhrase";
    char* encrypted_message = encrypt(message, key);
    
    printf("Original message: %s\n", message);
    printf("Encrypted message: %s\n", encrypted_message);

    free(encrypted_message);
    return 0;
}

char* encrypt(char* message, char* key)
{
    int message_length = strlen(message);
    int key_length = strlen(key);
    
    char* encrypted_message = (char*)malloc((message_length+1) * sizeof(char));
    encrypted_message[message_length] = '\0';

    for(int i=0; i<message_length; i++)
    {
        encrypted_message[i] = message[i] ^ key[i%key_length];
    }

    return encrypted_message;
}