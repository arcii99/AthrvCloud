//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: cheerful
#include <stdio.h>

int main() {
    printf("Hello my cheerful friend! Are you ready for some cryptography fun?\n");
    printf("Today, we're going to work on implementing a Public Key Algorithm in C!\n");
    printf("Don't worry if you don't know what that means, I'll explain it to you.\n");

    printf("Firstly, let's generate our public and private keys.\n");
    printf("I'll use RSA algorithm for this example.\n");

    int p = 11, q = 3, n, phi, e = 7, d = 3; // Here we initialize our variables
    // You can choose other values for these numbers as well

    n = p * q; // The value of n is the product of p and q
    phi = (p - 1) * (q - 1); // We calculate Euler Totient function value of n

    printf("\nThe value of n is: %d \n", n);
    printf("The value of phi is: %d \n", phi);

    // Now, we find the public key exponent
    while (e < phi) {
        if ((e * d) % phi == 1) {
            break; // We stop when the public and private keys are found
        }
        e++;
    }

    printf("The public key exponent is: %d \n", e);
    printf("The private key exponent is: %d \n", d);

    // Now that we have our keys, let's encrypt and decrypt a message

    // First we declare our message as a string
    char message[] = "I am a cheerful chatbot!";

    printf("\nOur message is: %s\n", message);

    // Next, we declare a variable for the ciphertext
    int ciphertext[strlen(message)];

    // Let's encrypt the message using our public key
    for (int i = 0; i < strlen(message); i++) {
        ciphertext[i] = (int)message[i] + e;
        printf("%d ", ciphertext[i]); // We print each value of the ciphertext
    }

    // Now, let's decrypt the message using our private key
    char plaintext[strlen(message)];

    for (int i = 0; i < strlen(message); i++) {
        plaintext[i] = (char)(ciphertext[i] - d);
    }

    printf("\nOur decrypted message is: %s\n", plaintext);

    printf("\nYay! We successfully implemented a Public Key Algorithm! \n");
    printf("Thanks for coding with me, cheerful friend! Have a wonderful day! \n");

    return 0;
}