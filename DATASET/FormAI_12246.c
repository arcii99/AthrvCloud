//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: relaxed
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<math.h>

#define MAX 1000

// gcd function
int gcd(int a, int b) {
    if(b == 0) return a;
    else return gcd(b, a%b);
}

// mod function
int Mod(int a, int b, int c) { 
    long long x=1,y=a; 

    while(b > 0) {
        if(b%2 == 1) {
            x=(x*y)%c;
        }

        y = (y*y)%c; 
        b /= 2; 
    }

    return x%c; 
} 

// miller rabin primality test
int Miller(long long p,int iteration) { 
    if(p<2) return 0; 
    if(p!=2 && p%2==0) return 0;

    long long s = p - 1;

    while(s%2==0) {
        s/=2;
    }

    int i;

    for(i = 0;i < iteration;i++) {
        long long a = rand()%(p-1)+1,temp=s;
        long long mod = Mod(a,temp,p);

        while(temp!=p-1 && mod!=1 && mod!=p-1) {
            mod = Mod(mod,mod,p);
            temp *= 2;
        }

        if(mod!=p-1 && temp%2==0) {
            return 0;
        }
    }

    return 1; 
}

// encrypt
long long encrypt(long long msg, long long e, long long n) {
    long long cipher = Mod(msg, e, n);
    return cipher;
}

// decrypt
long long decrypt(long long cipher, long long d, long long n) {
    long long msg = Mod(cipher, d, n);
    return msg;
}

int main() {
    // seed the random number generator
    srand(time(0));

    // generate two distinct prime numbers
    long long p = 293, q = 311;

    // calculate n and the totient
    long long n = p*q;
    long long totient = (p-1)*(q-1);

    // find the value of e
    long long e = 2;

    while(e < totient) {
        if(gcd(e, totient)==1) break;
        else e++;
    }

    // calculate d
    long long k = 2;
    long long d = (1 + (k*totient))/e;

    while(d > totient) {
        k++;
        d = (1 + (k*totient))/e;
    }

    // input a message to encrypt
    printf("Enter message to encrypt (must be integer less than n-1): ");
    long long msg;
    scanf("%lld", &msg);

    if(msg > n-1) {
        printf("Message is too big, please choose a smaller number.");
        return 0;
    }

    // encrypt the message and output the result
    long long cipher = encrypt(msg, e, n);
    printf("\nEncrypted message: %lld", cipher);

    // decrypt the message and output the result
    long long decrypted_msg = decrypt(cipher, d, n);
    printf("\nDecrypted message: %lld", decrypted_msg);

    return 0;
}