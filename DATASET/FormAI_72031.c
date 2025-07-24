//FormAI DATASET v1.0 Category: Text Summarizer ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT 1000
#define MAX_SUMMARY 100

typedef struct word_count {
    char *word;
    int count;
} word_count;

int main() {
    char input[MAX_INPUT];
    word_count summary[MAX_SUMMARY];
    int num_words, i, j, k, max_count, max_index;

    printf("Enter some text:\n");
    fgets(input, MAX_INPUT, stdin);

    // Tokenize input into words
    char *word_list[MAX_INPUT];
    char *token = strtok(input, " \n\r\t");
    for (num_words = 0; token != NULL; num_words++) {
        word_list[num_words] = token;
        token = strtok(NULL, " \n\r\t");
    }

    // Count occurrences of each word and store in summary array
    int num_summary = 0;
    for (i = 0; i < num_words; i++) {
        for (j = 0; j < num_summary; j++) {
            // If word already in summary, increment count
            if (strcmp(summary[j].word, word_list[i]) == 0) {
                summary[j].count++;
                break;
            }
        }
        // If word not in summary, add to summary array
        if (j == num_summary) {
            summary[num_summary].word = word_list[i];
            summary[num_summary].count = 1;
            num_summary++;
        }
    }

    // Sort summary array by count in descending order
    for (i = 0; i < num_summary; i++) {
        max_count = summary[i].count;
        max_index = i;
        for (j = i + 1; j < num_summary; j++) {
            if (summary[j].count > max_count) {
                max_count = summary[j].count;
                max_index = j;
            }
        }
        if (max_index != i) {
            word_count temp = summary[i];
            summary[i] = summary[max_index];
            summary[max_index] = temp;
        }
    }

    // Output summary to console
    printf("\nSummary:\n");
    for (i = 0; i < num_summary && i < MAX_SUMMARY; i++) {
        printf("%d. %s - %d occurrences\n", i + 1, summary[i].word, summary[i].count);
    }

    return 0;
}