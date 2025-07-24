//FormAI DATASET v1.0 Category: Encryption ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to perform encryption
void encryption(char *input, char *output, char *password) {
    int i, j, k, len_input, len_password;
    len_input = strlen(input);
    len_password = strlen(password);
    for (i = 0; i < len_input; ++i) {
        output[i] = input[i];
        for (j = 0, k = i % len_password; j < len_password; ++j, ++k) {
            output[i] ^= password[k % len_password];
        }
    }
    output[i] = '\0';
}

// Function to perform decryption
void decryption(char *input, char *output, char *password) {
    int i, j, k, len_input, len_password;
    len_input = strlen(input);
    len_password = strlen(password);
    for (i = 0; i < len_input; ++i) {
        output[i] = input[i];
        for (j = 0, k = i % len_password; j < len_password; ++j, ++k) {
            output[i] ^= password[k % len_password];
        }
    }
    output[i] = '\0';
}

int main() {
    char input[100], output[100], password[100];
    printf("Enter the input string:");
    scanf("%s", input);
    printf("Enter the password:");
    scanf("%s", password);
    encryption(input, output, password);
    printf("Encrypted String: %s\n", output);
    decryption(output, input, password);
    printf("Decrypted String: %s\n", input);
    return 0;
}