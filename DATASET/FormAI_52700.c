//FormAI DATASET v1.0 Category: Text processing ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    char input[256];
    char *token;
    printf("Enter a sentence: ");
    fgets(input, 256, stdin);

    token = strtok(input, " ");
    while (token != NULL) {

        // convert all letters to uppercase
        for (int i = 0; i < strlen(token); i++) {
            if (token[i] >= 'a' && token[i] <= 'z') {
                token[i] = token[i] - 32;
            }
        }

        printf("%s ", token);
        token = strtok(NULL, " ");
    }

    return 0;
}