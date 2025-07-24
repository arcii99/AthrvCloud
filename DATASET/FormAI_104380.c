//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

// Returns a random prime number between min and max (inclusive)
int get_random_prime(int min, int max) {
    int num;
    do {
        num = rand() % (max - min + 1) + min;
    } while (!is_prime(num));
    return num;
}

// Checks if a number is prime
int is_prime(int num) {
    if (num <= 1) {
        return 0;
    }
    int i;
    for (i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

// Returns the greatest common divisor of a and b
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

// Returns the multiplicative inverse of a mod b
int get_inverse(int a, int b) {
    int x, y;
    int gcd_val = extended_euclid(a, b, &x, &y);
    if (gcd_val != 1) {
        return -1;
    }
    return (x % b + b) % b;
}

// Extended Euclidean algorithm to find gcd(a, b) and x, y such that ax + by = gcd(a, b)
int extended_euclid(int a, int b, int* x, int* y) {
    if (b == 0) {
        *x = 1;
        *y = 0;
        return a;
    }
    int x1, y1;
    int gcd_val = extended_euclid(b, a % b, &x1, &y1);
    *x = y1;
    *y = x1 - y1 * (a / b);
    return gcd_val;
}

// Encrypts a message using RSA algorithm
void encrypt(char* message, int len, int e, int n, int* encrypted) {
    int i;
    for (i = 0; i < len; i++) {
        encrypted[i] = (int) pow((double) message[i], e) % n;
    }
}

// Decrypts a message using RSA algorithm
void decrypt(int* encrypted, int len, int d, int n, char* decrypted) {
    int i;
    for (i = 0; i < len; i++) {
        decrypted[i] = (char) pow((double) encrypted[i], d) % n;
    }
}

int main() {
    srand(time(NULL));

    int p = get_random_prime(100, 1000);
    int q = get_random_prime(100, 1000);
    int n = p * q;
    int totient = (p - 1) * (q - 1);
    int e = 2;
    while (gcd(e, totient) != 1) {
        e++;
    }
    int d = get_inverse(e, totient);

    char message[] = "Hello world!";
    int len = strlen(message);
    int encrypted[len];
    encrypt(message, len, e, n, encrypted);

    char decrypted[len];
    decrypt(encrypted, len, d, n, decrypted);

    printf("Original message: %s\n", message);
    printf("Encrypted message: ");
    int i;
    for (i = 0; i < len; i++) {
        printf("%d ", encrypted[i]);
    }
    printf("\n");
    printf("Decrypted message: %s\n", decrypted);

    return 0;
}