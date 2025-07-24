//FormAI DATASET v1.0 Category: Encryption ; Style: funny
#include <stdio.h>
#include <string.h>

int main() {

    char clear_text[50] = "This is the cleartext!";
    char cipher_text[50];

    // A famous encryption technique by my grandma
    for(int i=0; i < strlen(clear_text); i++) {
        cipher_text[i] = clear_text[i] + 10;
    }

    // Show the results
    printf("Original message: %s\n", clear_text);
    printf("Encrypted message: %s\n", cipher_text);

    // Let's decrypt back and see if it works
    for(int i=0; i < strlen(cipher_text); i++) {
        clear_text[i] = cipher_text[i] - 10;
    }

    // Show the results
    printf("Decrypted message: %s\n", clear_text);

    return 0;
}