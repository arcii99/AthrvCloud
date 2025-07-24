//FormAI DATASET v1.0 Category: Encryption ; Style: scientific
/*
 * This program demonstrates an example of C encryption algorithm.
 * It takes the input data from the user and encrypts it using a simple Caesar Cipher method.
 * The Caesar Cipher is a simple shift cipher that relies on shifting each letter of the plain text by a certain number of positions.
 * In this example, the program shifts the letters by 3 positions only, but the shift amount can be chosen arbitrarily.
 * After performing the encryption, the program prints the encrypted text to the console. 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char plain_text[1000], encrypted_text[1000];
    int i, j, shift = 3;

    printf("Enter the text you want to encrypt: ");
    fgets(plain_text, 1000, stdin);

    // Encryption phase
    for (i = 0; i < strlen(plain_text); i++) {
        // Shift only uppercase and lowercase letters
        if ((plain_text[i] >= 'A' && plain_text[i] <= 'Z') || (plain_text[i] >= 'a' && plain_text[i] <= 'z')) {
            // Calculate the new letter position and wrap around if needed
            encrypted_text[i] = (plain_text[i] - 'A' + shift) % 26 + 'A';
            if (plain_text[i] >= 'a' && plain_text[i] <= 'z') {
                encrypted_text[i] += 'a' - 'A'; // Convert to lowercase if needed
            }
        } else {
            encrypted_text[i] = plain_text[i]; // Preserve the original character
        }
    }
    encrypted_text[i] = '\0'; // Terminate the string

    printf("\nHere is the encrypted text: \n%s\n", encrypted_text);

    return 0;
}