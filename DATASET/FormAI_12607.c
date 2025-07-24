//FormAI DATASET v1.0 Category: Encryption ; Style: invasive
#include <stdio.h>
#include <string.h>

void encrypt(char str[], int key) {
    int len = strlen(str);
    int i;

    for (i = 0; i < len; i++) {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            str[i] = ((str[i] + key - 'a') % 26) + 'a';
        }
        else if (str[i] >= 'A' && str[i] <= 'Z') 
        {
            str[i] = ((str[i] + key - 'A') % 26) + 'A';
        }
    }
}

int main() {
    char message[] = "Hello, world!";
    int key = 3;

    printf("Original message: %s\n", message);

    encrypt(message, key);

    printf("Encrypted message: %s\n", message);

    return 0;
}