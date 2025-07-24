//FormAI DATASET v1.0 Category: Encryption ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to encrypt the given message using the Caesar cipher
char *encrypt(char message[], int shift) {
    char *encryptedMessage = (char *) malloc(sizeof(message)); // allocate memory for the encrypted message
    int length = strlen(message);
    for(int i=0; i<length; i++) {
        if(message[i] >= 'A' && message[i] <= 'Z') {
            encryptedMessage[i] = ((message[i] - 'A' + shift) % 26) + 'A'; // shift the letter by given amount
        }
        else if(message[i] >= 'a' && message[i] <= 'z') {
            encryptedMessage[i] = ((message[i] - 'a' + shift) % 26) + 'a'; // shift the letter by given amount
        }
        else {
            encryptedMessage[i] = message[i]; // leave spaces and other characters as is
        }
    }
    encryptedMessage[length] = '\0'; // add null terminator to the end of the string
    return encryptedMessage;
}

int main() {
    char message[100];
    int shift;
    printf("Enter the message to be encrypted: ");
    fgets(message, sizeof(message), stdin); // get the input message from the user
    message[strcspn(message, "\n")] = '\0'; // remove the newline character from the end of the string
    printf("Enter the shift amount: ");
    scanf("%d", &shift); // get the shift amount from the user
    char *encryptedMessage = encrypt(message, shift); // encrypt the message using the Caesar cipher
    printf("The encrypted message is: %s\n", encryptedMessage); // print the encrypted message
    
    return 0;
}