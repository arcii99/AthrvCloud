//FormAI DATASET v1.0 Category: Encryption ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to encrypt a given string
char* encrypt(char* str, int key) {
    int len = strlen(str);
    char* encrypted = (char*) malloc(len + 1);
    
    for(int i=0; i<len; i++) {
        if(str[i] >= 'a' && str[i] <= 'z') {
            // shift the lower case character by the key value
            encrypted[i] = ((str[i] - 'a' + key) % 26) + 'a';
        }
        else if(str[i] >= 'A' && str[i] <= 'Z') {
            // shift the upper case character by the key value
            encrypted[i] = ((str[i] - 'A' + key) % 26) + 'A';
        }
        else {
            // if the character is not an alphabet, copy it as it is
            encrypted[i] = str[i];
        }
    }
    encrypted[len] = '\0'; // terminate the string
    return encrypted;
}

int main() {
    char message[100];
    int key;
    printf("Enter a message to encrypt: ");
    fgets(message, 100, stdin); // read the message from user
    strtok(message, "\n"); // remove the trailing newline character
    printf("Enter a key value: ");
    scanf("%d", &key); // read the key value from user
    
    char* encrypted = encrypt(message, key); // call the encryption function
    printf("Encrypted message: %s\n", encrypted);
    
    free(encrypted); // free the dynamically allocated memory
    return 0;
}