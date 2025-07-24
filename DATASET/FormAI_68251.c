//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: random
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

// Function to perform modulo operation
int mod(int a, int b)
{
    return (a % b + b) % b;
}

// Function to calculate GCD
int find_gcd(int a, int b)
{
    int temp;
    while (1) {
        temp = a % b;
        if (temp == 0)
            return b;
        a = b;
        b = temp;
    }
}

// Function to calculate multiplicative inverse
int calculate_inverse(int a, int b)
{
    int m, x, y, temp;
    m = b;
    x = 0;
    y = 1;
    if (b == 1)
        return 0;

    while (a > 1) {
        temp = a / b;
        temp %= m;
        x = y - temp * x;
        y = temp;
        temp = a;
        a = b;
        b = temp % b;
    }
    if (x < 0)
        x += m;
    return x;
}

// Function to generate public and private keys
void generate_keys()
{
    // Enter two prime numbers
    int p = 7;
    int q = 13;

    // Calculate n
    int n = p * q;

    // Calculate totient of n
    int totient = (p - 1) * (q - 1);

    // Choose a number e such that e and totient are coprime
    int e = 2;
    while (e < totient) {
        if (find_gcd(e, totient) == 1)
            break;
        else
            e++;
    }

    // Calculate private key d
    int d = calculate_inverse(e, totient);

    printf("Public Key = {%d, %d}\n", e, n);
    printf("Private Key = {%d, %d}\n", d, n);
}

int main()
{
    generate_keys();
    return 0;
}