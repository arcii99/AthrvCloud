//FormAI DATASET v1.0 Category: File Encyptor ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char password[10];
    char secret[100];
    printf("Enter a password (must be 9 characters or less): ");
    fgets(password, sizeof(password), stdin);
    printf("Enter the secret message you want to encrypt: ");
    fgets(secret, sizeof(secret), stdin);
    int pwd_len = strlen(password);
    int secret_len = strlen(secret);
    int i, j;
    for (i = 0, j = 0; i < secret_len; i++, j++) {
        if (j == pwd_len) j = 0;
        secret[i] += password[j];
    }
    printf("Encrypted message: %s\n", secret);
    return 0;
}