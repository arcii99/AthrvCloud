//FormAI DATASET v1.0 Category: Word Count Tool ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50

int main() {
    char input[1000];
    int count = 0;
    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);

    char *token = strtok(input, " \n\t\r");
    while (token != NULL) {
        int length = strlen(token);
        if (length > MAX_WORD_LENGTH) {
            printf("Error: %s is longer than %d characters.\n", token, MAX_WORD_LENGTH);
            return 1;
        }
        for (int i = 0; i < length; i++) {
            if (!isalpha(token[i])) {
                printf("Error: %s contains non-alphabetic characters.\n", token);
                return 1;
            }
        }
        count++;
        token = strtok(NULL, " \n\t\r");
    }
    printf("Total words: %d\n", count);
    return 0;
}