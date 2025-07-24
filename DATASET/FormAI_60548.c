//FormAI DATASET v1.0 Category: Encryption ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char input[100];
    char* key = "secretkey";
    int keylen = strlen(key);
    int i, j = 0;

    printf("Enter the text to encrypt: ");
    fgets(input, 100, stdin);
    input[strcspn(input, "\n")] = 0;
    int inputlen = strlen(input);

    char* encrypted = (char*) malloc(inputlen + 1);
    for (i = 0; i < inputlen; i++) {
        char c = input[i];
        if (j == keylen)
            j = 0;
        char k = key[j];
        encrypted[i] = (c ^ k) + j;
        j++;
    }
    encrypted[i] = '\0';

    printf("\nEncrypted text: ");
    for (i = 0; i < inputlen; i++)
        printf("%02x", encrypted[i]);
    printf("\n");

    free(encrypted);
    return 0;
}