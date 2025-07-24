//FormAI DATASET v1.0 Category: Modern Encryption ; Style: happy
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    char message[100], encryptedMessage[100], decryptedMessage[100];
    int key, i;
    printf("Welcome! Let's encrypt your message. Enter your message:\n");
    gets(message);
    printf("Enter an integer value for encryption: ");
    scanf("%d", &key);
    
    // encryption process
    for(i=0; message[i] != '\0'; i++){
        encryptedMessage[i] = message[i] + key;
    }

    encryptedMessage[i] = '\0'; // adding terminating null character at the end
    printf("Your encrypted message is: %s\n", encryptedMessage);

    // decryption process
    for(i=0; encryptedMessage[i] != '\0'; i++){
        decryptedMessage[i] = encryptedMessage[i] - key;
    }

    decryptedMessage[i] = '\0'; // adding terminating null character at the end
    printf("Your decrypted message is: %s\n", decryptedMessage);

    printf("Thank you for encrypting and decrypting your message using our program. Have a nice day!\n");
    return 0;
}