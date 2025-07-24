//FormAI DATASET v1.0 Category: Modern Encryption ; Style: scalable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to encrypt the given string
char* encrypt(char* str, int n) {
    char* result = (char*)malloc(sizeof(char) * (n + 1));
    for (int i = 0; i < n; i++) {
        int c = str[i];
        if (isalpha(c)) {
            c = tolower(c);
            c = 'a' + (c - 'a' + 13) % 26;
        }
        result[i] = c;
    }
    result[n] = '\0';
    return result;
}

// Driver code
int main() {
    char str[100], *enc;
    printf("Enter a string: ");
    gets(str);
    enc = encrypt(str, strlen(str));
    printf("Encrypted String: %s", enc);
    free(enc);
    return 0;
}