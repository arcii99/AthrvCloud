//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: puzzling
#include <stdio.h>

#define MAX_LENGTH 1000
#define RANDOM_PRIME 13

// Permutation function
int permute(int num)
{
    int digit, permute = 0;

    while (num != 0)
    {
        digit = num % 10;
        permute = permute * 10 + digit;
        num /= 10;
    }

    return permute;
}

// Encryption function
int encrypt(int plain_text, int public_key)
{
    int cipher_text = 0, i, num_digits = 0, arr[MAX_LENGTH], temp;

    while (plain_text != 0)
    {
        arr[num_digits] = plain_text % 10;
        plain_text /= 10;
        num_digits++;
    }

    for (i = 0; i < num_digits; i++)
    {
        temp = arr[i];
        for (int j = 0; j < public_key; j++)
        {
            temp += RANDOM_PRIME;
            temp = permute(temp);
        }
        cipher_text = cipher_text * 10 + temp;
    }

    return cipher_text;
}

// Decryption function
int decrypt(int cipher_text, int private_key)
{
    int plain_text = 0, i, num_digits = 0, arr[MAX_LENGTH], temp;

    while (cipher_text != 0)
    {
        arr[num_digits] = cipher_text % 10;
        cipher_text /= 10;
        num_digits++;
    }

    for (i = 0; i < num_digits; i++)
    {
        temp = arr[i];
        for (int j = 0; j < private_key; j++)
        {
            temp = permute(temp);
            temp -= RANDOM_PRIME;
        }
        plain_text = plain_text * 10 + temp;
    }

    return plain_text;
}

int main()
{
    int public_key = 5;
    int private_key = 2;
    int plain_text = 12345;
    int cipher_text = encrypt(plain_text, public_key);
    int decrypted_text = decrypt(cipher_text, private_key);

    printf("Plain Text : %d\n", plain_text);
    printf("Encrypted Text : %d\n", cipher_text);
    printf("Decrypted Text : %d\n", decrypted_text);

    return 0;
}