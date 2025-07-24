//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: happy
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

// Function to check if a number is Prime
int isPrime(int n) {
    int i;
    for(i=2;i<=sqrt(n);i++)
        if (n%i==0)
            return 0;
    return 1;
}

// Function to calculate GCD of two numbers
int gcd(int a, int b) {
    if(b==0)
        return a;
    return gcd(b,a%b);
}

// Function to generate Public Key
int generatePublicKey(int p, int q) {
    int n=p*q;
    int phi=(p-1)*(q-1);

    int e;
    for(e=2;e<phi;e++) {
        if(gcd(e,phi)==1 && isPrime(e))
            return e;
    }
    return -1;
}

// Function to generate Private Key
int generatePrivateKey(int p, int q, int e) {
    int n=p*q;
    int phi=(p-1)*(q-1);

    int i;
    for(i=1;;i++) {
        if((i*phi+1)%e==0)
            break;
    }
    return (i*phi+1)/e;
}

int main() {
    int p=17, q=19;
    int e=generatePublicKey(p,q);
    int d=generatePrivateKey(p,q,e);
    int n=p*q;

    printf("Public Key: (%d,%d)\n",n,e);
    printf("Private Key: (%d,%d)\n",n,d);
    
    int msg=233;
    printf("Original Message: %d\n",msg);
    
    // Encryption
    int C=pow(msg,e);
    C%=n;
    printf("Encrypted Message: %d\n",C);
    
    // Decryption
    int M=pow(C,d);
    M%=n;
    printf("Decrypted Message: %d\n",M);

    return 0;
}