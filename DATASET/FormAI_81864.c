//FormAI DATASET v1.0 Category: Encryption ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* This is a simple encryption program written in C. It takes in a string, encrypts it, and outputs the encrypted string to the user.
   The encryption algorithm is quite simple and works on the basis of incrementing the value of each character in the string by a fixed amount.
   To decrypt the string, simply subtract the same fixed amount from each character in the encrypted string. */

int main() {
    char *str;
    int i, n = 0, key;
    
    /* Prompt the user to enter the string to be encrypted */
    printf("Enter the string to be encrypted:\n");
    scanf("%m[^\n]%*c", &str);
    
    /* Prompt the user to enter the key for encryption */
    printf("Enter the key for encryption (integer value):\n");
    scanf("%d", &key);
    
    /* Determine the length of the input string */
    n = strlen(str);
    
    /* Encrypt the string by incrementing the value of each character by the key amount */
    for(i=0; i<n; i++) {
        str[i] = str[i] + key;
    }
    
    /* Output the encrypted string */
    printf("Encrypted string: %s\n", str);
    
    /* Deallocate memory */
    free(str);
    
    return 0;
}