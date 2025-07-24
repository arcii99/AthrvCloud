//FormAI DATASET v1.0 Category: String manipulation ; Style: paranoid
#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100 // Max length of the C string

int main()
{
    char string1[MAX_LENGTH], string2[MAX_LENGTH];
    printf("Enter a string: ");
    fgets(string1, MAX_LENGTH, stdin); // Safe input method to prevent buffer overflow
    string1[strcspn(string1, "\n")] = 0; // Remove the newline character from the end of the string

    printf("Enter another string: ");
    fgets(string2, MAX_LENGTH, stdin);
    string2[strcspn(string2, "\n")] = 0;

    // Encrypted version of the strings
    char encrypted1[MAX_LENGTH], encrypted2[MAX_LENGTH];

    // Encryption algorithm: shift the ASCII values of each character by one
    for (int i = 0; i < strlen(string1); i++)
    {
        encrypted1[i] = string1[i] + 1;
    }
    encrypted1[strlen(string1)] = '\0'; // Append the null terminator at the end

    for (int i = 0; i < strlen(string2); i++)
    {
        encrypted2[i] = string2[i] + 1;
    }
    encrypted2[strlen(string2)] = '\0';

    // Check if the strings match
    int match = 1; // Assume they match
    if (strlen(string1) != strlen(string2))
    {
        match = 0; // Lengths differ, they cannot match
    }
    else
    {
        for (int i = 0; i < strlen(string1); i++)
        {
            if (encrypted1[i] != encrypted2[i])
            {
                match = 0;
                break; // A character differs, stop checking and declare them non-matching
            }
        }
    }

    // Clear the original strings from memory
    memset(string1, 0, MAX_LENGTH);
    memset(string2, 0, MAX_LENGTH);

    // Clear the encrypted strings from memory
    memset(encrypted1, 0, MAX_LENGTH);
    memset(encrypted2, 0, MAX_LENGTH);

    if (match)
    {
        printf("Strings match!\n");
    }
    else
    {
        printf("Strings do not match!\n");
    }

    // paranoid mode: overwrite all variables with random values before exiting
    char random1[MAX_LENGTH], random2[MAX_LENGTH], random3[MAX_LENGTH], random4[MAX_LENGTH];
    for (int i = 0; i < MAX_LENGTH; i++)
    {
        random1[i] = rand() % 256; // Generate a random byte
        random2[i] = rand() % 256;
        random3[i] = rand() % 256;
        random4[i] = rand() % 256;
    }

    // Clear the original strings from memory using the random values
    memcpy(string1, random1, MAX_LENGTH);
    memcpy(string2, random2, MAX_LENGTH);

    for (int i = 0; i < MAX_LENGTH; i++)
    {
        if (i < strlen(encrypted1))
        {
            encrypted1[i] = encrypted1[i] ^ random3[i]; // XOR the encrypted string with a random byte sequence
        }
        if (i < strlen(encrypted2))
        {
            encrypted2[i] = encrypted2[i] ^ random4[i];
        }
    }

    // Clear the encrypted strings from memory using the random values
    memcpy(encrypted1, random3, MAX_LENGTH);
    memcpy(encrypted2, random4, MAX_LENGTH);

    // Clear the random values from memory
    memset(random1, 0, MAX_LENGTH);
    memset(random2, 0, MAX_LENGTH);
    memset(random3, 0, MAX_LENGTH);
    memset(random4, 0, MAX_LENGTH);

    return 0;
}