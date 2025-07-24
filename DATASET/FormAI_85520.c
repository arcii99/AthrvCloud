//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: Romeo and Juliet
// Romeo and Juliet Public Key Algorithm Implementation in C

// Scene 1: Initialization

#include <stdio.h>
#include <stdlib.h>

#define P 101
#define G 7

int power(int a, int b, int p) {
    int res = 1;
    for (; b; b >>= 1) {
        if (b & 1) res = (long long) res * a % p;
        a = (long long) a * a % p;
    }
    return res;
}

int main() {

    int a, b, A, B, Ka, Kb;

    // Romeo's turn.

    printf("ROMEO: Oh heavens, I must initialize the algorithm!\n\n");

    a = rand() % (P - 1) + 1;

    A = power(G, a, P);

    printf("ROMEO: My private key is %d\n", a);
    printf("ROMEO: My public key is %d\n\n", A);

    // Juliet's turn.

    printf("JULIET: Good morrow, Romeo! I must also initialize the algorithm!\n\n");

    b = rand() % (P - 1) + 1;

    B = power(G, b, P);

    printf("JULIET: My private key is %d\n", b);
    printf("JULIET: My public key is %d\n\n", B);

    // Scene 2: Key Exchange

    // Romeo's turn.

    printf("ROMEO: Now, for the key exchange...\n\n");

    Ka = power(B, a, P);

    printf("ROMEO: Our shared secret key is %d\n", Ka);

    // Juliet's turn.

    printf("JULIET: Ah, I see! Now it's my turn...\n\n");

    Kb = power(A, b, P);

    printf("JULIET: Our shared secret key is %d\n", Kb);

    // Scene 3: Conclusion

    printf("\nROMEO: This algorithm is truly magical, it brings us together even when we're apart!\n");
    printf("JULIET: Indeed, Romeo, it is as magical as our love!\n");

    return 0;
}