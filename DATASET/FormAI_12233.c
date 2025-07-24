//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LEN 256

int compare_words(const void *a, const void *b) {
    const char **pa = (const char **) a;
    const char **pb = (const char **) b;
    return strcmp(*pa, *pb);
}

int main() {
    char *buffer = NULL;
    size_t buffer_size = 0;
    ssize_t nread;
    char *words[MAX_WORD_LEN];
    int word_counts[MAX_WORD_LEN] = {0};
    int num_words = 0;
    
    printf("Enter your text:\n");
    while ((nread = getline(&buffer, &buffer_size, stdin)) != -1) {
        char *token = strtok(buffer, " \t\n\r");
        while (token != NULL) {
            char *word = malloc(strlen(token) + 1);
            word[strlen(token)] = '\0';
            for (int i = 0; i < strlen(token); i++) {
                word[i] = tolower(token[i]);
            }
            words[num_words++] = word;
            token = strtok(NULL, " \t\n\r");
        }
    }
    free(buffer);
    
    qsort(words, num_words, sizeof(char *), compare_words);
    
    int current_count = 1;
    for (int i = 1; i < num_words; i++) {
        if (strcmp(words[i], words[i-1]) == 0) {
            current_count++;
        } else {
            word_counts[current_count]++;
            current_count = 1;
        }
    }
    word_counts[current_count]++;
    
    printf("Word frequencies:\n");
    for (int i = MAX_WORD_LEN-1; i > 0; i--) {
        if (word_counts[i] > 0) {
            printf("%d - %d\n", i, word_counts[i]);
        }
    }
    
    for (int i = 0; i < num_words; i++) {
        free(words[i]);
    }
    
    return 0;
}