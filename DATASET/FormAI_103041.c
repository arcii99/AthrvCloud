//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define PUBLIC_KEY 65537
#define MAX_INT 2147483647

// Function to calculate greatest common divisor
int gcd(int a, int b)
{
    if (b == 0)
        return a;

    return gcd(b, a % b);
}

// Function to generate random prime number
int generate_random_prime()
{
    int prime;
    int is_prime;

    do
    {
        is_prime = 1;
        prime = rand() % MAX_INT;

        for (int i = 2; i <= sqrt(prime); i++)
        {
            if (prime % i == 0)
            {
                is_prime = 0;
                break;
            }
        }
    } while(!is_prime);

    return prime;
}

// Function to generate keys for RSA encryption and decryption
void generate_keys(int *public_key, int *private_key, int *modulus)
{
    int p, q, n, phi, e, d;

    // Generate random prime numbers p and q
    p = generate_random_prime();
    q = generate_random_prime();

    // Calculate modulus n and Euler's totient function phi
    n = p * q;
    phi = (p - 1) * (q - 1);

    // Find public exponent e
    e = rand() % phi;

    while (gcd(e, phi) != 1)
    {
        e = rand() % phi;
    }

    // Find private exponent d
    d = 1;

    while (1)
    {
        if (((d * e) % phi) == 1)
        {
            break;
        }

        d++;
    }

    *public_key = e;
    *private_key = d;
    *modulus = n;
}

// Function to encrypt message using public key
int* encrypt_message(int *message, int message_length, int public_key, int modulus)
{
    int *encrypted_message = (int*)malloc(message_length * sizeof(int));

    for (int i = 0; i < message_length; i++)
    {
        encrypted_message[i] = fmod(pow(message[i], public_key), modulus);
    }

    return encrypted_message;
}

// Function to decrypt message using private key
int* decrypt_message(int *encrypted_message, int message_length, int private_key, int modulus)
{
    int *decrypted_message = (int*)malloc(message_length * sizeof(int));

    for (int i = 0; i < message_length; i++)
    {
        decrypted_message[i] = fmod(pow(encrypted_message[i], private_key), modulus);
    }

    return decrypted_message;
}

int main()
{
    srand(time(NULL));

    int public_key, private_key, modulus;
    int *message = (int*)malloc(4 * sizeof(int));

    // Generate keys for RSA encryption and decryption
    generate_keys(&public_key, &private_key, &modulus);

    // Read message from user
    printf("Enter a four-digit message: ");
    scanf("%d", message);

    // Encrypt message using public key
    int *encrypted_message = encrypt_message(message, 4, public_key, modulus);

    // Decrypt message using private key
    int *decrypted_message = decrypt_message(encrypted_message, 4, private_key, modulus);

    // Print results
    printf("\nPublic key: %d", public_key);
    printf("\nPrivate key: %d", private_key);
    printf("\nModulus: %d", modulus);

    printf("\n\nOriginal Message: %d %d %d %d", message[0], message[1], message[2], message[3]);
    printf("\nEncrypted Message: %d %d %d %d", encrypted_message[0], encrypted_message[1], encrypted_message[2], encrypted_message[3]);
    printf("\nDecrypted Message: %d %d %d %d", decrypted_message[0], decrypted_message[1], decrypted_message[2], decrypted_message[3]);

    free(message);
    free(encrypted_message);
    free(decrypted_message);

    return 0;
}