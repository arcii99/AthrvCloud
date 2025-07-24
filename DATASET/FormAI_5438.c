//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

int mod_inverse(int a, int n) {
    int t, newt, r, newr, quotient, temp;
    t = 0;
    newt = 1;
    r = n;
    newr = a;
    while (newr != 0) {
        quotient = r / newr;
        temp = t;
        t = newt;
        newt = temp - quotient * newt;
        temp = r;
        r = newr;
        newr = temp - quotient * newr;
    }
    if (r > 1) {
        return -1;
    }
    if (t < 0) {
        t = t + n;
    }
    return t;
}

int is_prime(int n) {
    int i;
    if (n == 0 || n == 1) {
        return 0;
    }
    for (i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

int generate_prime() {
    int prime, i;
    int is_prime_value;
    srand(time(0));
    while (1) {
        prime = rand() % 100 + 100;
        is_prime_value = is_prime(prime);
        if (is_prime_value == 1) {
            return prime;
        }
    }
}

int get_keys(int *public_key, int *private_key) {
    int p, q, n, phi, e, d;
    p = generate_prime();
    q = generate_prime();
    n = p * q;
    phi = (p - 1) * (q - 1);
    e = 2;
    while (e < phi) {
        if (gcd(e, phi) == 1) {
            break;
        }
        e++;
    }
    d = mod_inverse(e, phi);
    public_key[0] = e;
    public_key[1] = n;
    private_key[0] = d;
    private_key[1] = n;
}

int encrypt(char *plain_text, int *public_key, int *cipher_text) {
    int i, n, e, c;
    n = public_key[1];
    e = public_key[0];
    for (i = 0; plain_text[i] != '\0'; i++) {
        c = plain_text[i];
        if (c >= 65 && c <= 90) {
            c = c - 65;
            c = c + 1;
        } else if (c >= 97 && c <= 122) {
            c = c - 97;
            c = c + 27;
        } else if (c >= 48 && c <= 57) {
            c = c - 48;
            c = c + 53;
        } else if (c == 32) {
            c = 63;
        } else {
            printf("Invalid character in plaintext!");
            return -1;
        }
        c = pow(c, e);
        cipher_text[i] = c % n;
    }
    return i;
}

int decrypt(int *cipher_text, int cipher_text_len, int *private_key, char *plain_text) {
    int i, n, d, c;
    n = private_key[1];
    d = private_key[0];
    for (i = 0; i < cipher_text_len; i++) {
        c = cipher_text[i];
        c = pow(c, d);
        c = c % n;
        if (c >= 1 && c <= 26) {
            c = c - 1;
            c = c + 65;
        } else if (c >= 28 && c <= 53) {
            c = c - 27;
            c = c + 97;
        } else if (c >= 54 && c <= 62) {
            c = c - 53;
            c = c + 48;
        } else if (c == 63) {
            c = 32;
        } else {
            printf("Invalid character in ciphertext!");
            return -1;
        }
        plain_text[i] = c;
    }
    plain_text[i] = '\0';
    return i;
}

int main() {
    int public_key[2], private_key[2], cipher_text[100];
    char plain_text[100], decrypted_text[100];
    get_keys(public_key, private_key);
    printf("Enter a message to encrypt (max length 100): ");
    fgets(plain_text, sizeof(plain_text), stdin);
    int i = encrypt(plain_text, public_key, cipher_text);
    if (i != -1) {
        printf("Encrypted message: ");
        int j;
        for (j = 0; j < i; j++) {
            printf("%d ", cipher_text[j]);
        }
        printf("\n");
        int k = decrypt(cipher_text, i, private_key, decrypted_text);
        if (k != -1) {
            printf("Decrypted message: %s\n", decrypted_text);
        }
    }       
    return 0;
}