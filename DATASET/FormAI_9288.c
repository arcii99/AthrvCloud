//FormAI DATASET v1.0 Category: Encryption ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//function to encrypt the message with the given key
char* encrypt(char* message, char* key){
    int messageLength = strlen(message), keyLength = strlen(key);
    char* encryptedMessage = (char*)malloc(messageLength*sizeof(char)); //allocate space for encrypted message
    for(int i=0; i<messageLength; i++){
        //adding the corresponding ascii values of the message and key character,
        //then multiplying it by a random number between 1 and 10
        encryptedMessage[i] = (char)(((int)message[i] + (int)key[i%keyLength]) * (rand()%10+1));
    }
    encryptedMessage[messageLength] = '\0'; //null terminate the encrypted message
    return encryptedMessage;
}

//function to decrypt the message with the given key
char* decrypt(char* encryptedMessage, char* key){
    int messageLength = strlen(encryptedMessage), keyLength = strlen(key);
    char* decryptedMessage = (char*)malloc(messageLength*sizeof(char)); //allocate space for decrypted message
    for(int i=0; i<messageLength; i++){
        //dividing the ascii value of the encrypted message character by the corresponding ascii value of the key
        decryptedMessage[i] = (char)(((int)encryptedMessage[i] / (int)key[i%keyLength]));
    }
    decryptedMessage[messageLength] = '\0'; //null terminate the decrypted message
    return decryptedMessage;
}

int main(){
    char message[100], key[100];
    printf("Enter message to be encrypted: ");
    fgets(message, 100, stdin);
    printf("Enter key: ");
    fgets(key, 100, stdin);
    srand(time(0)); //seed the random number generator with current time
    char* encryptedMessage = encrypt(message, key);
    char* decryptedMessage = decrypt(encryptedMessage, key);
    printf("\nEncrypted message: %s\n", encryptedMessage);
    printf("Decrypted message: %s\n", decryptedMessage);
    free(encryptedMessage); //free the memory allocated for encrypted message
    free(decryptedMessage); //free the memory allocated for decrypted message
    return 0;
}