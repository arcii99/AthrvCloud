//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LEN 50

int cmpfunc(const void *a, const void *b) {
    return *(int *)b - *(int *)a;
}

int main() {
    char *text = NULL;
    size_t len = 0;
    ssize_t read;

    printf("Enter some text:\n");
    read = getline(&text, &len, stdin);

    if (read == -1) {
        printf("Error reading text\n");
        return 1;
    }

    // Convert text to lowercase
    for (int i = 0; i < strlen(text); i++) {
        text[i] = tolower(text[i]);
    }

    // Split text into words
    char *word;
    int word_count = 0;
    char *words[MAX_WORD_LEN];
    word = strtok(text, " .,-\n\r");

    while (word != NULL) {
        words[word_count++] = strdup(word);
        word = strtok(NULL, " .,-\n\r");
    }

    // Count word frequency
    int freq[word_count];
    memset(freq, 0, sizeof(freq));
    for (int i = 0; i < word_count; i++) {
        for (int j = 0; j < word_count; j++) {
            if (strcmp(words[j], words[i]) == 0) {
                freq[i]++;
            }
        }
    }

    // Sort word frequency in descending order
    qsort(freq, word_count, sizeof(int), cmpfunc);

    // Print word frequency
    printf("Word Frequency:\n");
    for (int i = 0; i < word_count; i++) {
        if (i > 0 && freq[i] != freq[i - 1]) {
            printf("\n");
        }
        printf("%s: %d\n", words[i], freq[i]);
    }

    // Clean up memory
    for (int i = 0; i < word_count; i++) {
        free(words[i]);
    }
    free(text);

    return 0;
}