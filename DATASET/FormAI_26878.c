//FormAI DATASET v1.0 Category: Modern Encryption ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a key as a 3x3 matrix
int key[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

// Function to encrypt a string using the key
void encrypt(char *text) {
    int len = strlen(text);
    int i, j, k;
    int plaintext[3][len/3 + 1];

    // Convert string to 3xN matrix
    k = 0;
    for (i = 0; i < 3; i++) {
        for (j = 0; j <= len/3; j++) {
            if (k < len) {
                plaintext[i][j] = text[k];
                k++;
            }
            else {
                plaintext[i][j] = '\0';
            }
        }
    }

    // Multiply matrix with key to get encrypted matrix
    int encrypted[3][len/3 + 1];
    for (i = 0; i < 3; i++) {
        for (j = 0; j <= len/3; j++) {
            encrypted[i][j] = 0;
            for (k = 0; k < 3; k++) {
                encrypted[i][j] += key[i][k] * plaintext[k][j];
            }
        }
    }

    // Convert encrypted matrix back to string and print
    for (i = 0; i < 3; i++) {
        for (j = 0; j <= len/3; j++) {
            if (encrypted[i][j] != '\0') {
                printf("%c", encrypted[i][j]);
            }
        }
    }
    printf("\n");
}

int main() {
    char str[100];
    printf("Enter a string: ");
    fgets(str, 100, stdin);
    encrypt(str);
    return 0;
}