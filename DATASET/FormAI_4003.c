//FormAI DATASET v1.0 Category: Encryption ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

#define MAX_INPUT 1000

char* encrypt(char input[], int key) {
    char* encrypted = (char*)malloc(sizeof(char) * MAX_INPUT); // allocate memory for encrypted string
    int i = 0; // initialize index
    while (input[i] != '\0') { // loop until end of string
        int ascii = (int)input[i]; // get the ASCII value of current character
        ascii = (ascii + key) % 256; // add key and wrap around ASCII codes
        encrypted[i] = (char)ascii; // cast back to character and store in encrypted string
        i++; // increment index
    }
    encrypted[i] = '\0'; // add null terminator to end of encrypted string
    return encrypted; // return encrypted string
}

int main() {
    char input[MAX_INPUT]; // allocate memory for input string
    int key;
    
    printf("Enter a message to encrypt: ");
    fgets(input, MAX_INPUT, stdin); // read string from user
    printf("Enter a key: ");
    scanf("%d", &key); // read key from user
    
    char* encrypted = encrypt(input, key); // encrypt input string using key
    
    printf("Encrypted message: %s\n", encrypted); // print encrypted message
    
    free(encrypted); // free memory used for encrypted string
    return 0;
}