//FormAI DATASET v1.0 Category: Encryption ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1000

char key[MAX_LENGTH];
char input[MAX_LENGTH];
char output[MAX_LENGTH];

void XOR(char *key, char *input, char *output) {
    int input_length = strlen(input);
    int key_length = strlen(key);

    for (int i = 0; i < input_length; i++) {
        output[i] = input[i] ^ key[i % key_length];
    }
    output[input_length] = '\0';
}

int main() {
    printf("Enter a key: ");
    fgets(key, MAX_LENGTH, stdin);
    key[strcspn(key, "\n")] = '\0';

    printf("Enter a message: ");
    fgets(input, MAX_LENGTH, stdin);
    input[strcspn(input, "\n")] = '\0';

    XOR(key, input, output);

    printf("Encrypted message: %s\n", output);

    return 0;
}