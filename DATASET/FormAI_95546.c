//FormAI DATASET v1.0 Category: Encryption ; Style: visionary
#include <stdio.h>
#include <string.h>

void encrypt(char *str, int key) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        str[i] = str[i] + key;
    }
}

void decrypt(char *str, int key) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        str[i] = str[i] - key;
    }
}

int main() {
    char str[50];
    int key;
    
    printf("Enter a string: ");
    scanf("%s", str);
    
    printf("Enter a key (positive integer): ");
    scanf("%d", &key);
    
    encrypt(str, key);
    printf("Encrypted string: %s\n", str);
    
    decrypt(str, key);
    printf("Decrypted string: %s\n", str);
    
    return 0;
}