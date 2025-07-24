//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: visionary
/*
    Visionary Public-Key Algorithm implementation
    Created by [Your Name]
*/

#include <stdio.h>
#include <stdlib.h>

#define PRIME_NUMBER 23
#define GENERATOR 5

// Function to compute modular exponentiation
long long int power_modulo(long long int base, long long int exponent, long long int modulo){
    long long int result = 1;
    while(exponent>0){
        if(exponent%2==1){
            result = (result*base)%modulo;
        }
        base = (base*base)%modulo;
        exponent/=2;
    }
    return result%modulo;
}

// Function to generate a private key
long long int generate_private_key(){
    // Generating a random number between 2 and PRIME_NUMBER-2
    long long int private_key = (rand()%(PRIME_NUMBER-2))+2;
    return private_key;
}

// Function to compute the public key
long long int compute_public_key(long long int private_key){
    long long int public_key = power_modulo(GENERATOR, private_key, PRIME_NUMBER);
    return public_key;
}

// Function to compute the shared key
long long int compute_shared_key(long long int own_private_key, long long int other_public_key){
    long long int shared_key = power_modulo(other_public_key, own_private_key, PRIME_NUMBER);
    return shared_key;
}

int main(){
    // Generating Alice's and Bob's private keys
    long long int alice_private_key = generate_private_key();
    long long int bob_private_key = generate_private_key();

    // Computing Alice's and Bob's public keys
    long long int alice_public_key = compute_public_key(alice_private_key);
    long long int bob_public_key = compute_public_key(bob_private_key);

    // Computing Alice's and Bob's shared keys
    long long int alice_shared_key = compute_shared_key(alice_private_key, bob_public_key);
    long long int bob_shared_key = compute_shared_key(bob_private_key, alice_public_key);

    // Ensuring that both the shared keys are equal
    if(alice_shared_key == bob_shared_key){
        printf("Shared Key: %lld\n", alice_shared_key);
    } else{
        printf("Error in computing shared keys.\n");
    }

    return 0;
}