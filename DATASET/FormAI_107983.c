//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: romantic
#include <stdio.h>
#include <stdlib.h>

/* A romantic twist on the RSA public-key algorithm */

int main()
{
    // Prompt the user to enter their message and calculate its length
    printf("My dearest love, please enter your message: ");
    char message[200];
    fgets(message, 200, stdin);

    // Calculate the length of the message
    int length = 0;
    while (message[length] != '\0') {
        length++;
    }

    // Generate two random prime numbers
    int p = 29;
    int q = 31;

    // Calculate n, the modulus
    int n = p * q;

    // Calculate phi(n), the totient of n
    int phi = (p - 1) * (q - 1);

    // Choose a public key e that is relatively prime to phi(n)
    int e = 13;

    // Calculate the private key d for decryption
    int d = 197;

    // Encrypt the message using the public key
    int i;
    int encrypted[length];
    for (i = 0; i < length; i++) {
        encrypted[i] = ((int)message[i])^e % n;
    }

    // Decrypt the message using the private key
    char decrypted[length];
    for (i = 0; i < length; i++) {
        decrypted[i] = (char)(encrypted[i]^d % n);
    }

    // Print the original message, encrypted message, and decrypted message
    printf("My love, here is your original message: %s\n", message);
    printf("And here is your message encrypted with my love: ");
    for (i = 0; i < length; i++) {
        printf("%d ", encrypted[i]);
    }
    printf("\nFinally, here is your message decrypted with our love: %s\n", decrypted);

    return 0;
}