//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the prime number used in the hash function
#define PRIME 31

// Define the maximum length of the input string
#define MAX_STRING_LENGTH 100

// Function to calculate the hash value of a string
unsigned long long calculate_hash(char* str)
{
    unsigned long long hash = 0;

    // Loop through each character in the string
    for(int i = 0; i < strlen(str); i++) {
        // Multiply the hash by the prime number
        hash *= PRIME;
        // Add the ASCII value of the character to the hash
        hash += (unsigned long long) str[i];
    }

    return hash;
}

int main()
{
    char* str = (char*) malloc(sizeof(char) * MAX_STRING_LENGTH);
    printf("Enter the string to hash: ");
    scanf("%s", str);
    
    printf("The hash value of \"%s\" is: %llu\n", str, calculate_hash(str));

    free(str);

    return 0;
}