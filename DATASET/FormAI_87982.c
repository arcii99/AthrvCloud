//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

/* FUNCTION DECLARATIONS */
int gcd(int a, int b);
int choose_random_prime();
int choose_e(int phi_n);
int modular_inverse(int e, int phi_n);
int pow_modulo(int base, int exp, int modulus);
char* encrypt_message(char* message, int n, int e);
char* decrypt_message(char* message, int n, int d);

/* MAIN FUNCTION */
int main()
{
    /* Random seed */
    srand(time(NULL));

    /* Choose two random primes */
    int p = choose_random_prime();
    int q = choose_random_prime();

    /* Calculate n and phi(n) */
    int n = p*q;
    int phi_n = (p-1)*(q-1);

    /* Choose an encryption key (public key) */
    int e = choose_e(phi_n);

    /* Calculate the corresponding decryption key (private key) */
    int d = modular_inverse(e, phi_n);

    /* Print keys */
    printf("Public key (n,e) = (%d,%d)\n", n, e);
    printf("Private key (n,d) = (%d,%d)\n", n, d);

    /* Message to encrypt */
    char message[] = "The King's treasure is hidden in the castle";

    /* Encrypt message */
    char* encrypted_message = encrypt_message(message, n, e);
    printf("\nEncrypted message: %s\n", encrypted_message);

    /* Decrypt message */
    char* decrypted_message = decrypt_message(encrypted_message, n, d);
    printf("\nDecrypted message: %s\n", decrypted_message);

    return 0;
}

/* FUNCTION DEFINITIONS */

/* Returns the greatest common divisor of a and b */
int gcd(int a, int b)
{
    int remainder;

    while (b != 0)
    {
        remainder = a % b;
        a = b;
        b = remainder;
    }

    return a;
}

/* Chooses a random prime number between 10 and 100 */
int choose_random_prime()
{
    int is_prime;
    int number;
    do {
        number = rand() % 91 + 10;
        is_prime = 1;
        for (int i = 2; i < number; i++)
        {
            if (number % i == 0)
            {
                is_prime = 0;
                break;
            }
        }
    } while (is_prime != 1);

        return number;
}

/* Chooses a random integer e such that 1 < e < phi(n) and gcd(e,phi(n)) = 1 */
int choose_e(int phi_n)
{
    int e;
    int is_valid;
    do {
        e = rand() % (phi_n - 2) + 2; // 2 <= e <= phi_n - 1
        is_valid = gcd(e, phi_n) == 1 ? 1 : 0;
    } while (is_valid != 1);

        return e;
}

/* Calculates the modular inverse of e modulo phi(n) */
int modular_inverse(int e, int phi_n)
{
    int x1 = 1, x2 = 0, y1 = 0, y2 = 1;
    int q, r, x, y;

    while (phi_n != 0) {
        q = e / phi_n;
        r = e % phi_n;

        x = x2 - q*x1;
        y = y2 - q*y1;

        e = phi_n;
        phi_n = r;
        x2 = x1;
        x1 = x;
        y2 = y1;
        y1 = y;
    }

    return x2;
}

/* Calculates base^exp mod modulus */
int pow_modulo(int base, int exp, int modulus)
{
    int result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result*base) % modulus;
        }
        base = (base*base) % modulus;
        exp = exp / 2;
    }
    return result;
}

/* Encrypts a message using the RSA encryption algorithm */
char* encrypt_message(char* message, int n, int e)
{
    char* encrypted_message = (char*) malloc(strlen(message) + 1);

    for (int i = 0; i < strlen(message); i++)
    {
        int ascii_code = (int) message[i];
        int encrypted_code = pow_modulo(ascii_code, e, n);
        encrypted_message[i] = (char) encrypted_code;
    }

    encrypted_message[strlen(message)] = '\0';

    return encrypted_message;
}

/* Decrypts a message using the RSA encryption algorithm */
char* decrypt_message(char* message, int n, int d)
{
    char* decrypted_message = (char*) malloc(strlen(message) + 1);

    for (int i = 0; i < strlen(message); i++)
    {
        int encrypted_code = (int) message[i];
        int decrypted_code = pow_modulo(encrypted_code, d, n);
        decrypted_message[i] = (char) decrypted_code;
    }

    decrypted_message[strlen(message)] = '\0';

    return decrypted_message;
}