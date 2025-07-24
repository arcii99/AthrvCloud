//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

int gcd(int a, int b) {
    int temp;
    while (b > 0) {
        temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int p = 3;
    int q = 7;
    int n = p * q;
    int phi = (p - 1) * (q - 1);
    int e = 2;
    int d;
    while (e < phi) {
        if (gcd(e, phi) == 1) {
            break;
        }
        e++;
    }
    for (int i = 1; i < phi; i++) {
        if ((i * e) % phi == 1) {
            d = i;
            break;
        }
    }
    printf("Public Key: {%d, %d}\n", e, n);
    printf("Private Key: {%d, %d}\n", d, n);
    return 0;
}