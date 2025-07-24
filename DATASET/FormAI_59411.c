//FormAI DATASET v1.0 Category: Encryption ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LEN 100 // Maximum length of the string

char *encrypt(char *str, int key); // Function to encrypt the string

int main()
{
    char str[MAX_LEN];
    int key;

    printf("Enter the string to encrypt (Max length %d): ", MAX_LEN);
    fgets(str, MAX_LEN, stdin); // Getting input from the user
    printf("Enter the encryption key (0-25): ");
    scanf("%d", &key);

    char *enc_str = encrypt(str, key); // Encrypting the string
    printf("Encrypted string: %s\n", enc_str);

    free(enc_str); // Freeing the memory allocated to the encrypted string
    return 0;
}

char *encrypt(char *str, int key)
{
    int len = strlen(str);
    char *enc_str = (char *)malloc(len * sizeof(char)); // Dynamic memory allocation for the encrypted string

    srand(time(NULL)); // Seeding the random number generator
    for (int i = 0; i < len; i++)
    {
        int r = rand() % 10; // Generating a random number between 0 and 9

        // Applying the encryption algorithm
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            enc_str[i] = 'a' + ((str[i] + key - 'a') % 26) + r; // Adding a random offset to each character
        }
        else if (str[i] >= 'A' && str[i] <= 'Z')
        {
            enc_str[i] = 'A' + ((str[i] + key - 'A') % 26) + r; // Adding a random offset to each character
        }
        else
        {
            enc_str[i] = str[i]; // For characters other than alphabets, simply copy them to the encrypted string
        }
    }

    return enc_str;
}