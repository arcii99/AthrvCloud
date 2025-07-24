//FormAI DATASET v1.0 Category: Modern Encryption ; Style: mathematical
#include <stdio.h>
#include <string.h>

void encrypt(char *input_string, char *output_string, int key) {
    int i;
    int length = strlen(input_string);
    for (i = 0; i < length; i++) {
        output_string[i] = input_string[i] + key;
    }
    output_string[length] = '\0';
}

void decrypt(char *input_string, char *output_string, int key) {
    int i;
    int length = strlen(input_string);
    for (i = 0; i < length; i++) {
        output_string[i] = input_string[i] - key;    
    }
    output_string[length] = '\0';
}

int main() {
    char input_string[100];
    char output_string[100];
    int key;
    printf("Enter a string to encrypt: ");
    scanf("%s", input_string);
    printf("Enter a key for encryption: ");
    scanf("%d", &key);
    encrypt(input_string, output_string, key);
    printf("Encrypted string: %s\n", output_string);
    decrypt(output_string, input_string, key);
    printf("Decrypted string: %s\n", input_string);
    return 0;
}