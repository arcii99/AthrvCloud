//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: innovative
#include <stdio.h>

// Public Key Encryption Algorithm
int publicKeyEnc(int num, int power, int mod)
{
    int result = 1;
    // Binary Exponential Algorithm
    while (power > 0)
    {
        if (power % 2 == 1)
        {
            result = (result * num) % mod;
        }
        num = (num * num) % mod;
        power = power / 2;
    }
    return result;
}

int main()
{
    int p = 13;
    int q = 11;
    int n = p * q;
    int phi = (p - 1) * (q - 1);
    int e = 7;
    int d = 103; // d is the secret key
    int m = 9;   // message to be encrypted

    // Encryption
    int c = publicKeyEnc(m, e, n);
    printf("Encrypted Message: %d\n", c);

    // Decryption
    int dec = publicKeyEnc(c, d, n);
    printf("Decrypted Message: %d\n", dec);

    return 0;
}