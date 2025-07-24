//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MESSAGE_SIZE 50

// Function to generate a random prime number
int random_prime() {
    int number = rand() % 100;
    int is_prime = 0;

    while (!is_prime) {
        is_prime = 1;
        number++;
        for (int i = 2; i < number; i++) {
            if (number % i == 0) {
                is_prime = 0;
                break;
            }
        }
    }

    return number;
}

int main() {
    srand(time(NULL));
    int p = random_prime();
    int q = random_prime();
    int n = p * q;
    int phi = (p - 1) * (q - 1);
    int e = 0;
    int d = 0;

    // Find e such that it is coprime with phi
    for (int i = 2; i < phi; i++) {
        if (phi % i != 0) {
            e = i;
            break;
        }
    }

    // Find d such that e*d mod phi = 1
    for (int i = 1; i < phi; i++) {
        if ((e * i) % phi == 1) {
            d = i;
            break;
        }
    }

    printf("Public key: (%d, %d)\n", n, e);
    printf("Private key: (%d, %d)\n", n, d);

    // Encrypt message
    char message[MESSAGE_SIZE] = "Hello, world!";
    int encrypted_message[MESSAGE_SIZE];
    for (int i = 0; i < MESSAGE_SIZE; i++) {
        int m = message[i];
        int c = 1;
        for (int j = 0; j < e; j++) {
            c = (c * m) % n;
        }
        encrypted_message[i] = c;
    }

    // Decrypt message
    char decrypted_message[MESSAGE_SIZE];
    for (int i = 0; i < MESSAGE_SIZE; i++) {
        int c = encrypted_message[i];
        int m = 1;
        for (int j = 0; j < d; j++) {
            m = (m * c) % n;
        }
        decrypted_message[i] = m;
    }

    printf("Original message: %s\n", message);
    printf("Encrypted message: ");
    for (int i = 0; i < MESSAGE_SIZE; i++) {
        printf("%d ", encrypted_message[i]);
    }
    printf("\n");
    printf("Decrypted message: %s\n", decrypted_message);

    return 0;
}