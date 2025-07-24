//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: high level of detail
/* This is a simple implementation of RSA algorithm in C.
   RSA is a public key cryptographic algorithm used widely for secure data transmission.
   This program allows the user to generate public and private RSA keys, encrypt and decrypt a message using those keys.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define MAX 1000

//GCD function to find the greatest common divisor
int gcd(int a, int b){
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

//RSA key generation function
void generate_keys(int p, int q, int *public_key, int *private_key){
    //Calculate n
    int n = p * q;
 
    //Compute euler totient function
    int phi = (p-1) * (q-1);
    
    int e; //public key exponent
    do {
        //Choose random e such that e is smaller than phi and co-prime to phi
        srand(time(0));
        e = rand() % phi + 1;
    } while (gcd(phi, e) != 1);
    
    *public_key = e;
    
    //Compute the modular inverse of e modulo phi as private key
    int d = 1;
    while ((d * e) % phi != 1){
        d++;
    }

    *private_key = d;
        
    //Print the generated public and private keys
    printf("\nPublic Key (e, n): (%d, %d)\n", e, n);
    printf("Private Key (d, n): (%d, %d)\n\n", d, n);
}
 
//Function to encrypt plaintext using RSA algorithm and public key
void encrypt(int *public_key, char* plaintext, int* encrypted){
    int e = public_key[0], n = public_key[1];
    
    int i = 0; 
    while (plaintext[i] != '\0'){
        long long int pt = plaintext[i]; // convert character to ASCII code
        long long int ct = (long long int)pow(pt, e) % n; // encryption formula
        encrypted[i] = ct;
        i++;
    }
    encrypted[i] = -1; //end marker
    printf("Encrypted message: ");
    for (int j=0; encrypted[j] != -1; j++){
        printf("%d ", encrypted[j]);
    } 
    printf("\n");  
}

//Function to decrypt ciphertext using RSA algorithm and private key
void decrypt(int *private_key, int* encrypted, char* decrypted){
    int d = private_key[0], n = private_key[1];
    
    int i = 0;
    while (encrypted[i] != -1){
        long long int ct = encrypted[i]; //retrieving encrypted ASCII code
        long long int pt = (long long int)pow(ct, d) % n; // decryption formula
        decrypted[i] = (char)pt; //convert ASCII code back to character
        i++;
    }
    decrypted[i] = '\0'; // end marker
    printf("Decrypted message: %s\n\n", decrypted);
}

int main(){
    int p, q; //two prime numbers for key generation
    int public_key[2], private_key[2]; //public and private key pair
    char plaintext[MAX], decrypted[MAX]; //plaintext message and decrypted message
    int encrypted[MAX]; //encrypted message as integers
    
    //prompt user to enter two prime numbers for RSA key generation
    printf("Enter two prime numbers for RSA key generation: ");
    scanf("%d %d", &p, &q);

    //generate RSA public and private keys
    generate_keys(p, q, public_key, private_key);
    
    //prompt user to enter plaintext message
    printf("Enter plaintext message: ");
    scanf(" %[^\n]s", plaintext);
    
    //encrypt plaintext message using RSA public key
    encrypt(public_key, plaintext, encrypted);
    
    //decrypt ciphertext message using RSA private key
    decrypt(private_key, encrypted, decrypted);
    
    return 0;
}