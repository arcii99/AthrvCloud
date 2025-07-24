//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    unsigned long long public_exponent;
    unsigned long long modulus;
} public_key;

typedef struct {
    unsigned long long private_exponent;
    unsigned long long modulus;
} private_key;

public_key generate_public_key(unsigned long long p, unsigned long long q, unsigned long long e);

private_key generate_private_key(unsigned long long p, unsigned long long q, unsigned long long e);

int main() {
    // The following code block generates the public and private keys
    unsigned long long p = 1763, q = 1481, e = 3;
    public_key pub_key = generate_public_key(p, q, e);
    private_key priv_key = generate_private_key(p, q, e);

    printf("The public key is: (%llu, %llu)\n", pub_key.public_exponent, pub_key.modulus);
    printf("The private key is: (%llu, %llu)\n", priv_key.private_exponent, priv_key.modulus);

    // The following code block is an example of encryption and decryption using the generated keys
    char message[] = "The game is afoot!";
    unsigned long long message_length = strlen(message);
    unsigned long long encrypted_message[message_length];

    for (int i = 0; i < message_length; i++) {
        encrypted_message[i] = message[i];
        for (int j = 0; j < pub_key.public_exponent - 1; j++) {
            encrypted_message[i] = (encrypted_message[i] * message[i]) % pub_key.modulus;
        }
    }

    printf("The encrypted message is: ");
    for (int i = 0; i < message_length; i++) {
        printf("%llu ", encrypted_message[i]);
    }
    printf("\n");

    char decrypted_message[message_length];
    for (int i = 0; i < message_length; i++) {
        decrypted_message[i] = encrypted_message[i];
        for (int j = 0; j < priv_key.private_exponent - 1; j++) {
            decrypted_message[i] = (decrypted_message[i] * encrypted_message[i]) % priv_key.modulus;
        }
    }

    printf("The decrypted message is: %s\n", decrypted_message);

    return 0;
}

public_key generate_public_key(unsigned long long p, unsigned long long q, unsigned long long e) {
    public_key pub_key;
    pub_key.modulus = p * q;
    pub_key.public_exponent = e;
    return pub_key;
}

private_key generate_private_key(unsigned long long p, unsigned long long q, unsigned long long e) {
    private_key priv_key;
    unsigned long long phi = (p - 1) * (q - 1);
    unsigned long long d = 1;
    while ((d * e) % phi != 1) {
        d++;
    }
    priv_key.modulus = p * q;
    priv_key.private_exponent = d;
    return priv_key;
}