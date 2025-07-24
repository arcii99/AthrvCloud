//FormAI DATASET v1.0 Category: Encryption ; Style: interoperable
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

// Encryption function
char* encrypt(char* str, int key) {
    char* result = malloc(strlen(str)+1);
    int i;
    for(i=0;i<strlen(str);i++) {
        char c = str[i];
        // Checking if the character is an alphabet
        if(isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            // Encryption formula : (c - base + key) mod 26 + base
            c = (c - base + key) % 26 + base;
        }
        result[i] = c;
    }
    result[i] = '\0';
    return result;
}

// Decryption function
char* decrypt(char* str, int key) {
    return encrypt(str, 26-key);
}

int main() {
    char* sampleString = "Interoperable Encryption";
    int key = 3;
    printf("Original string: %s\n", sampleString);

    // Encryption
    char* encrypted = encrypt(sampleString, key);
    printf("Encrypted string: %s\n", encrypted);

    // Decryption
    char* decrypted = decrypt(encrypted, key);
    printf("Decrypted string: %s\n", decrypted);

    // Freeing allocated memory
    free(encrypted);
    free(decrypted);

    return 0;
}