//FormAI DATASET v1.0 Category: Text processing ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char input[1000];
    char output[1000];
    int key;

    printf("Enter the string to encrypt: ");
    fgets(input, 1000, stdin);

    printf("Enter the encryption key: ");
    scanf("%d", &key);

    int len = strlen(input);

    for (int i = 0; i < len; i++) {
        if (input[i] >= 65 && input[i] <= 90) {
            // uppercase
            output[i] = ((input[i] - 65 + key) % 26) + 65;
        } else if (input[i] >= 97 && input[i] <= 122) {
            // lowercase
            output[i] = ((input[i] - 97 + key) % 26) + 97;
        } else {
            // symbol or whitespace
            output[i] = input[i];
        }
    }

    output[len] = '\0';

    printf("The encrypted string is: %s\n", output);

    return 0;
}