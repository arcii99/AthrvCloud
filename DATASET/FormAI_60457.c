//FormAI DATASET v1.0 Category: File Encyptor ; Style: optimized
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STR_LEN 256
#define ENCRYPTION_KEY 5

int main() {
    char string[MAX_STR_LEN];
    printf("Enter string to encrypt: ");
    fgets(string, MAX_STR_LEN, stdin);

    int string_len = strlen(string);

    for(int i=0; i<string_len; i++) {
        if(isalpha(string[i])) {
            if(isupper(string[i])) {
                string[i] = ((string[i] - 'A' + ENCRYPTION_KEY) % 26) + 'A';
            }
            else {
                string[i] = ((string[i] - 'a' + ENCRYPTION_KEY) % 26) + 'a';
            }
        }
    }

    printf("\nEncrypted string: %s\n", string);

    return 0;
}