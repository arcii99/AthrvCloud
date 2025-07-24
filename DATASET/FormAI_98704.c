//FormAI DATASET v1.0 Category: modern Encryption ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

typedef struct {
    int d;
    int n;
} PrivateKey;

typedef struct {
    int e;
    int n;
} PublicKey;

int is_prime(int num) {
    if (num < 2) {
        return 0;
    }
    int i;
    for (i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int mod_exp(int base, int exp, int mod) {
    int result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

int generate_prime() {
    int num = rand() % 1000 + 1000;
    while (!is_prime(num)) {
        num++;
    }
    return num;
}

int generate_coprime(int phi) {
    int e = rand() % phi;
    while (gcd(e, phi) != 1) {
        e++;
    }
    return e;
}

PublicKey generate_public_key() {
    PublicKey public_key;
    int p = generate_prime();
    int q = generate_prime();
    int n = p * q;
    int phi = (p - 1) * (q - 1);
    int e = generate_coprime(phi);
    public_key.e = e;
    public_key.n = n;
    return public_key;
}

PrivateKey generate_private_key(PublicKey public_key) {
    PrivateKey private_key;
    int phi = ((public_key.n % public_key.e) - 1) * ((public_key.n / public_key.e) - 1);
    int d = 1;
    while ((d * public_key.e) % phi != 1) {
        d++;
    }
    private_key.d = d;
    private_key.n = public_key.n;
    return private_key;
}

int* encode_message(char* message, int message_length) {
    int* message_array = malloc(message_length * sizeof(int));
    int i;
    for (i = 0; i < message_length; i++) {
        message_array[i] = (int) message[i];
    }
    return message_array;
}

char* decode_message(int* message_array, int message_length) {
    char* message = malloc(message_length * sizeof(char));
    int i;
    for (i = 0; i < message_length; i++) {
        message[i] = (char) message_array[i];
    }
    return message;
}

int* encrypt_message(int* message_array, int message_length, PublicKey public_key) {
    int* encrypted_message_array = malloc(message_length * sizeof(int));
    int i;
    for (i = 0; i < message_length; i++) {
        encrypted_message_array[i] = mod_exp(message_array[i], public_key.e, public_key.n);
    }
    return encrypted_message_array;
}

int* decrypt_message(int* message_array, int message_length, PrivateKey private_key) {
    int* decrypted_message_array = malloc(message_length * sizeof(int));
    int i;
    for (i = 0; i < message_length; i++) {
        decrypted_message_array[i] = mod_exp(message_array[i], private_key.d, private_key.n);
    }
    return decrypted_message_array;
}

void print_array(int* array, int array_length) {
    int i;
    for (i = 0; i < array_length; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void print_message(char* message, int message_length) {
    int i;
    for (i = 0; i < message_length; i++) {
        printf("%c", message[i]);
    }
    printf("\n");
}

int main() {
    srand(time(NULL));
    char* message = "hello world";
    int message_length = strlen(message);
    int* message_array = encode_message(message, message_length);
    PublicKey public_key = generate_public_key();
    PrivateKey private_key = generate_private_key(public_key);
    int* encrypted_message_array = encrypt_message(message_array, message_length, public_key);
    int* decrypted_message_array = decrypt_message(encrypted_message_array, message_length, private_key);
    char* decrypted_message = decode_message(decrypted_message_array, message_length);
    printf("Original message: ");
    print_message(message, message_length);
    printf("Encoded message: ");
    print_array(message_array, message_length);
    printf("Encrypted message: ");
    print_array(encrypted_message_array, message_length);
    printf("Decrypted message: ");
    print_array(decrypted_message_array, message_length);
    printf("Decoded message: ");
    print_message(decrypted_message, message_length);
    free(message_array);
    free(encrypted_message_array);
    free(decrypted_message_array);
    free(decrypted_message);
    return 0;
}