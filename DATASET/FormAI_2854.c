//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int is_prime(int n) {
    if (n <= 1) return 0;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

int gcd(int n1, int n2) {
    if (n1 == 0) return n2;
    return gcd(n2 % n1, n1);
}

int coprime(int n) {
    int phi = 1;
    for (int i = 2; i < n; i++) {
        if (gcd(i, n) == 1) phi++;
    }
    return phi;
}

int find_prime(int n) {
    int prime = n + 1;
    while (!is_prime(prime)) prime++;
    return prime;
}

int fast_expo(int base, int power, int mod) {
    int result = 1 % mod;
    while (power > 0) {
        if (power & 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        power >>= 1;
    }
    return result;
}

int multiplicative_inverse(int n, int mod) {
    for (int i = 1; i < mod; i++) {
        if ((n * i) % mod == 1) return i;
    }
    return -1;
}

void generate_key_pair(int p, int q, int *public_key, int *private_key) {
    int n = p * q;
    int phi = (p-1) * (q-1);
    int e = 3;
    while (gcd(e, phi) != 1) e += 2;
    int d = multiplicative_inverse(e, phi);
    *public_key = e;
    *private_key = d;
}

void encrypt(int *encrypted_message, int *message, int message_len, int public_key, int n) {
    for (int i = 0; i < message_len; i++) {
        encrypted_message[i] = fast_expo(message[i], public_key, n);        
    }
}

void decrypt(int *decrypted_message, int *encrypted_message, int message_len, int private_key, int n) {
    for (int i = 0; i < message_len; i++) {
        decrypted_message[i] = fast_expo(encrypted_message[i], private_key, n);
    }
}

void print_array(int *arr, int arr_size) {
    printf("[");
    for (int i = 0; i < arr_size-1; i++) {
        printf("%d, ", arr[i]);
    }
    printf("%d]", arr[arr_size-1]);
}

int main() {
    int p = 11;
    int q = 13;
    int public_key, private_key;
    generate_key_pair(p, q, &public_key, &private_key);
    printf("Public key: %d\n", public_key);
    printf("Private key: %d\n", private_key);
    int message[] = {8, 2, 9};
    int message_len = sizeof(message)/sizeof(message[0]);
    printf("Original message: ");
    print_array(message, message_len);
    int n = p * q;
    int encrypted_message[message_len];
    encrypt(encrypted_message, message, message_len, public_key, n);
    printf("\nEncrypted message: ");
    print_array(encrypted_message, message_len);
    int decrypted_message[message_len];
    decrypt(decrypted_message, encrypted_message, message_len, private_key, n);
    printf("\nDecrypted message: ");
    print_array(decrypted_message, message_len);
    return 0;
}