//FormAI DATASET v1.0 Category: Encryption ; Style: Alan Touring
#include <stdio.h>
#include <string.h>

// Function to encrypt a given string using a simple shift algorithm
void encrypt(char *str, int n) {
    int len = strlen(str);
    for(int i = 0; i < len; i++) {
        if(str[i] >= 'a' && str[i] <= 'z') {
            str[i] = 'a' + ((str[i] - 'a' + n) % 26);
        }
        else if(str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = 'A' + ((str[i] - 'A' + n) % 26);
        }
    }
}

// Function to decrypt a given string using a simple shift algorithm
void decrypt(char *str, int n) {
    int len = strlen(str);
    for(int i = 0; i < len; i++) {
        if(str[i] >= 'a' && str[i] <= 'z') {
            str[i] = 'a' + ((str[i] - 'a' - n + 26) % 26);
        }
        else if(str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = 'A' + ((str[i] - 'A' - n + 26) % 26);
        }
    }
}

int main() {
    char str[100];
    int n;

    printf("Enter a string to encrypt: ");
    fgets(str, 100, stdin);

    printf("Enter the shift value: ");
    scanf("%d", &n);

    encrypt(str, n);
    printf("Encrypted string: %s\n", str);

    decrypt(str, n);
    printf("Decrypted string: %s\n", str);

    return 0;
}