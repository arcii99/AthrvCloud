//FormAI DATASET v1.0 Category: Encryption ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function to encrypt the given string using 
   a simple Caesar Cipher technique */
void encrypt(char string[]) {
    char encrypted[1000];
    int key = 3;   /* Key for the Cipher */
    int length = strlen(string);

    /* Loop through each character of the string */
    for(int i=0; i<length; i++) {
        /* If the current character is an uppercase letter */
        if(string[i] >= 'A' && string[i] <= 'Z') {
            /* Encrypt by shifting the character by the key value */
            encrypted[i] = ((string[i]+key-'A') % 26) + 'A';
        }
        /* If the current character is a lowercase letter */
        else if(string[i] >= 'a' && string[i] <= 'z') {
            /* Encrypt by shifting the character by the key value */
            encrypted[i] = ((string[i]+key-'a') % 26) + 'a';
        }
        /* If the current character is a digit */
        else if(string[i] >= '0' && string[i] <= '9') {
            /* Encrypt by shifting the character by the key value */
            encrypted[i] = ((string[i]+key-'0') % 10) + '0';
        }
        /* If the current character is neither an alphabet nor a digit */
        else {
            /* Don't encrypt, just copy the character as it is */
            encrypted[i] = string[i];
        }
    }
    encrypted[length] = '\0';  /* Add the null terminator at the end */
    printf("Encrypted string: %s\n", encrypted);
}

/* Main Function */
int main() {
    char string[1000];
 
    printf("Enter a string to encrypt: ");
    fgets(string, 1000, stdin);
    string[strcspn(string, "\n")] = '\0';   /* Remove the newline character from the input */
 
    printf("Original string: %s\n", string);
    encrypt(string);
 
    return 0;
}