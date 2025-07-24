//FormAI DATASET v1.0 Category: Encryption ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* encrypt(char* str, int key) {
    int len = strlen(str);
    char* result = (char*)malloc(sizeof(char) * len);

    for(int i = 0; i < len; i++) {
        result[i] = str[i] + key;
    }

    return result;
}

int main() {
    char* message = "This is a secret message.";
    int key = 7;
    char* encrypted = encrypt(message, key);

    printf("Original Message: %s\n", message);
    printf("Encrypted Message: %s\n", encrypted);

    free(encrypted);
    return 0;
}