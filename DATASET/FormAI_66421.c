//FormAI DATASET v1.0 Category: Text Summarizer ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_SUMMARY_LENGTH 500

int main() {

    char input[1000];
    char *word_list[MAX_WORDS];
    int word_count = 0;

    printf("Enter the text you want to summarize:\n");
    fgets(input, sizeof(input), stdin);

    // Split input into words and store them in an array
    char *word = strtok(input, " .,\n");
    while (word != NULL) {
        word_list[word_count++] = word;
        word = strtok(NULL, " .,\n");
    }

    // Summarize the text by including the first three words of each sentence
    char summary[MAX_SUMMARY_LENGTH] = "";
    int sentence_count = 0;
    for (int i = 0; i < word_count; i++) {
        strcat(summary, word_list[i]);
        if (strchr(".!?", word_list[i][strlen(word_list[i]) - 1]) != NULL) {
            sentence_count++;
        }
        if (sentence_count == 3) {
            break;
        }
        strcat(summary, " ");
    }

    printf("Summary:\n%s...", summary);
    return 0;
}