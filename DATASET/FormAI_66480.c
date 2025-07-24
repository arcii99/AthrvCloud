//FormAI DATASET v1.0 Category: Encryption ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 1000

void encrypt(char message[], int key);

int main() {
    char message[MAX_LEN];
    int key;
    printf("Enter the message: ");
    fgets(message, MAX_LEN, stdin);
    printf("Enter the key: ");
    scanf("%d", &key);
    encrypt(message, key);
    printf("Encrypted message: %s", message);
    return 0;
}

void encrypt(char message[], int key) {
    int i = 0;
    char current_char;
    while (message[i] != '\0') {
        current_char = message[i];
        if (current_char >= 65 && current_char <= 90) { // uppercase letter
            message[i] = ((current_char - 65 + key) % 26) + 65;
        } else if (current_char >= 97 && current_char <= 122) { // lowercase letter
            message[i] = ((current_char - 97 + key) % 26) + 97;
        } else if (current_char >= 48 && current_char <= 57) { // digit
            message[i] = ((current_char - 48 + key) % 10) + 48;
        }
        i++;
    }
}