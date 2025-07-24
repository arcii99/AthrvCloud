//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// Function to check if a number is prime or not
int isPrime(int num) {
    int i;
    for (i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

// Function to find the greatest common divisor of two numbers
int gcd(int num1, int num2) {
    if (num2 == 0) {
        return num1;
    }
    else {
        return gcd(num2, num1 % num2);
    }
}

// Function to generate a random prime number between 100 and 1000 for p and q
int generatePrime() {
    int prime;
    do {
        prime = rand() % 901 + 100; // generate a random number between 100 and 1000
    } while (!isPrime(prime)); // repeat until a prime number is generated
    return prime;
}

// Function to calculate the value of e
int calculateE(int phi) {
    int e;
    do {
        e = rand() % (phi - 2) + 2; // generate a random number between 2 and phi-1
    } while (gcd(e, phi) != 1); // repeat until a number that is coprime with phi is generated
    return e;
}

// Function to calculate the value of d using extended Euclidean algorithm
int calculateD(int e, int phi) {
    int d0 = 0, d1 = 1, q, r, temp_phi = phi;

    while (e > 1) {
        q = e / temp_phi;
        r = e % temp_phi;
        e = temp_phi;
        temp_phi = r;

        int dtemp = d0 - q * d1;
        d0 = d1;
        d1 = dtemp;
    }

    if (d1 < 0) {
        d1 += phi;
    }

    return d1;
}

int main() {
    srand(time(0)); // seed the random number generator with current time

    int p = generatePrime();
    int q = generatePrime();
    int n = p * q;
    int phi = (p - 1) * (q - 1);
    int e = calculateE(phi);
    int d = calculateD(e, phi);

    printf("p = %d\nq = %d\nn = %d\nphi = %d\ne = %d\nd = %d\n", p, q, n, phi, e, d);

    return 0;
}