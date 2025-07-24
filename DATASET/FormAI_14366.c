//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: random
#include <stdio.h>

int main() {
    printf("Welcome to the C Public-Key Algorithm Implementation program!\n");

    // Step 1: Generate a prime number
    int prime1 = 17;
    int prime2 = 19;
    int n = prime1 * prime2;

    // Step 2: Choose a number for public key exponent e
    int e = 7;

    // Step 3: Calculate the totient of n
    int totient = (prime1 - 1) * (prime2 - 1);

    // Step 4: Calculate the private key exponent d
    int d = 0;
    for(int i = 1; i < totient; i++) {
        if((i * e) % totient == 1) {
            d = i;
            break;
        }
    }

    // Step 5: Encrypt a message
    printf("Enter a message to encrypt: ");
    char message[100];
    scanf("%[^\n]", message);

    int encrypted_message[100];
    for(int i = 0; i < strlen(message); i++) {
        encrypted_message[i] = ((int)message[i])^e % n;
    }
    printf("Encrypted message: ");
    for(int i = 0; i < strlen(message); i++) {
        printf("%d ", encrypted_message[i]);
    }
    printf("\n");

    // Step 6: Decrypt the message
    char decrypted_message[100];
    for(int i = 0; i < strlen(message); i++) {
        decrypted_message[i] = (char)(encrypted_message[i]^d % n);
    }
    printf("Decrypted message: %s\n", decrypted_message);

    return 0;
}