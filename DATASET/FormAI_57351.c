//FormAI DATASET v1.0 Category: Modern Encryption ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_LENGTH 100 // Maximum length for the input string
#define SHIFT 3 // Number of positions to shift for encryption

void encryption(char *input, int key){
    int i;
    char result[MAX_LENGTH]; // Array to store the encrypted string
    for(i=0; i<strlen(input); i++){
        if(input[i]>='a' && input[i]<='z'){ // For lowercase letters
            result[i] = 'a' + (input[i]-'a'+key)%26; // Applying the encryption formula
        }
        else if(input[i]>='A' && input[i]<='Z'){ // For uppercase letters
            result[i] = 'A' + (input[i]-'A'+key)%26; // Applying the encryption formula
        }
        else{
            result[i] = input[i]; // For non-alphabetic characters
        }
    }
    result[strlen(input)] = '\0'; // Terminate the string
    printf("Encrypted string: %s\n", result); // Print the encrypted string
}

int main()
{
    char input[MAX_LENGTH]; // Array to store the input string
    int key;
    printf("Enter the string to be encrypted: ");
    fgets(input, MAX_LENGTH, stdin); // Receive the input string
    input[strcspn(input, "\n")] = '\0'; // Remove the newline character at the end
    printf("Enter the key for encryption: ");
    scanf("%d", &key); // Receive the key for encryption
    encryption(input, key); // Call the encryption function
    return 0;
}