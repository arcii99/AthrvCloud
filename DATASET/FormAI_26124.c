//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: creative
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

// function to check if a number is prime or not
int is_prime(int n){
    if(n <= 1) return 0;
    for(int i=2; i<=sqrt(n); i++){
        if(n%i == 0) return 0;
    }
    return 1;
}

// function to get a random prime number
int get_prime(){
    srand(time(NULL));  // seeding the random number generator
    int prime_list[] = {13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};  // list of prime numbers
    int n = sizeof(prime_list)/sizeof(int);
    int index = rand() % n;  // selecting a random index
    return prime_list[index];
}

// function to calculate power of a number
int power(int a, int b, int m){
    int res = 1;
    while(b){
        if(b & 1) res = (res * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return res;
}

// function to get public key
int get_public_key(int phi_n){
    int e = 2;
    while(e < phi_n){
        if(is_prime(e) && phi_n%e != 0) return e;
        e++;
    }
}

// function to get private key
int get_private_key(int e, int phi_n){
    int d = 1;
    while((d*e)%phi_n != 1 || d == e) d++;
    return d;
}

int main(){
    // generate public and private keys using a prime number
    int p = get_prime();
    int q = get_prime();
    while(q == p) q = get_prime();
    int n = p*q;
    int phi_n = (p-1)*(q-1);
    int e = get_public_key(phi_n);
    int d = get_private_key(e, phi_n);

    // print keys
    printf("Public Key: (%d, %d)\n", e, n);
    printf("Private Key: (%d, %d)\n\n", d, n);

    // encryption
    printf("Enter message to encrypt: ");
    char message[100];
    scanf("%[^\n]s", message);
    int encrypted_message[100];
    int len = strlen(message);
    printf("\nEncrypted Message: ");
    for(int i=0; i<len; i++){
        int m = message[i];
        int c = power(m, e, n);
        encrypted_message[i] = c;
        printf("%d ", c);
    }

    // decryption
    printf("\n\nDecrypted Message: ");
    for(int i=0; i<len; i++){
        int c = encrypted_message[i];
        int m = power(c, d, n);
        printf("%c", m);
    }
    printf("\n");

    return 0;
}