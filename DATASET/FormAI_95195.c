//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char input[1000];
    char word[100];
    int wordCount = 0;
    int i, j, k, found;

    printf("Enter a sentence: ");
    fgets(input, sizeof(input), stdin);

    // Remove trailing newline character
    input[strcspn(input, "\n")] = 0;

    // Convert sentence to lowercase
    for (i = 0; input[i]; i++) {
        input[i] = tolower(input[i]);
    }

    // Count frequency of each word
    for (i = 0; input[i]; i++) {
        k = 0;
        found = 0;
        while (input[i] != ' ' && input[i] != '\0') {
            word[k] = input[i];
            k++;
            i++;
        }
        word[k] = '\0';
        for (j = 0; j < i && !found; j++) {
            if (strcmp(word, input+j) == 0) {
                found = 1;
            }
        }
        if (found) {
            continue;
        }
        for (j = i + 1; input[j]; j++) {
            if (strcmp(word, input+j) == 0) {
                wordCount++;
            }
        }
        printf("%s: %d\n", word, wordCount);
        wordCount = 0;
    }

    return 0;
}