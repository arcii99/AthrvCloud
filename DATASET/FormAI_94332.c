//FormAI DATASET v1.0 Category: Encryption ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1000

// Helper function to encrypt a single character
char encryptChar(char c, int key){
    // Apply a simple shift cipher using the key
    int shifted = (int) c + key;

    // Make sure the shifted value falls within the ASCII range of printable characters
    while (shifted < 32){
        shifted += 94;
    }
    while (shifted > 126){
        shifted -= 94;
    }

    return (char) shifted;
}

int main(){
    // Get input from the user
    char input[MAX_LENGTH];
    printf("Enter the string you want to encrypt: ");
    fgets(input, MAX_LENGTH, stdin);
    input[strcspn(input, "\n")] = '\0'; // Remove the newline character

    // Get the encryption key
    int key;
    printf("Enter the encryption key: ");
    scanf("%d", &key);

    // Encrypt the input string
    int length = strlen(input);
    char* encrypted = (char*) malloc(sizeof(char) * length);
    for (int i = 0; i < length; i++){
        encrypted[i] = encryptChar(input[i], key);
    }

    // Print the encrypted string
    printf("\nEncrypted string:\n%s\n\n", encrypted);

    // Clean up the memory
    free(encrypted);

    return 0;
}