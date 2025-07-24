//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: rigorous
#include<stdio.h> 

// Function to find gcd of two numbers
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

// Function to calculate pow(x, y) % p
int mod_exp(int x, int y, int p) {
    int res = 1;
    x = x % p;

    while (y > 0) {
        if (y & 1) {
            res = (res*x) % p;
        }
        y = y>>1;
        x = (x*x) % p;
    }
    return res;
}

int main() {
    int p = 13; // Public key
    int alpha = 6; // Primitive root
    int a, b, A, B; // Secret keys

    // Alice generates her secret key
    a = 5;
    A = mod_exp(alpha, a, p);

    // Bob generates his secret key
    b = 7;
    B = mod_exp(alpha, b, p);

    // Shared secret key
    int keyA = mod_exp(B, a, p);
    int keyB = mod_exp(A, b, p);

    // Check if both the secret keys are same
    if (keyA == keyB) {
        printf("Shared secret key is %d\n", keyA);
    }
    else {
        printf("Error in calculating Shared secret key\n");
    }
    return 0;
}