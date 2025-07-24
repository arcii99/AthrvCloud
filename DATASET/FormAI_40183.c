//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Function to calculate GCD
int gcd(int a, int h)
{
    int temp;
    while (1)
    {
        temp = a % h;
        if (temp == 0)
            return h;
        a = h;
        h = temp;
    }
}

int main()
{
    int p = 13;
    int q = 23;
    int n = p*q;
    int e = 5;
    int phi = (p-1)*(q-1);
    int flag;
    int d;
    
    // Ensure that e and phi are co-prime
    while (1)
    {
        flag = gcd(e, phi);
        if (flag == 1)
            break;
        else
            e++;
    }
    
    // Calculate private key
    d = fmod(((1 + (phi * 1.0))/e), phi);
    
    printf("Public key: (%d, %d)\n", e, n);
    printf("Private key: (%d, %d)\n", d, n);
    
    // Encrypt the message
    char message[100] = "HELLO WORLD!";
    int encrypted[100];
    for (int i = 0; i < strlen(message); i++)
        encrypted[i] = fmod(pow((int)message[i], e), n);
    
    // Decrypt the message
    char decrypted[100];
    for (int i = 0; i < strlen(message); i++)
        decrypted[i] = (char)(fmod(pow(encrypted[i], d), n));
    
    printf("Original message: %s\n", message);
    printf("Encrypted message: ");
    for (int i = 0; i < strlen(message); i++)
        printf("%d ", encrypted[i]);
    printf("\nDecrypted message: %s\n", decrypted);
    
    return 0;
}