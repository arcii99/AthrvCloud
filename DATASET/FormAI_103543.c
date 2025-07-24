//FormAI DATASET v1.0 Category: Modern Encryption ; Style: recursive
#include <stdio.h>
#include <string.h>

/* Recursive function to encrypt a string */
void encrypt(char *str, int index, int key) {
    if(index == strlen(str)) {
        return;
    }
    char ch = str[index];
    // Encrypt uppercase letters
    if(ch >= 'A' && ch <= 'Z') {
        ch = ((ch - 'A') + key) % 26 + 'A';
    }
    // Encrypt lowercase letters
    else if(ch >= 'a' && ch <= 'z') {
        ch = ((ch - 'a') + key) % 26 + 'a';
    }
    // Recursive call to encrypt the next character
    encrypt(str, index+1, key);
    // Replace the character with the encrypted value
    str[index] = ch;
}

int main() {
    char str[100];
    int key;
    printf("Enter a string to encrypt: ");
    fgets(str, 100, stdin);
    printf("Enter the encryption key: ");
    scanf("%d", &key);
    // Remove the newline character from the string
    str[strcspn(str, "\n")] = '\0';
    // Call the encrypt function to encrypt the string
    encrypt(str, 0, key);
    printf("The encrypted string is: %s\n", str);
    return 0;
}