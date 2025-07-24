//FormAI DATASET v1.0 Category: Encryption ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* encrypt(char* input_str, int key) {
    char* output_str = (char*) malloc(sizeof(char) * strlen(input_str));
    int i = 0;
    for (; i < strlen(input_str); i++)
        output_str[i] = input_str[i] + key;
    output_str[i] = '\0';
    return output_str;
}

char* decrypt(char* input_str, int key) {
    char* output_str = (char*) malloc(sizeof(char) * strlen(input_str));
    int i = 0;
    for (; i < strlen(input_str); i++)
        output_str[i] = input_str[i] - key;
    output_str[i] = '\0';
    return output_str;
}

int main() {
    char input_str[100];
    int key;
    printf("Enter the String to encrypt: ");
    fgets(input_str, sizeof(input_str), stdin);
    printf("Enter the Encryption Key: ");
    scanf("%d", &key);
    char* encrypted_str = encrypt(input_str, key);
    printf("Encrypted String: %s\n", encrypted_str);
    char* decrypted_str = decrypt(encrypted_str, key);
    printf("Decrypted String: %s\n", decrypted_str);
    free(encrypted_str);
    free(decrypted_str);
    return 0;
}