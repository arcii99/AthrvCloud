//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: all-encompassing
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#define MAX 1000
#define PRIME 257
// Note: This implementation has a few limitations, it can only encrypt 3 letters at a time and the key size is limited to 3 digits.

int gcd(int a, int b){ // Utility function to find GCD of given numbers
    if(a==0)
        return b;
    return gcd(b%a, a);
}

int modular_pow(int base, int exponent, int modulus){ // Modular exponentiation implementation
    int result = 1;
    while(exponent > 0){
        if(exponent%2==1)
            result = (result*base)%modulus;
        base = (base*base)%modulus;
        exponent/=2;
    }
    return result;
}

int is_prime(int num){ // Determines whether the given number is prime or not
    int i;
    for(i=2;i<=sqrt(num);i++){
        if(num%i==0)
            return 0;
    }
    return 1;
}

void encode(char *plaintext, int n, int e, char *ciphertext){ // Function to encode given plaintext using RSA algorithm
    int i, j, len = strlen(plaintext), temp;
    for(i=0;i<len;i+=3){
        temp = 0;
        for(j=0;j<3;j++){
            if(i+j<len)
                temp = temp*100 + (int)plaintext[i+j];
            else
                temp *= 100;
        }
        int encoded = modular_pow(temp, e, n);
        sprintf(&ciphertext[i], "%03d", encoded);
    }
}

void decode(char *ciphertext, int n, int d, char *decrypted){ // Function to decode given ciphertext using RSA algorithm
    int i, j, len = strlen(ciphertext), temp;
    for(i=0;i<len;i+=3){
        temp = 0;
        for(j=0;j<3;j++){
            if(i+j<len)
                temp = temp*10 + (int)ciphertext[i+j] - 48;
            else
                temp *= 10;
        }
        int decoded = modular_pow(temp, d, n);
        for(j=2;j>=0;j--){
            decrypted[i+j] = decoded%100;
            decoded /= 100;
        }
    }
}

int main(){
    int p, q, phi, n, e, d;
    char plaintext[MAX];
    char ciphertext[MAX];
    char decrypted[MAX];
    srand(time(NULL)); // Initialize the random seed
    // Step 1: Select two prime numbers
    do{
        p = rand()%500 + 500;
    }while(!is_prime(p));
    do{
        q = rand()%500 + 1000;
    }while(!is_prime(q));
    // Step 2: Calculate n and phi
    n = p*q;
    phi = (p-1)*(q-1);
    // Step 3: Find e
    do{
        e = rand()%phi + 1;
    }while(gcd(e, phi) != 1);
    // Step 4: Find d
    d = modular_pow(e, phi-1, phi);
    gets(plaintext); // Take the plaintext as input
    encode(plaintext, n, e, ciphertext); // Encrypt the plaintext
    printf("\nThe encrypted message is: %s", ciphertext); // Print the ciphertext
    decode(ciphertext, n, d, decrypted); // Decrypt the ciphertext
    printf("\nThe decrypted message is: %s", decrypted); // Print the decrypted text
    return 0;
}