//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAU 2.61803398875    /* The Golden Ratio */
#define PRIME 4294967291     /* Largest Prime less than 2^32 */

/**
 * Function to generate a Cryptographic hash for given string.
 *
 * Logic:
 * 1. Hash function takes a string as input and generates a hash code using the following steps
 * 2. Initialize the hash value to a random prime number
 * 3. Loop over each character in the string and perform the following steps
 * 4. Multiply the hash by the Golden Ratio constant TAU
 * 5. Add the ASCII value of the current character
 * 6. Take a modulo of the hash value with the largest prime less than 2^32 - PRIME constant
 * 7. Return the final hash value
 *
 * @param str: input string to generate hash code
 * @return: Hash code generated
 */
unsigned long long hash(char* str) {

    unsigned long long hash_value = PRIME;    // Initialize hash value to prime number

    for (int i = 0; i < strlen(str); i++) {
        hash_value = (hash_value * TAU) + (int) str[i];   // Multiply by Golden ratio and add current char ascii value
        hash_value = hash_value % PRIME;    // Take modulo with largest prime less than 2^32
    }

    return hash_value;  // Return final hash code
}

int main() {

    char input_str[50];
    printf("Enter input string to generate hash code: ");
    scanf("%s", input_str);

    unsigned long long hash_code = hash(input_str);

    printf("Hash code for '%s' is: %llu", input_str, hash_code);

    return 0;
}