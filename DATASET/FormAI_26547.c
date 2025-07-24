//FormAI DATASET v1.0 Category: Encryption ; Style: Donald Knuth
#include <stdio.h>
#include <string.h>

void encrypt(char *str) {
    int key = 4; // encryption key, can be changed to any integer value
    
    for(int i = 0; i < strlen(str); i++) {
        if(str[i] >= 'a' && str[i] <= 'z') {
            // add key to lowercase alphabets
            str[i] = (((str[i] - 'a') + key) % 26) + 'a';
        }
        else if(str[i] >= 'A' && str[i] <= 'Z') {
            // add key to uppercase alphabets
            str[i] = (((str[i] - 'A') + key) % 26) + 'A';
        }
        else if(str[i] >= '0' && str[i] <= '9') {
            // add key to digits
            str[i] = (((str[i] - '0') + key) % 10) + '0';
        }
    }
}

int main() {
    char str[100];
    
    printf("Enter a string to encrypt: ");
    fgets(str, 100, stdin);
    
    printf("Original string: %s", str);
    
    encrypt(str);
    
    printf("Encrypted string: %s", str);
    
    return 0;
}