//FormAI DATASET v1.0 Category: Encryption ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 100

void encrypt(char *input, char *output, int key) {
    int i, len;
    char c;

    len = strlen(input);

    for(i = 0; i < len; i++) {
        c = input[i];

        if(c >= 'a' && c <= 'z')
            c = (c + key - 'a') % 26 + 'a';
        else if(c >= 'A' && c<= 'Z')
            c = (c + key - 'A') % 26 + 'A';

        output[i] = c;
    }
    output[i] = '\0';
}

int main() {
    char input[MAXSIZE], output[MAXSIZE], key_str[MAXSIZE];
    int key;

    printf("Enter the input string: ");
    fgets(input, MAXSIZE, stdin);
    input[strcspn(input, "\n")] = 0;

    printf("Enter the key: ");
    fgets(key_str, MAXSIZE, stdin);
    key = atoi(key_str);

    encrypt(input, output, key);
    printf("Encrypted string: %s\n", output);

    return 0;
}