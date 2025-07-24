//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: all-encompassing
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<stdbool.h>

// Function to determine if a number is prime or not
bool isPrime(int n){
    if(n<=1){
        return false;
    }
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0){
            return false;
        }
    }
    return true;
}

// Function to calculate greatest common divisor
int gcd(int a,int b){
    if(b==0){
        return a;
    }
    return gcd(b,a%b);
}

// Function to encrypt the message using rsa algorithm
int* rsa_encrypt(int message,int e, int n){
    int *cipher = malloc(2*sizeof(int));
    cipher[0] = (int)(pow(message,e))%n;
    cipher[1] = n;
    return cipher;
}

// Function to decrypt the cipher text using rsa algorithm
int rsa_decrypt(int* cipher,int d){
    int c = cipher[0];
    int n = cipher[1];
    return (int)(pow(c,d))%n;
}

int main(){

    // Generating large prime numbers
    int p,q,n,phi,e,d;
    do{
        p = 499;
        while(!isPrime(p)){
            p++;
        }
        q = 487;
        while(!isPrime(q)){
            q--;
        }
        n = p*q;
        phi = (p-1)*(q-1);
    }while(gcd(phi,65537)!=1);

    e = 65537;

    // Calculating private key
    d=1;
    while(d*e%phi!=1){
        d++;
    }

    // Encrypting and Decrypting message
    int message = 1234;
    int *cipher = rsa_encrypt(message,e,n);
    int decrypted = rsa_decrypt(cipher,d);

    printf("Original Message: %d\n",message);
    printf("Encrypted Message: %d\n",cipher[0]);
    printf("Decrypted Message: %d\n",decrypted);

    free(cipher);

    return 0;
}