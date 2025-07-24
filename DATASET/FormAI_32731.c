//FormAI DATASET v1.0 Category: modern Encryption ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* encrypt(char *str, int key) { // function to encrypt given string with the given key
    int len = strlen(str);
    char *encrypted = (char*) malloc(len * sizeof(char)); // allocate memory for encrypted string
    for(int i=0; i<len; i++) {
        char c = str[i];
        if(c >= 65 && c <= 90) { // capital letters
            encrypted[i] = (char) (((c - 65 + key) % 26) + 65);
        } else if(c >= 97 && c <= 122) { // small letters
            encrypted[i] = (char) (((c - 97 + key) % 26) + 97);
        } else {
            encrypted[i] = c; // any other characters
        }
    }
    encrypted[len] = '\0'; // terminate the string
    return encrypted;
}

int main() {
    printf("Enter the message to encrypt: ");
    char message[100];
    fgets(message, 100, stdin); // take input string with fgets
    int key;
    printf("Enter the key: ");
    scanf("%d", &key); // take the key input
    char *encrypted = encrypt(message, key); // encrypt the message with the key
    printf("\nEncrypted message: %s\n", encrypted); // print the encrypted message
    free(encrypted); // free the memory allocated for encrypted string
    return 0;
}