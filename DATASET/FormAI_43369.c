//FormAI DATASET v1.0 Category: Modern Encryption ; Style: distributed
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define KEY 23

int main(int argc, char *argv[]) {
    char *input_string = argv[1];
    char output_string[strlen(input_string)+1];

    // Encryption
    for(int i=0; i < strlen(input_string); i++) {
        output_string[i] = (input_string[i] + KEY) % 128;
    }
    output_string[strlen(input_string)] = '\0';

    // Distributed style: Print the encrypted characters
    printf("Encrypted message: ");
    for(int i=0; i < strlen(output_string); i++) {
        printf("%c ", output_string[i]);
    }
    printf("\n");

    // Decryption
    for(int i=0; i < strlen(output_string); i++) {
        output_string[i] = (output_string[i] - KEY + 128) % 128;
    }
    output_string[strlen(output_string)] = '\0';

    // Distributed style: Print the decrypted message
    printf("Decrypted message: ");
    for(int i=0; i < strlen(output_string); i++) {
        printf("%c", output_string[i]);
    }
    printf("\n");

    return 0;
}