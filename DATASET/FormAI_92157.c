//FormAI DATASET v1.0 Category: Word Count Tool ; Style: secure
#include <stdio.h>
#include <string.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 20

struct Word {
    char str[MAX_WORD_LENGTH];
    int count;
};

int main() {
    struct Word words[MAX_WORDS];
    char input[256];
    int i, j, count = 0;

    printf("Enter a string: ");
    fgets(input, 256, stdin);

    // Replace newline character with null terminator
    input[strcspn(input, "\n")] = '\0';

    // Tokenize input
    char *token = strtok(input, " ");

    // Count words
    while (token != NULL) {
        for (i = 0; i < count; i++) {
            if (strcmp(words[i].str, token) == 0) {
                words[i].count++;
                break;
            }
        }
        if (i == count) {
            strncpy(words[count].str, token, MAX_WORD_LENGTH);
            words[count++].count = 1;
        }
        token = strtok(NULL, " ");
    }

    // Print results
    printf("Word count: %d\n", count);
    printf("Word frequency:\n");
    for (i = 0; i < count; i++) {
        printf("%s: %d\n", words[i].str, words[i].count);
    }

    return 0;
}