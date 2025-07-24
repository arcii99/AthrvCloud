//FormAI DATASET v1.0 Category: File Encyptor ; Style: grateful
#include <stdio.h>
#include <string.h>

void encrypt(char *input_str, char *output_str, char key) {
    int i;
    int len = strlen(input_str);
    for (i = 0; i < len; i++) {
        *(output_str + i) = *(input_str + i) ^ key;
    }
}

void decrypt(char *input_str, char *output_str, char key) {
    int i;
    int len = strlen(input_str);
    for (i = 0; i < len; i++) {
        *(output_str + i) = *(input_str + i) ^ key;
    }
}

int main() {
    char input[100];
    char encrypted[100], decrypted[100];
    char key;

    printf("Enter text to encrypt: ");
    fgets(input, 100, stdin);

    printf("Enter a key for encryption: ");
    scanf("%c", &key);

    encrypt(input, encrypted, key);

    printf("\nEncrypted text: ");
    printf("%s\n", encrypted);

    decrypt(encrypted, decrypted, key);

    printf("\nDecrypted text: ");
    printf("%s\n", decrypted);

    return 0;
}