//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PASS_LEN 12   // Change this value to increase or decrease password length
#define NUM_OF_CHARS 94 // Total number of printable ASCII characters


void generatePassword(char* password);

int main(void)
{
    char password[PASS_LEN + 1];  // Add one byte for null terminating character

    // Set the seed of random number generator
    srand((unsigned int)time(NULL));

    // Generate a secure password
    generatePassword(password);

    printf("Generated Password: %s\n", password);

    return 0;
}


void generatePassword(char* password)
{
    int i, random;
    char printableChars[NUM_OF_CHARS + 1] = "!\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~";
    // Add one byte for null terminating character 

    for (i = 0; i < PASS_LEN; i++)
    {
        random = rand() % NUM_OF_CHARS;
        password[i] = printableChars[random];
    }

    password[PASS_LEN] = '\0';  // add null terminating character at the end of the password

    return;
}