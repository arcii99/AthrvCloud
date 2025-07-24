//FormAI DATASET v1.0 Category: Modern Encryption ; Style: relaxed
#include <stdio.h>
#include <string.h>

#define MAX_LEN 100 // maximum length of input string

int main() {
    char input[MAX_LEN]; // input string
    char key[MAX_LEN]; // encryption key
    char encrypted[MAX_LEN]; // encrypted string
    int i, j;

    printf("Enter a string to encrypt: ");
    fgets(input, MAX_LEN, stdin);

    printf("Enter an encryption key: ");
    fgets(key, MAX_LEN, stdin);

    // remove newline character from input and key strings
    input[strcspn(input, "\n")] = 0;
    key[strcspn(key, "\n")] = 0;

    // perform encryption
    for (i = 0, j = 0; i < strlen(input); i++, j++) {
        if (j == strlen(key)) {
            j = 0; // reset j if end of key is reached
        }
        encrypted[i] = input[i] ^ key[j]; // perform encryption using XOR operator
    }
    encrypted[i] = '\0'; // add null terminator to end of string

    printf("Encrypted string: %s\n", encrypted);

    return 0;
}