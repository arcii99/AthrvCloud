//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: accurate
#include<stdio.h>
#include<math.h>

long long int gcd(long long int a, long long int h) {
    long long int temp;
    while (1) {
        temp = a%h;
        if (temp == 0)
          return h;
        a = h;
        h = temp;
    }
}

int main() {
    long long int p, q, n,phi,e,d,c,i;
    printf("Enter two prime numbers: ");
    scanf("%lld %lld",&p, &q);
    n = p*q;
    phi = (p-1)*(q-1);
    for (e=2; e<phi; e++) {
        if (gcd(e, phi)==1)
            break;
    }
    for (d=1; d<=phi; d++) {
        if (((d*e)%phi)==1)
            break;
    }
    printf("Public Key: (%lld,%lld)\nPrivate Key: (%lld,%lld)\n", e,n,d,n);
    printf("Enter the message to be encrypted: ");
    scanf("%lld",&c);
    long long int k = 2;
    double CipherVal = pow(c,e);
    CipherVal = fmod(CipherVal, n);

    double DecipherVal = pow(CipherVal,d);
    DecipherVal = fmod(DecipherVal, n);
    printf("Original Message: %lld", c);
    printf("\nEncrypted Message: %lld", (long long int)CipherVal);
    printf("\nDecrypted Message: %lld", (long long int)DecipherVal);

    return 0;
}