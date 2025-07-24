//FormAI DATASET v1.0 Category: modern Encryption ; Style: happy
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

// Function to encrypt a given message string using the Caesar cipher encryption scheme
// The program shifts the letters by a random constant value determined by the current time, 
// giving a unique encryption key every time the program is run

char* encrypt(char *message){
    srand(time(0));
    int shift = rand()%26 + 1; // Generating a random shift value between 1 and 26
    char *encrypted_message = (char*) malloc (sizeof(char)*strlen(message)+1); // Allocate memory for the encrypted message string

    // Loop through each character in the input string and shift it by the random constant value
    for(int i=0; i<strlen(message); i++){
        if(message[i] >= 'a' && message[i] <= 'z')
            encrypted_message[i] = ((message[i] - 'a') + shift) % 26 + 'a'; // Shift lowercase letters
        else if(message[i] >= 'A' && message[i] <= 'Z')
            encrypted_message[i] = ((message[i] - 'A') + shift) % 26 + 'A'; // Shift uppercase letters
        else
            encrypted_message[i] = message[i]; // Leave non-alphabetical characters unchanged
    }
    encrypted_message[strlen(message)] = '\0'; // Append null character to the end of the encrypted message string
    return encrypted_message; // Return the encrypted message string
}

int main(){
    char message[100], *encrypted_message;
    printf("Enter a message to encrypt: ");
    fgets(message, 100, stdin);
    message[strlen(message)-1] = '\0'; // Remove the newline character at the end of the input string
    encrypted_message = encrypt(message); // Call the encryption function
    printf("The encrypted message is: %s", encrypted_message);
    free(encrypted_message); // Free the memory allocated for the encrypted message string
    return 0;
}