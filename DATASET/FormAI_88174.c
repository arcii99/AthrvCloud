//FormAI DATASET v1.0 Category: Encryption ; Style: portable
#include <stdio.h>
#include <string.h>

void encrypt(char* str, int key) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        char c = str[i];
        if (c >= 'A' && c <= 'Z') {
            // Shift uppercase letters by key positions
            str[i] = (c + key - 'A') % 26 + 'A';
        }
        else if (c >= 'a' && c <= 'z') {
            // Shift lowercase letters by key positions
            str[i] = (c + key - 'a') % 26 + 'a';
        }
        // Anything else is left unchanged
    }
}

int main() {
    char message[] = "Hello, World!";
    int key = 3;
    printf("Original message: %s\n", message);
    encrypt(message, key);
    printf("Encrypted message: %s\n", message);
    return 0;
}