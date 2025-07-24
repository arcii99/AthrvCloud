//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: realistic
#include<stdio.h>
#include<math.h>

// Function to check if a number is prime or not
int is_prime(int num){

    if(num == 2 || num == 3){
        return 1;
    }
    if(num == 1 || num % 2 == 0){
        return 0;
    }

    int limit = sqrt(num);

    for(int i = 3; i <= limit; i += 2){
        if(num % i == 0){
            return 0;
        }
    }

    return 1;
}

// Function to find the gcd of two numbers
int gcd(int a, int b){

    int temp;
    while(b > 0){
        temp = b;
        b = a % b;
        a = temp;
    }

    return a;
}

// Function to find the modular inverse of a number
int mod_inverse(int a, int m){

    a = a % m;

    for(int i = 1; i < m; i++){
        if((a * i) % m == 1){
            return i;
        }
    }

    return -1;

}

int main(){

    int p, q, n, phi, e, d, plain_text, cipher_text, decrypted_text;

    // Get the two prime numbers
    printf("Enter the first prime number: ");
    scanf("%d", &p);

    printf("Enter the second prime number: ");
    scanf("%d", &q);

    // Check if p and q are prime
    if(is_prime(p) == 0 || is_prime(q) == 0){
        printf("Error: p and q must be prime\n");
        return 0;
    }

    // Calculate n and phi
    n = p * q;
    phi = (p-1) * (q-1);

    // Find e such that e is coprime to phi and 1 < e < phi
    for(int i = 2; i < phi; i++){
        if(gcd(i, phi) == 1){
            e = i;
            break;
        }
    }

    // Find the modular inverse of e
    d = mod_inverse(e, phi);

    // Get the plain text from the user
    printf("Enter the plain text (integer): ");
    scanf("%d", &plain_text);

    // Encrypt the plain text
    cipher_text = pow(plain_text, e);
    cipher_text = cipher_text % n;

    printf("Cipher text: %d\n", cipher_text);

    // Decrypt the cipher text
    decrypted_text = pow(cipher_text, d);
    decrypted_text = decrypted_text % n;

    printf("Decrypted text: %d\n", decrypted_text);

    return 0;
}