//FormAI DATASET v1.0 Category: Encryption ; Style: intelligent
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char* encrypt(char* string_to_encrypt, int key) {
        int len = strlen(string_to_encrypt);
        char* encrypted_string = (char*) malloc(len + 1);

        for(int i = 0; i < len; i++) {
                if(isalpha(string_to_encrypt[i])) {
                        if(isupper(string_to_encrypt[i])) {
                                encrypted_string[i] = (((string_to_encrypt[i] - 65) + key) % 26) + 65;
                        } else {
                                encrypted_string[i] = (((string_to_encrypt[i] - 97) + key) % 26) + 97;
                        }
                } else {
                        encrypted_string[i] = string_to_encrypt[i];
                }
        }

        encrypted_string[len] = '\0';
        return encrypted_string;
}

int main() {
        char string_to_encrypt[101];
        printf("Enter the string to encrypt: \n");
        fgets(string_to_encrypt, 100, stdin);

        int key = 3;

        char* encrypted_string = encrypt(string_to_encrypt, key);

        printf("Encrypted string: %s\n", encrypted_string);

        free(encrypted_string);

        return 0;
}