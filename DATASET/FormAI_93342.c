//FormAI DATASET v1.0 Category: Encryption ; Style: scientific
/*
 * This program demonstrates the implementation of a customized encryption scheme
 * using the Caesar Cipher algorithm in C.
 * The program takes a user input string, encrypts it using the user-specified key value,
 * and stores the encrypted string in a different buffer.
 * The program uses scientific conventions to ensure maximum security while handling
 * the user data.
 * Minimum Key size: 4 bytes.
 * Maximum Key size: 64 bytes.
 * Maximum User Input Size: 65536 bytes.
 * Maximum Encrypted Output Size: 65536 bytes.
 * Author: Your Name
 * Date: Current Date
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_SIZE 64
#define MAX_BUFFER_SIZE 65536

void encrypt(char *input, char *key, char *encrypted);

int main() {

    char input[MAX_BUFFER_SIZE];
    char key[MAX_KEY_SIZE];
    char encrypted[MAX_BUFFER_SIZE];

    printf("Welcome to the Caesar Cipher Encryption program.\n");
    printf("Please enter the input string to be encrypted (maximum 65536 characters): ");
    fgets(input, MAX_BUFFER_SIZE, stdin);
    input[strcspn(input, "\n")] = 0;

    printf("Please enter the key string (minimum 4 and maximum 64 characters): ");
    fgets(key, MAX_KEY_SIZE, stdin);
    key[strcspn(key, "\n")] = 0;

    encrypt(input, key, encrypted);

    printf("The encrypted string is: %s", encrypted);

    return 0;
}

void encrypt(char *input, char *key, char *encrypted) {

    int input_len = strlen(input);
    int key_len = strlen(key);
    int i, j;
    char keymatrix[MAX_KEY_SIZE];

    if (key_len < 4) {
        printf("Error: The key size is smaller than the minimum allowed size (4 bytes).\n");
        exit(1);
    }

    if (key_len > MAX_KEY_SIZE) {
        printf("Error: The key size is larger than the maximum allowed size (64 bytes).\n");
        exit(1);
    }

    if (input_len > MAX_BUFFER_SIZE) {
        printf("Error: The input size is larger than the maximum buffer size (65536 bytes).\n");
        exit(1);
    }

    // Create the key matrix
    for(i = 0; i < key_len; i++) {
        for(j = i + 1; j < key_len; j++) {
            if(key[i] > key[j]) {
                char temp = key[i];
                key[i] = key[j];
                key[j] = temp;
            }
        }
    }

    strcpy(keymatrix,key);

    for(i = 0; i < key_len; i++) {
        for(j = 0; j < key_len; j++) {
            if(keymatrix[i]==key[j]) {
                keymatrix[i]=j+'A';
                key[j]= '_'; 
                break;
            }
        }
    }

    for(i = 0; i < input_len; i++) {
        if (input[i] >= 'a' && input[i] <= 'z') {
            input[i] = input[i] - 'a' + 'A';
        }

        if (input[i] >= 'A' && input[i] <= 'Z') {
            int pos = input[i] - 'A';
            encrypted[i] = keymatrix[pos];
        } else {
            encrypted[i] = input[i];
        }
    }

    encrypted[i] = '\0';

}