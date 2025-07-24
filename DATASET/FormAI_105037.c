//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// Function to check if a number is prime or not
int isPrime(int num){
    int i;
    for(i = 2; i < num; i++){
        if(num % i == 0){
            return 0;
        }
    }
    return 1;
}

// Function to generate a prime number
int generatePrime(){
    int num = rand() % 10000 + 1000;
    while(!isPrime(num)){
        num++;
    }
    return num;
}

// Function to calculate modular exponentiation
int modExp(int base, int exponent, int modulus){
    int result = 1;
    while(exponent > 0){
        if(exponent % 2 == 1){
            result = (result * base) % modulus;
        }
        base = (base * base) % modulus;
        exponent = exponent / 2;
    }
    return result;
}

// Function to generate a public key
void generatePublicKey(int *publicKey, int *privateKey, int p, int q){
    int n = p * q;
    int phi = (p - 1) * (q - 1);
    int e = 3 + rand() % (phi - 3);
    while(phi % e == 0 || isPrime(e) == 0){
        e++;
    }
    *publicKey = e;
    int k = 1;
    while(k > 0){
        *privateKey = (k * phi + 1) / e;
        if(modExp(e * (*privateKey), 1, phi) == 1){
            break;
        }
        k++;
    }
}

int main(){
    srand(time(NULL));
    int p = generatePrime();
    int q = generatePrime();
    int publicKey, privateKey;
    generatePublicKey(&publicKey, &privateKey, p, q);
    printf("The public key is: %d\n", publicKey);
    printf("The private key is: %d\n", privateKey);
    return 0;
}