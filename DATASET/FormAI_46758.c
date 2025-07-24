//FormAI DATASET v1.0 Category: Encryption ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char input[], char key[]) {
    int i, j = 0;
    for (i = 0; i < strlen(input); i++) {
        input[i] = (input[i] ^ key[j]);
        j++;
        if (j == strlen(key))
            j = 0;
    }
}

void decrypt(char input[], char key[]) {
    int i, j = 0;
    for (i = 0; i < strlen(input); i++) {
        input[i] = (input[i] ^ key[j]);
        j++;
        if (j == strlen(key))
            j = 0;
    }
}

int main() {
    char input[100], key[25], choice;
    do {
        printf("Enter a string to encrypt: ");
        fgets(input, 100, stdin);
        printf("Enter a key: ");
        fgets(key, 25, stdin);
        encrypt(input, key);
        printf("Encrypted string: %s\n", input);
        printf("Do you want to decrypt the string?(y/n) ");
        scanf(" %c", &choice);
        if (choice == 'y') {
            decrypt(input, key);
            printf("Decrypted string: %s\n", input);
        }
        printf("Do you want to continue?(y/n) ");
        scanf(" %c", &choice);
        getchar();
    } while (choice == 'y');
    return 0;
}