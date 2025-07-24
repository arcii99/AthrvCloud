//FormAI DATASET v1.0 Category: modern Encryption ; Style: bold
#include <stdio.h>
#include <string.h>

#define KEY 10 // The secret key for the encryption
#define MAX_LENGTH 100 // Maximum length of the input string

void encrypt(char *input){ // Function to encrypt the input string
    int i;
    for(i=0; i<strlen(input); i++){
        // Apply the secret key to the ASCII value of each character in the string
        input[i] = ((int)input[i] + KEY) % 128; 
    }
}

void decrypt(char *input){ // Function to decrypt the input string
    int i;
    for(i=0; i<strlen(input); i++){
        // Reverse the encryption process by subtracting the secret key from each character's ASCII value
        input[i] = ((int)input[i] - KEY + 128) % 128;
    }
}

int main(){
    char input[MAX_LENGTH];
    printf("Enter your message: ");
    fgets(input, MAX_LENGTH, stdin); // Take input from user

    encrypt(input); // Encrypt the input message

    printf("Encrypted message: %s\n", input);

    decrypt(input); // Decrypt the encrypted message

    printf("Decrypted message: %s\n", input);

    return 0;
}