//FormAI DATASET v1.0 Category: Encryption ; Style: cheerful
#include <stdio.h>
#include <string.h>

void encrypt(char *str) {
    int i;
    for(i=0; i<strlen(str); i++) {
        if(str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = 'Z' - (str[i] - 'A');
        }
        else if(str[i] >= 'a' && str[i] <= 'z') {
            str[i] = 'z' - (str[i] - 'a');
        }
    }
}

void decrypt(char *str) {
    int i;
    for(i=0; i<strlen(str); i++) {
        if(str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = 'A' + ('Z' - str[i]);
        }
        else if(str[i] >= 'a' && str[i] <= 'z') {
            str[i] = 'a' + ('z' - str[i]);
        }
    }
}

int main() {
    char str[100];
    printf("Enter a string to encrypt: ");
    scanf("%[^\n]s", str);

    encrypt(str);
    printf("Encrypted string: %s\n", str);

    decrypt(str);
    printf("Decrypted string: %s\n", str);

    return 0;
}