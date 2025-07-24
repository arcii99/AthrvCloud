//FormAI DATASET v1.0 Category: Modern Encryption ; Style: artistic
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    char message[100], key[100];
    int len, i, j, k, key_len;
    int encrypted_message[100], decrypted_message[100];
    srand(time(NULL));

    //Get message from the user
    printf("Enter the message to be encrypted: ");
    fgets(message, sizeof(message), stdin);
    len = strlen(message);

    //Generate random key
    key_len = len - 1;
    for(i=0;i<key_len;i++){
        key[i] = rand()%26 + 'A';
    }
    key[i] = '\0';

    //Display key
    printf("\nGenerated Key: %s\n", key);

    //Encrypt the message
    for(i=0;i<len-1;i++){
        encrypted_message[i] = ((int)message[i] + (int)key[i%key_len]) % 26;
    }
    encrypted_message[i] = '\0';

    //Display encrypted message
    printf("\nEncrypted Message: ");
    for(i=0;i<len-1;i++){
        printf("%c", encrypted_message[i] + 'A');
    }

    //Decrypt the message
    for(i=0;i<len-1;i++){
        decrypted_message[i] = ((int)encrypted_message[i] - (int)key[i%key_len] + 26) % 26;
    }
    decrypted_message[i] = '\0';

    //Display decrypted message
    printf("\nDecrypted Message: ");
    for(i=0;i<len-1;i++){
        printf("%c", decrypted_message[i] + 'A');
    }

    return 0;
}