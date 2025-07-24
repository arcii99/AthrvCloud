//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: rigorous
#include<stdio.h>
#include<math.h>

/*Function to calculate GCD of two numbers*/
int gcd(int a, int b){
    if(b == 0){
        return a;
    }
    return gcd(b, a % b);
}

/*Function to calculate power of a number*/
int power(int a, int b, int m){
    int res = 1;
    while(b > 0){
        if(b & 1){
            res = (res * a) % m;
        }
        a = (a * a) % m;
        b >>= 1;
    }
    return res;
}

/*Function to generate prime numbers*/
int generate_prime_number(int n){
    int i, j, flag;
    for(i = n; i < n + 100; i++){
        flag = 1;
        for(j = 2; j <= sqrt(i); j++){
            if(i % j == 0){
                flag = 0;
                break;
            }
        }
        if(flag){
            return i;
        }
    }
    return -1;
}

/*Function to find primitive root of a prime number*/
int find_primitive_root(int prime_number){
    int phi = prime_number - 1;
    int i;
    for(i = 2; i <= sqrt(phi); i++){
        if(phi % i == 0){
            if(gcd(i, phi/i) == 1){
                return i;
            }
        }
    }
    return -1;
}

/*Function to calculate public key*/
int calculate_public_key(int primitive_root, int private_key, int prime_number){
    return power(primitive_root, private_key, prime_number);
}

/*Function to calculate secret key*/
int calculate_secret_key(int public_key, int private_key, int prime_number){
    return power(public_key, private_key, prime_number);
}

int main(){
    int prime_number = generate_prime_number(1000000000); /*Generate 10 digit prime number*/
    int primitive_root = find_primitive_root(prime_number);
    int private_key_A, private_key_B, public_key_A, public_key_B, secret_key_A, secret_key_B;
    
    /*Input private keys of A and B*/
    printf("Enter private key of A: ");
    scanf("%d", &private_key_A);
    printf("Enter private key of B: ");
    scanf("%d", &private_key_B);
    
    /*Calculate public keys of A and B*/
    public_key_A = calculate_public_key(primitive_root, private_key_A, prime_number);
    public_key_B = calculate_public_key(primitive_root, private_key_B, prime_number);
    
    /*Print public keys of A and B*/
    printf("Public key of A: %d\n", public_key_A);
    printf("Public key of B: %d\n", public_key_B);
    
    /*Calculate secret keys of A and B*/
    secret_key_A = calculate_secret_key(public_key_B, private_key_A, prime_number);
    secret_key_B = calculate_secret_key(public_key_A, private_key_B, prime_number);
    
    /*Print secret keys of A and B*/
    printf("Secret key of A: %d\n", secret_key_A);
    printf("Secret key of B: %d\n", secret_key_B);
    
    return 0;
}