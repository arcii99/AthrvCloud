//FormAI DATASET v1.0 Category: Encryption ; Style: cheerful
#include <stdio.h>
#include <string.h>

int main(){
    
    // Welcome message
    printf("Hello there!\n");
    printf("Today we are going to learn about C Encryption!\n");
    
    // Get user input
    char plaintext[100], key[100], encrypted[100];
    printf("Please enter some text to encrypt: ");
    scanf("%s", plaintext);
    printf("Please enter a key to use for encryption: ");
    scanf("%s", key);
    
    // Encryption algorithm
    int i, j = 0, keyLength = strlen(key);
    for(i = 0; i < strlen(plaintext); i++){
        encrypted[i] = plaintext[i] ^ key[j];
        j++;
        if(j == keyLength) j = 0;
    }
    encrypted[i] = '\0'; // Add null terminator to end of string
    
    // Print out encrypted text
    printf("Your text has been encrypted! Here is the result:\n");
    printf("%s\n", encrypted);
    
    return 0;
}