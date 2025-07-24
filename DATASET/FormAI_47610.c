//FormAI DATASET v1.0 Category: Text Summarizer ; Style: artistic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_INPUT 500
#define MAX_SUMMARY 100

char input[MAX_INPUT];
char summary[MAX_SUMMARY];

int main() {
    printf("Enter the text you want to summarize:\n");
    fgets(input, MAX_INPUT, stdin);
    
    // Remove newline character from input
    input[strcspn(input, "\n")] = 0;
    
    // Tokenize input text
    char *token = strtok(input, " ");
    
    // Determine word count in input text
    int word_count = 0;
    while (token != NULL) {
        word_count++;
        token = strtok(NULL, " ");
    }
    
    // If input text is less than 15 words, return full text as summary
    if (word_count < 15) {
        strcpy(summary, input);
    } else {
        // Summarize input text
        int sentence_count = 0;
        char *p = input;
        while (*p) {
            if (*p == '.' || *p == '!' || *p == '?') {
                sentence_count++;
            }
            p++;
        }
        
        int sentences_per_summary = sentence_count / 3;
        int current_sentence = 0;
        int current_word_count = 0;
        char *summary_pointer = summary;
        char *input_pointer = input;
        int characters_remaining = MAX_SUMMARY - 1;
        while (*input_pointer && current_sentence < sentences_per_summary && current_word_count < 15) {
            int characters_to_copy = strlen(input_pointer);
            char *end_of_sentence = strpbrk(input_pointer, ".!?");
            if (end_of_sentence) {
                characters_to_copy = end_of_sentence - input_pointer + 1;
            }
            if (characters_remaining < characters_to_copy) {
                characters_to_copy = characters_remaining;
            }
            strncpy(summary_pointer, input_pointer, characters_to_copy);
            summary_pointer += characters_to_copy;
            current_word_count += strlen(strtok(input_pointer, " "));
            input_pointer += characters_to_copy;
            current_sentence++;
        }
        if (current_sentence < sentences_per_summary) {
            strncat(summary, " Read More...", MAX_SUMMARY - strlen(summary) - 1);
        }
    }
    
    printf("Summary: %s\n", summary);
    
    return 0;
}