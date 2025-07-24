//FormAI DATASET v1.0 Category: Encryption ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Recursive function to encrypt a string */
void encrypt(char *str, int len, int key) {
    /* Base case */
    if(len == 0) {
        return;
    }
    else {
        /* Recursively encrypt the rest of the string */
        encrypt(str, len - 1, key);
        /* Apply the encryption key to the current character */
        char ch = *(str + len - 1);
        char encrypted_ch = ch ^ key;
        *(str + len - 1) = encrypted_ch;
    }
}

int main() {
    char str[100];
    int key;
    /* Get the string and key from the user */
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    printf("Enter a key: ");
    scanf("%d", &key);

    /* Remove the newline character from the string */
    int len = strlen(str);
    if(str[len - 1] == '\n') {
        str[len - 1] = '\0';
        len--;
    }

    /* Encrypt the string recursively */
    encrypt(str, len, key);

    /* Print the encrypted string */
    printf("The encrypted string is: %s\n", str);

    return 0;
}