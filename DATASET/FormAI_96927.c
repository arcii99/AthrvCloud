//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: calm
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* This function takes a string and returns a cryptographic hash
   value using a unique algorithm. */
char* crypto_hash(char* str) {
    int i, sum = 0;
    char* hash = (char*) malloc(65 * sizeof(char));  // 64 hexadecimal digits and \0 character
    char* hash_ptr = hash;

    // Hashing algorithm
    for (i = 0; i < strlen(str); i++) {
        sum += str[i];
        *hash_ptr = sum ^ (sum << 1);
        hash_ptr++;
    }
    *hash_ptr = '\0';  // Terminate the hash string

    return hash;
}

int main() {
    char input_str[100];
    char* hash;

    // Prompt the user to enter a string
    printf("Enter a string to hash: ");
    fgets(input_str, 100, stdin);

    // Remove the newline character from the string
    input_str[strcspn(input_str, "\n")] = 0;

    // Generate the hash
    hash = crypto_hash(input_str);

    // Output the hash value
    printf("Hash value of \"%s\" is: %s\n", input_str, hash);

    // Free the dynamically allocated memory for the hash
    free(hash);

    return 0;
}