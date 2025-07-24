//FormAI DATASET v1.0 Category: modern Encryption ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *encrypt(char *str, int shift) {
    char *result = (char *)malloc(strlen(str) + 1);
    strcpy(result, str);

    for (int i = 0; i < strlen(result); i++) {
        if (result[i] >= 'a' && result[i] <= 'z') {
            result[i] = (result[i] - 'a' + shift) % 26 + 'a';
        } else if (result[i] >= 'A' && result[i] <= 'Z') {
            result[i] = (result[i] - 'A' + shift) % 26 + 'A';
        }
    }

    return result;
}

int main() {
    char str[256], *encrypted_str;
    int shift;

    printf("Enter a string: ");
    fgets(str, 256, stdin);
    printf("Enter a shift: ");
    scanf("%d", &shift);

    encrypted_str = encrypt(str, shift);

    printf("Original String: %s", str);
    printf("Encrypted String: %s", encrypted_str);

    free(encrypted_str);
    return 0;
}