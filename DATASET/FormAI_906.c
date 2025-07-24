//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1024

/* Function to perform digital watermarking */
void digitalWatermarking(char *originalText) {

    char watermark[] = "My Digital Signature";
    char encryptedText[MAX_SIZE];
    int key = 5;                 // Key for encryption

    /* Encrypt the original text */
    for(int i = 0; originalText[i] != '\0'; ++i) {
        encryptedText[i] = originalText[i] + key;
    }

    /* Concatenate the watermark to the encrypted text */
    strcat(encryptedText, watermark);

    /* Print the encrypted text with the watermark */
    printf("Encrypted Text with Watermark: %s\n", encryptedText);

    /* Decrypt the encrypted text */
    for(int i = 0; encryptedText[i] != '\0'; ++i) {
        originalText[i] = encryptedText[i] - key;
    }

    /* Print the decrypted text */
    printf("Decrypted Text: %s\n", originalText);    
}

/* Driver function */
int main() {

    char originalText[MAX_SIZE];

    /* Get input from user */
    printf("Enter the Original Text: ");
    scanf("%[^\n]s", originalText);

    /* Call the function for digital watermarking */
    digitalWatermarking(originalText);

    return 0;
}