//FormAI DATASET v1.0 Category: Text Summarizer ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SENTENCES 100
#define MAX_SENTENCE_LEN 1000

int main() {
    // Welcome message
    printf("Welcome to the Paranoid Text Summarizer!\n\n");

    // Read in the text
    char text[MAX_SENTENCES][MAX_SENTENCE_LEN];
    printf("Please enter the text you would like summarized:\n");
    int num_sentences = 0;
    while (num_sentences < MAX_SENTENCES) {
        fgets(text[num_sentences], MAX_SENTENCE_LEN, stdin);
        if (strcmp(text[num_sentences], "\n") == 0) {
            break;
        }
        num_sentences++;
    }

    // Make sure the user didn't input too much text
    if (num_sentences == MAX_SENTENCES) {
        printf("ERROR: Maximum number of sentences exceeded!\n");
        exit(1);
    }

    // Summarize the text
    printf("\nHere is your summarized text:\n");
    int i, j, k;
    for (i = 0; i < num_sentences; i++) {
        // Remove any non-alphanumeric characters
        for (j = 0; j < strlen(text[i]); j++) {
            if (!isalnum(text[i][j])) {
                text[i][j] = ' ';
            }
        }

        // Split the sentence into words
        char *words[MAX_SENTENCE_LEN];
        int num_words = 0;
        words[num_words] = strtok(text[i], " ");
        while (words[num_words] != NULL) {
            num_words++;
            words[num_words] = strtok(NULL, " ");
        }

        // Count the number of each word in the sentence
        int count[num_words];
        for (j = 0; j < num_words; j++) {
            count[j] = 1;
            for (k = j + 1; k < num_words; k++) {
                if (strcmp(words[j], words[k]) == 0) {
                    count[j]++;
                }
            }
        }

        // Find the most frequently occurring word
        int max_count = 0;
        char *most_common_word = NULL;
        for (j = 0; j < num_words; j++) {
            if (count[j] > max_count) {
                max_count = count[j];
                most_common_word = words[j];
            } else if (count[j] == max_count) {
                // If there is a tie, choose the word that has fewer characters
                if (strlen(words[j]) < strlen(most_common_word)) {
                    most_common_word = words[j];
                }
            }
        }

        // Print the most common word of the sentence
        printf("* %s\n", most_common_word);
    }

    // Goodbye message
    printf("\nThank you for using the Paranoid Text Summarizer!\n");

    return 0;
}