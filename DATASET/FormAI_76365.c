//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: curious
#include <stdio.h>

// Our unique public key algorithm implementation
int generatePublicKey(int p, int q) {
    int n = p * q;
    int phi = (p - 1) * (q - 1);
    int e = 2;

    while(e < phi) {
        int gcd = 1;

        for(int i = 2; i <= e && i <= phi; i++) {
            if(e % i == 0 && phi % i == 0) {
                gcd = i;
            }
        }

        if(gcd == 1) {
            break;
        } else {
            e++;
        }
    }

    return e;
}

int main() {
    int p = 61;
    int q = 53;
    int publicKey = generatePublicKey(p, q);

    printf("Public Key: %d", publicKey);
    return 0;
}