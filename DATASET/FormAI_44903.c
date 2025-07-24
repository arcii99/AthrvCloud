//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: Cryptic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define byte unsigned char
#define ERROR -1
#define NO_ERROR 0

/* The main function takes user input of a message and generates a C checksum for it */ 
int main() {
    byte checksum = 0;
    byte length = 0;
    char message[256], code[256]; 

    printf("Enter your message: "); // Prompt user to input message
    fgets(message, 256, stdin);

    length = strlen(message);

    // Append encrypted code to the message
    for(int i = 0; i < length; ++i) {
        code[i] = message[i] + 2; // Encrypt the message with a Caesar Cipher
        checksum ^= code[i]; // Generate the checksum
    }

    code[length-1] = checksum; // Append the checksum to the message

    // Let the user know the encrypted code and the C checksum
    printf("\n%s\n", code);
    printf("The C checksum is: %d", checksum);

    return NO_ERROR;
}