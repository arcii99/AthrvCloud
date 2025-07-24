//FormAI DATASET v1.0 Category: File Encyptor ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 1024

void encrypt(char *str) {
    int i, j, len;
    char *result = (char *) malloc(strlen(str) * sizeof(char));
    
    // Convert all characters to their ASCII code
    for(i = 0; i < strlen(str); i++) {
        result[i] = (char) (str[i] + 4); // Shift the ASCII code by 4
    }
    
    // Reverse the string
    len = strlen(result);
    for(i = 0, j = len - 1; i < j; i++, j--) {
        char temp = result[i];
        result[i] = result[j];
        result[j] = temp;
    }
    
    // Replace every vowel with its uppercase counterpart
    for(i = 0; i < strlen(result); i++) {
        if(result[i] == 'a' || result[i] == 'e' || result[i] == 'i' || result[i] == 'o' || result[i] == 'u') {
            result[i] = toupper(result[i]);
        }
    }
    
    // Output the encrypted string
    printf("Encrypted string: %s\n", result);
    free(result);
}

int main() {
    char input[MAX_LENGTH];
    
    // Get input from the user
    printf("Enter a string to encrypt: ");
    fgets(input, MAX_LENGTH, stdin);
    input[strlen(input) - 1] = '\0'; // Remove newline character
    
    // Encrypt the string
    encrypt(input);
    
    return 0;
}