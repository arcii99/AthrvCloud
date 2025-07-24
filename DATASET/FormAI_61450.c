//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: Romeo and Juliet
/* Romeo and Juliet Public-Key Algorithm Implementation */

// Shall I compare thee to a summer's day?
// Thou art more secure and cipher'd: code away!
// Let's create keys for our love to stay
// A public and a private, to use as we may

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h> 

// Function to check if a number is prime or not
int isPrime(int num) {
    int i;
    for(i=2; i<=sqrt(num); i++) {
        if(num%i == 0) {
            return 0;
        }
    }
    return 1;
}

// Function to find the greatest common divisor of two numbers
int gcd(int a, int b) {
    int temp;
    while(b != 0) {
        temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function to generate prime numbers for keys
int generate_prime() {
    int num;
    do {
        srand(time(NULL));
        num = rand() % 100 + 2; // Generate random numbers between 2-100
    } while(!isPrime(num));
    return num;
}

int main(){
    int p = generate_prime();
    int q = generate_prime();
    int n = p * q;
    int phi = (p-1) * (q-1);

    // Let's find a number 'e' such that 1 < e < phi and gcd(phi, e) = 1
    int e = 2;
    while(e < phi) {
        if(gcd(e, phi) == 1) {
            break;
        }
        e++;
    }

    // Let's find d such that d*e = 1 mod phi
    int k = 2;
    int d;
    while(1) {
        d = (1 + k*phi) / e;
        if((d*e) % phi == 1) {
            break;
        }
        k++;
    }

    printf("Public Key (n, e) = (%d, %d)\n", n, e);
    printf("Private Key (n, d) = (%d, %d)\n", n, d);

    // Let's encrypt a message 'M'
    int M = 50;
    int encrypted_num = fmod(pow(M, e), n);
    printf("Encrypted Message = %d\n", encrypted_num);

    // Let's decrypt the encrypted message
    int decrypted_num = fmod(pow(encrypted_num, d), n);
    printf("Decrypted Message = %d\n", decrypted_num);

    return 0;
}