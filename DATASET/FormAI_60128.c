//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: Cryptic
#include<stdio.h>
#include<math.h>

int main()
{
    int public_key, private_key, p, q, n, phi_n, e, d, message, encrypted_message, decrypted_message;
    
    // Initializing p and q as large prime numbers
    p = 17;
    q = 19;
    
    // Finding n and phi(n)
    n = p * q;
    phi_n = (p - 1) * (q - 1);
    
    // Finding the public key e
    e = 7;
    
    // Finding the private key d
    for(d=1; d<=phi_n; d++)
    {
        if((e * d) % phi_n == 1)
            break;
    }
    
    // Print the public and private key
    printf("Public Key (e,n): (%d,%d)\n", e, n);
    printf("Private Key (d,n): (%d,%d)\n\n", d, n);
    
    // Enter the message to be encrypted
    printf("Enter the message to be encrypted: ");
    scanf("%d", &message);
    
    // Encrypt the message
    encrypted_message = fmod(pow(message, e), n);
    printf("Encrypted Message: %d\n", encrypted_message);
    
    // Decrypt the message
    decrypted_message = fmod(pow(encrypted_message, d), n);
    printf("Decrypted Message: %d\n\n", decrypted_message);
    
    return 0;
}