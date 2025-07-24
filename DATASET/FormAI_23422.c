//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: protected
#include <stdio.h>
#include <stdlib.h>

// Function to calculate the power of a number
int power(int x, unsigned int y, int m) {
    int res = 1;      // Initialize result

    x = x % m;  // Update x if it is more than or
                // equal to m

    while (y > 0) {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*x) % m;

        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x) % m;
    }
    return res;
}

// Function to perform the Miller-Rabin primality test
int millerRabinTest(int d, int n) {
    // Pick a random number in [2..n-2]
    // Corner cases make sure that n > 4
    int a = 2 + rand() % (n - 4);

    // Compute a^d % n
    int x = power(a, d, n);

    if (x == 1 || x == n-1)
       return 1;

    // Keep squaring x while one of the following doesn't happen
    // (i)   d does not reach n-1
    // (ii)  (x^2) % n is not 1
    // (iii) (x^2) % n is not n-1
    while (d != n-1) {
        x = (x*x) % n;
        d *= 2;

        if (x == 1)      return 0;
        if (x == n-1)    return 1;
    }

    // Return composite
    return 0;
}

// Function to check if the given number is prime or not
int isPrime(int n, int k) {
    // Corner cases
    if (n <= 1 || n == 4)  return 0;
    if (n <= 3) return 1;

    // Find r such that n = 2^d * r + 1 for some r >= 1
    int d = n - 1;
    while (d % 2 == 0)
        d /= 2;

    // Iterate given number of times
    for (int i = 0; i < k; i++)
         if (millerRabinTest(d, n) == 0)
              return 0;

    return 1;
}

// Function to find the Greatest Common Divisor of two numbers
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// Function to generate a random prime number
int generatePrime() {
    int prime = rand() % 10000 + 2;

    // Keep generating random numbers until a prime is found
    while (!isPrime(prime, 4))
        prime = rand() % 10000 + 2;

    return prime;
}

// Function to perform modular exponentiation
int modularExponentiation(int base, unsigned int exponent, int modulus) {
    int result = 1;
    base = base % modulus;

    while (exponent > 0) {
        if (exponent % 2 == 1)
            result = (result * base) % modulus;

        exponent = exponent >> 1;
        base = (base * base) % modulus;
    }

    return result;
}

// Function implementing the Public-Key Algorithm
void publicKeyAlgorithm() {
    // Generate two random prime numbers
    int p = generatePrime();
    int q = generatePrime();

    // Calculate modulus
    int n = p * q;

    // Calculate totient of n
    int totient = (p-1) * (q-1);

    // Choose a number e such that gcd(e, totient) = 1
    int e = rand() % totient;
    while (gcd(e, totient) != 1)
        e = rand() % totient;

    // Choose a value for d such that d*e = 1 (mod totient)
    int d = 1;
    while ((d * e) % totient != 1 || d == e)
        d++;

    // Display Public and Private keys
    printf("Public Key: (%d, %d)\n", e, n);
    printf("Private Key: (%d, %d)\n", d, n);

    // Take message input
    printf("\nEnter message (number): ");
    int message;
    scanf("%d", &message);

    // Encrypt message
    int cipherText = modularExponentiation(message, e, n);
    printf("Encrypted message: %d\n", cipherText);

    // Decrypt message
    int decryptedText = modularExponentiation(cipherText, d, n);
    printf("Decrypted message: %d\n", decryptedText);
}

// Driver code
int main() {
    publicKeyAlgorithm();

    return 0;
}