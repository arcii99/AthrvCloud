//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// function to check whether a number is prime or not
int isPrime(int number) {
    if (number < 2) { // 0 and 1 are not prime numbers
        return 0;
    }
    int i;
    for (i = 2; i <= sqrt(number); i++) {
        if (number % i == 0) { // if number is divisible by i, it is not a prime number
            return 0;
        }
    }
    return 1;
}

// function to generate a random prime number between 100 and 1000
int generatePrime() {
    int number;
    do {
        number = rand() % 901 + 100; // generate a number between 100 and 1000
    } while (!isPrime(number)); // repeat if the number is not prime
    return number;
}

// function to calculate the greatest common divisor of two numbers
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    else {
        return gcd(b, a % b);
    }
}

// function to encrypt a message using the public key
int* encrypt(int message[], int size, int publicKey[], int n) {
    int* encryptedMessage = malloc(size * sizeof(int)); // allocate memory for the encrypted message
    int i;
    for (i = 0; i < size; i++) {
        int power = publicKey[1];
        int base = message[i];
        int j;
        for (j = 1; j < power; j++) { // calculate base^power
            base *= message[i];
            base %= n;
        }
        encryptedMessage[i] = base; // store the encrypted message
    }
    return encryptedMessage;
}

int main() {
    srand(time(NULL)); // seed the random number generator

    // generate two random prime numbers
    int p = generatePrime();
    int q = generatePrime();

    int n = p * q;
    int phi = (p - 1) * (q - 1);

    // generate the public key (e, n)
    int e;
    do {
        e = rand() % phi + 2; // choose a random number between 2 and phi-1
    } while (gcd(e, phi) != 1); // repeat if e and phi have a common factor

    int publicKey[2] = { e, n };

    // generate the private key (d, n)
    int d = 0;
    int i;
    for (i = 1; i < phi; i++) {
        if ((i * e) % phi == 1) { // find a number d such that (e*d) % phi = 1
            d = i;
            break;
        }
    }

    int privateKey[2] = { d, n };

    // print the public and private keys
    printf("Public key: (%d, %d)\n", publicKey[0], publicKey[1]);
    printf("Private key: (%d, %d)\n", privateKey[0], privateKey[1]);

    // get the message to be encrypted
    char message[100];
    printf("Enter the message to be encrypted: ");
    fgets(message, 100, stdin);
    message[strcspn(message, "\n")] = '\0'; // remove the newline character at the end

    // convert the message to an array of integers using ASCII values
    int size = strlen(message);
    int* messageArray = malloc(size * sizeof(int));
    for (i = 0; i < size; i++) {
        messageArray[i] = message[i];
    }

    // encrypt the message using the public key
    int* encryptedMessage = encrypt(messageArray, size, publicKey, n);

    // print the encrypted message
    printf("Encrypted message: ");
    for (i = 0; i < size; i++) {
        printf("%d ", encryptedMessage[i]);
    }
    printf("\n");

    // free the memory
    free(messageArray);
    free(encryptedMessage);

    return 0;
}