//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Function to find GCD of two numbers
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// Function to find multiplicative inverse of a number
int find_inverse(int phi, int e) {
    int i, inverse;
    for (i = 1; i < phi; i++) {
        if ((e * i) % phi == 1) {
            inverse = i;
            break;
        }
    }
    return inverse;
}

// Function to encrypt a message using the public key
int encrypt(int message, int e, int n) {
    int i, encrypted = 1;
    for (i = 0; i < e; i++) {
        encrypted = (encrypted * message) % n;
    }
    return encrypted;
}

// Function to decrypt a message using the private key
int decrypt(int message, int d, int n) {
    int i, decrypted = 1;
    for (i = 0; i < d; i++) {
        decrypted = (decrypted * message) % n;
    }
    return decrypted;
}

// Function to generate public and private keys
void generate_keys(int p, int q, int *e, int *d, int *n) {
    int phi = (p-1) * (q-1);
    *n = p * q;
    *e = rand() % (phi-2) + 2; // Choose e randomly between 1 < e < phi and gcd(e, phi) = 1
    while (gcd(*e, phi) != 1) {
        *e = rand() % (phi-2) + 2;
    }
    *d = find_inverse(phi, *e);
}

// Struct for passing multiple arguments to thread function
struct thread_arg {
    int id;
    int message;
    int e;
    int n;
};

// Thread function for encryption
void *thread_encrypt(void *arg) {
    struct thread_arg *t_arg = (struct thread_arg*) arg;
    int id = t_arg->id;
    int message = t_arg->message;
    int e = t_arg->e;
    int n = t_arg->n;
    printf("Thread %d is encrypting...\n", id);
    int encrypted = encrypt(message, e, n);
    printf("Thread %d encrypted the message: %d -> %d\n", id, message, encrypted);
    pthread_exit(NULL);
}

// Thread function for decryption
void *thread_decrypt(void *arg) {
    struct thread_arg *t_arg = (struct thread_arg*) arg;
    int id = t_arg->id;
    int message = t_arg->message;
    int d = t_arg->e;
    int n = t_arg->n;
    printf("Thread %d is decrypting...\n", id);
    int decrypted = decrypt(message, d, n);
    printf("Thread %d decrypted the message: %d -> %d\n", id, message, decrypted);
    pthread_exit(NULL);
}

// Main function
int main() {
    int p = 61;
    int q = 53;
    int e, d, n;
    generate_keys(p, q, &e, &d, &n);

    int message = 123;
    struct thread_arg t_arg1 = {1, message, e, n};
    struct thread_arg t_arg2 = {2, message, d, n};

    pthread_t tid1, tid2;
    pthread_create(&tid1, NULL, thread_encrypt, &t_arg1);
    pthread_create(&tid2, NULL, thread_decrypt, &t_arg2);

    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);

    return 0;
}