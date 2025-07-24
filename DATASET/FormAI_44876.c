//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

// Euclid's algorithm for finding the greatest common denominator of two numbers
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// Generate a random prime number between a and b
int generatePrime(int a, int b) {
    int num = rand() % (b - a + 1) + a;
    int i;
    for (i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            num = rand() % (b - a + 1) + a; // regenerate if not prime
            i = 1; // reset i to 2
        }
    }
    return num;
}

int main() {
    int p = generatePrime(100, 999); // generate first prime number
    int q = generatePrime(1000, 9999); // generate second prime number

    int n = p * q; // modulus n

    int phi = (p - 1) * (q - 1); // Euler's totient function

    int e = 2;
    while (gcd(e, phi) != 1) { // find e such that e and phi(n) are coprime
        e++;
    }

    int d;
    int k = 1;
    while (((k * phi) + 1) % e != 0) { // find d such that d and e are multiplicative inverses
        k++;
    }
    d = ((k * phi) + 1) / e;

    printf("Public Key: (%d, %d)\n", e, n); // print public key
    printf("Private Key: (%d, %d)\n", d, n); // print private key

    // encrypt the message
    char message[100];
    printf("Enter message to encrypt: ");
    scanf("%s", message);

    int i;
    int encrypted[100];
    for (i = 0; message[i] != '\0'; i++) {
        encrypted[i] = (int)message[i];
        encrypted[i] = (int)pow(encrypted[i], e);
        encrypted[i] = encrypted[i] % n; // mod n
    }
    encrypted[i] = -1;

    printf("Encrypted message: ");
    for (i = 0; encrypted[i] != -1; i++) {
        printf("%d ", encrypted[i]);
    }

    // decrypt the message
    int decrypted[100];
    for (i = 0; encrypted[i] != -1; i++) {
        decrypted[i] = encrypted[i];
        decrypted[i] = (int)pow(decrypted[i], d);
        decrypted[i] = decrypted[i] % n; // mod n
    }
    decrypted[i] = -1;

    printf("\nDecrypted message: ");
    for (i = 0; decrypted[i] != -1; i++) {
        printf("%c", decrypted[i]);
    }
    printf("\n");

    return 0;
}