//FormAI DATASET v1.0 Category: Modern Encryption ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define KEY_SIZE 16
#define MAX_SIZE 1024
#define DELIMITER "`"

void generate_key(char *key, int size) {
    srand(time(NULL));
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    for (int i = 0; i < size; i++) {
        key[i] = charset[rand() % (sizeof(charset) - 1)];
    }
}

int encrypt(char *input, char *key, char *output) {
    int input_len = strlen(input);
    int key_len = strlen(key);
    int output_len = input_len + key_len + 1;
    if (output_len > MAX_SIZE) {
        return -1;
    }
    char *temp = (char *)malloc(output_len * sizeof(char));
    memset(temp, 0, output_len);
    for (int i = 0; i < input_len; i++) {
        temp[i] = input[i] ^ key[i % key_len];
    }
    sprintf(output, "%s`%s", key, temp);
    free(temp);
    return 0;
}

int decrypt(char *input, char *output) {
    char *key = strtok(input, DELIMITER);
    char *temp = strtok(NULL, DELIMITER);
    int key_len = strlen(key);
    int temp_len = strlen(temp);
    if (temp_len > MAX_SIZE || temp_len + 1 < key_len) {
        return -1;
    }
    memset(output, 0, temp_len);
    for (int i = 0; i < temp_len; i++) {
        output[i] = temp[i] ^ key[i % key_len];
    }
    return 0;
}

int main() {
    char key[KEY_SIZE + 1];
    generate_key(key, KEY_SIZE);
    char input[MAX_SIZE];
    char output[MAX_SIZE];
    printf("Enter text to encrypt: ");
    fgets(input, MAX_SIZE, stdin);
    input[strcspn(input, "\n")] = '\0';
    if (encrypt(input, key, output) < 0) {
        printf("Input too large!\n");
        return 1;
    }
    printf("Encrypted text: %s\n", output);
    memset(input, 0, sizeof(input));
    if (decrypt(output, input) < 0) {
        printf("Invalid input format!\n");
        return 1;
    }
    printf("Decrypted text: %s\n", input);
    return 0;
}