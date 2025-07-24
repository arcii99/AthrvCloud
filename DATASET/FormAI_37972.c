//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Generating random prime numbers
int generate_prime(){
    int num = rand() % 100 + 1; // Generating random number between 1 and 100
    
    // Checking if number is prime
    for(int i=2; i<=sqrt(num); i++){
        if(num % i == 0) // If number is divisible by any other number apart from itself and 1 
            return generate_prime(); // Recursively generating new number
    }
    return num; // If number is prime
}

// Finding gcd of two numbers
int gcd(int a, int b){
    if(b == 0)
        return a;
    else
        return gcd(b, a%b);
}

// Generating keys
void generate_keys(int p, int q, int *pub_key, int *priv_key){
    int n = p * q; // Finding the value of n
    int totient_n = (p-1) * (q-1); // Finding the value of totient n
    
    // Finding a number e which is co-prime to totient_n
    int e = rand() % totient_n + 1; 
    while(gcd(e, totient_n) != 1)
        e = rand() % totient_n + 1;
    *pub_key = e; // Assigning the value of e as public key
    
    // Finding a number d such that e*d mod totient_n = 1
    int k = 1;
    while(1){
        int temp = (k * totient_n + 1) % e;
        if(temp == 0){
            *priv_key = (k * totient_n + 1) / e;
            break;
        }
        k++;
    }
}

// Encryption
int encrypt(int message, int pub_key, int n){
    int encrypted_msg = fmod(pow(message, pub_key), n); // Applying the formula for encryption
    return encrypted_msg;
}

// Decryption
int decrypt(int encrypted_msg, int priv_key, int n){
    int decrypted_msg = fmod(pow(encrypted_msg, priv_key), n); // Applying the formula for decryption
    return decrypted_msg;
}

int main(){
    int p = generate_prime(); // Generating random prime number p
    int q = generate_prime(); // Generating random prime number q
    int pub_key, priv_key;
    generate_keys(p, q, &pub_key, &priv_key); // Generating public and private keys
    int n = p * q; // Finding the value of n
    
    // Taking input from user
    int message;
    printf("Enter the message to be encrypted: ");
    scanf("%d", &message);
    printf("Encrypting message...\n");
    int encrypted_msg = encrypt(message, pub_key, n); // Encrypting the message
    printf("Encrypted message: %d\n", encrypted_msg);
    
    printf("Decrypting message...\n");
    int decrypted_msg = decrypt(encrypted_msg, priv_key, n); // Decrypting the message
    printf("Decrypted message: %d\n", decrypted_msg);
    
    return 0;
}