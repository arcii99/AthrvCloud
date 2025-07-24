//FormAI DATASET v1.0 Category: Text Summarizer ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 100

int main() {
    char input_text[MAX_WORDS][MAX_WORD_LENGTH] = {'\0'};
    char summary[MAX_WORDS] = {'\0'};
    int word_count = 0;
    int i, j;

    // User input
    printf("Enter your text: \n");
    char c = getchar();
    while (c != '\n' && word_count < MAX_WORDS) {
        // Check if word is complete
        if (isspace(c) || ispunct(c)) {
            input_text[word_count][strlen(input_text[word_count])-1] = '\0';
            word_count++;
        }
        // Append character to current word
        else {
            input_text[word_count][strlen(input_text[word_count])] = c;
        }
        c = getchar();
    }

    // Summarize text
    for (i = 0; i < word_count; i++) {
        // Check if word is a common word that can be ignored
        char common_words[][MAX_WORD_LENGTH] = {"a", "an", "the", "and", "but", "or", "in", "on", "at", "of", "to", "for", "by", "with", "from", "about", "into", "over", "after", "before"};
        int is_common_word = 0;
        for (j = 0; j < sizeof(common_words)/sizeof(common_words[0]); j++) {
            if (strcmp(input_text[i], common_words[j]) == 0) {
                is_common_word = 1;
                break;
            }
        }
        if (is_common_word == 1) {
            continue;
        }
        // Check if word is a proper noun
        char* last_char = &input_text[i][strlen(input_text[i])-2];
        if (*last_char == 's' && *(last_char-1) == '\'') {
            continue;
        }
        if (isupper(input_text[i][0])) {
            strcat(summary, input_text[i]);
            strcat(summary, " ");
        }
    }

    // Output summary
    printf("\nSummary: \n%s\n", summary);

    return 0;
}