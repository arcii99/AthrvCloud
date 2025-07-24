//FormAI DATASET v1.0 Category: Encryption ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SHIFT 3 //Change this value to increase/decrease the level of encryption

char* encrypt(char* message, int shift) {
    size_t length = strlen(message); //Get length of message
    char* encrypted = (char*) malloc(length + 1); //Allocate memory for encrypted message
    
    for(int i = 0; i < length; i++) {
        if(message[i] >= 'a' && message[i] <= 'z') { //'a' represents the starting lowercase alphabet character and 'z' represents the ending lowercase alphabet character in the ASCII table
            
            int newIndex = (message[i] - 'a' + shift) % 26; //The algorithm for encryption
            encrypted[i] = 'a' + newIndex; //Convert to character
            
        } else if(message[i] >= 'A' && message[i] <= 'Z') { //'A' represents the starting uppercase alphabet character and 'Z' represents the ending uppercase alphabet character in the ASCII table
            
            int newIndex = (message[i] - 'A' + shift) % 26; //The algorithm for encryption
            encrypted[i] = 'A' + newIndex; //Convert to character
            
        } else {
            encrypted[i] = message[i]; //If the character is not a letter, then leave it unchanged
        }
    }
    
    encrypted[length] = '\0'; //Add a null terminator to the end of the encrypted message
    
    return encrypted;
}

int main() {
    char message[100]; //Assuming a maximum message size of 100 characters
    printf("Enter the message that needs to be encrypted: ");
    fgets(message, 100, stdin); //Taking input from user
    
    char* encrypted = encrypt(message, SHIFT); //Encrypting the message
    
    printf("Encrypted message: %s", encrypted); //Print the encrypted message
    
    free(encrypted); //Deallocate the memory allocated for encrypted message
    
    return 0;
}