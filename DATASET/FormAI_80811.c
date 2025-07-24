//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// Function to check if a number is prime or not
int is_prime(int n){
    int i;
    for(i=2; i<=sqrt(n); i++){
        if(n%i == 0){
            return 0;
        }
    }
    return 1;
}

// Function to find the greatest common divisor of a and b
int gcd(int a, int b){
    if(b == 0){
        return a;
    }
    else{
        return gcd(b, a%b);
    }
}

// Function to generate a random prime number
int generate_prime(){
    int prime = rand()%100 + 27;
    while(!is_prime(prime)){
        prime++;
    }
    return prime;
}

int main(){
    int p = generate_prime(); // generates a random prime number
    int q = generate_prime(); // generates another random prime number
    while(q == p){ // makes sure that q is not equal to p
        q = generate_prime();
    }

    int n = p*q; // calculates n
    int phi = (p-1)*(q-1); // calculates phi(n)
    int e = 3; // public key exponent
    while(gcd(e, phi) != 1){ // makes sure that e and phi(n) are coprime
        e++;
    }

    int d = 1; // private key exponent
    while((e*d)%phi != 1){ // calculates d that satisfies the condition
        d++;
    }

    printf("Public Key: (%d, %d)\n", e, n); // prints the public key
    printf("Private Key: (%d, %d)\n", d, n); // prints the private key

    return 0;
}