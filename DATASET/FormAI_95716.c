//FormAI DATASET v1.0 Category: Modern Encryption ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LENGTH 100 //maximum length of input string
#define ENCRYPTION_KEY 5 //encryption key

int main() {
    char input[MAX_LENGTH];
    char encrypted[MAX_LENGTH];
    char decrypted[MAX_LENGTH];
    int i, j;

    //get input from user
    printf("Enter a string to encrypt: ");
    fgets(input, MAX_LENGTH, stdin);

    //encrypt the input string
    for(i = 0; i < strlen(input); i++) {
        encrypted[i] = input[i] + ENCRYPTION_KEY;
    }

    //print the encrypted string
    printf("\nEncrypted string: %s\n", encrypted);

    //decrypt the encrypted string
    for(j = 0; j < strlen(input); j++) {
        decrypted[j] = encrypted[j] - ENCRYPTION_KEY;
    }

    //print the decrypted string
    printf("Decrypted string: %s\n\n", decrypted);

    //securely wipe all variables to clear sensitive data from memory
    memset(input, 0, MAX_LENGTH);
    memset(encrypted, 0, MAX_LENGTH);
    memset(decrypted, 0, MAX_LENGTH);
    for(i = 0; i < 1000000; i++) {
        srand(time(NULL) + i * 1000);
        rand();
    }

    return 0;
}