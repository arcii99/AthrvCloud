//FormAI DATASET v1.0 Category: Encryption ; Style: Dennis Ritchie
#include <stdio.h>
#include <string.h>

// Define the encryption key
#define ENCRYPTION_KEY 4

void encrypt(char* input, char* output) {
    int i, ascii;

    for(i = 0; i < strlen(input); i++) {
        ascii = (int) input[i];

        // If the character is uppercase
        if(ascii >= 65 && ascii <= 90)
            output[i] = ((ascii - 65 + ENCRYPTION_KEY) % 26) + 65;
        // If the character is lowercase
        else if(ascii >= 97 && ascii <= 122)
            output[i] = ((ascii - 97 + ENCRYPTION_KEY) % 26) + 97;
        // If the character is a number
        else if(ascii >= 48 && ascii <= 57)
            output[i] = ((ascii - 48 + ENCRYPTION_KEY) % 10) + 48;
        // If the character is not a letter or a number
        else
            output[i] = input[i];
    }

    output[i] = '\0';
}

int main() {
    char input[256], output[256];

    printf("Enter a string to encrypt: ");
    fgets(input, sizeof(input), stdin);

    // Remove the newline character from input
    input[strcspn(input, "\n")] = 0;

    encrypt(input, output);

    printf("Encrypted string: %s", output);

    return 0;
}