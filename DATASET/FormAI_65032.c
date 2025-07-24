//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: happy
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

//Function to check if a number is prime
bool is_prime(int number){
    for(int i=2; i<number; i++){
        if(number%i == 0){
            return false;
        }
    }
    return true;
}

//Function to calculate the greatest common divisor
int gcd(int a, int b){
    int temp = 0;
    while(b != 0){
        temp = b;
        b = a%b;
        a = temp;
    }
    return a;
}

//Function to generate random number between min and max
int generate_random_number(int min, int max){
    return (rand() % (max - min + 1)) + min;
}

//Function to generate public and private key
void generate_key_pairs(int p, int q, int* public_key, int* private_key){
    int n = p*q;
    int phi = (p-1)*(q-1);
    int e = 2;
    while(e < phi){
        if(gcd(e,phi) == 1){
            break;
        }
        e++;
    }
    int d = 1/e % phi;
    public_key[0] = e;
    public_key[1] = n;
    private_key[0] = d;
    private_key[1] = n;
}

//Function to encrypt a message
int encrypt(int message, int* public_key){
    int e = public_key[0];
    int n = public_key[1];
    int cipher_text = pow(message, e);
    cipher_text = cipher_text % n;
    return cipher_text;
}

//Function to decrypt a message
int decrypt(int cipher_text, int* private_key){
    int d = private_key[0];
    int n = private_key[1];
    int message = pow(cipher_text, d);
    message = message % n;
    return message;
}

int main(){
    //Generate 2 random prime numbers
    int p = generate_random_number(30, 50);
    int q = generate_random_number(50, 70);
    
    while(!is_prime(p)){
        p = generate_random_number(30, 50);
    }
    
    while(!is_prime(q)){
        q = generate_random_number(50, 70);
    }
    
    //Generate public and private key pairs
    int public_key[2], private_key[2];
    generate_key_pairs(p, q, public_key, private_key);
    
    //Print public and private key pairs
    printf("Public key: (%d,%d)\n", public_key[0], public_key[1]);
    printf("Private key: (%d,%d)\n", private_key[0], private_key[1]);
    
    //Encrypt a message and decrypt it
    int message = 123;
    int cipher_text = encrypt(message, public_key);
    int decrypted_message = decrypt(cipher_text, private_key);
    
    //Print message, cipher text and decrypted message
    printf("Original Message: %d\n", message);
    printf("Cipher Text: %d\n", cipher_text);
    printf("Decrypted Message: %d\n", decrypted_message);
    
    return 0;
}