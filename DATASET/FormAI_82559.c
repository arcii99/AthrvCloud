//FormAI DATASET v1.0 Category: Text Summarizer ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SENTENCES 100
#define MAX_SENTENCE_LEN 1000
#define MAX_SUMMARY_LEN 500

int main() {

    char text[MAX_SENTENCES][MAX_SENTENCE_LEN];
    char summary[MAX_SUMMARY_LEN];
    int i, j, k, num_sentences;

    printf("Enter the text to be summarized:\n");

    /* Reading input text */

    for(i=0; i<MAX_SENTENCES; i++) {
        fgets(text[i], MAX_SENTENCE_LEN, stdin);
        if(text[i][0] == '\n') {
            num_sentences = i;
            break;
        }
    }

    /* Removing newline characters from each sentence */

    for(i=0; i<num_sentences; i++) {
        for(j=0; j<MAX_SENTENCE_LEN; j++) {
            if(text[i][j] == '\n') {
                text[i][j] = ' ';
            }
        }
    }

    /* Tokenizing sentences into individual words */

    char *words[MAX_SENTENCES][MAX_SENTENCE_LEN];
    int num_words[MAX_SENTENCES];

    for(i=0; i<num_sentences; i++) {
        words[i][0] = strtok(text[i], " ");
        num_words[i] = 1;

        while(words[i][num_words[i]-1] != NULL) {
            words[i][num_words[i]] = strtok(NULL, " ");
            if(words[i][num_words[i]] != NULL) {
                num_words[i]++;
            }
        }
    }

    /* Creating word frequency table */

    char *unique_words[MAX_SENTENCES*MAX_SENTENCE_LEN];
    int frequencies[MAX_SENTENCES*MAX_SENTENCE_LEN];
    int num_unique_words = 0;

    for(i=0; i<num_sentences; i++) {
        for(j=0; j<num_words[i]; j++) {
            /* Check if word already exists in unique_words array */
            int index = -1;
            for(k=0; k<num_unique_words; k++) {
                if(strcmp(unique_words[k], words[i][j]) == 0) {
                    index = k;
                    break;
                }
            }

            /* If word doesn't exist in array, add it */
            if(index == -1) {
                unique_words[num_unique_words] = words[i][j];
                frequencies[num_unique_words] = 1;
                num_unique_words++;
            }

            /* If word exists in array, increment its frequency */
            else {
                frequencies[index]++;
            }
        }
    }

    /* Sort unique_words and frequencies arrays in decreasing order of frequency */

    for(i=0; i<num_unique_words-1; i++) {
        for(j=i+1; j<num_unique_words; j++) {
            if(frequencies[i] < frequencies[j]) {
                int temp_freq = frequencies[i];
                frequencies[i] = frequencies[j];
                frequencies[j] = temp_freq;

                char *temp_word = unique_words[i];
                unique_words[i] = unique_words[j];
                unique_words[j] = temp_word;
            }
        }
    }

    /* Generating summary */

    strcpy(summary, "");

    for(i=0; i<num_unique_words; i++) {
        /* Check if word occurs at least twice */
        if(frequencies[i] < 2) {
            continue;
        }

        /* Check if word is a stop word */
        char *stop_words[] = {"the", "a", "an", "in", "at", "on", "to", "of", "for", "with", "by", "from", "where", "how", "when", "why", "who"};
        int num_stop_words = sizeof(stop_words)/sizeof(stop_words[0]);
        int is_stop_word = 0;

        for(j=0; j<num_stop_words; j++) {
            if(strcmp(unique_words[i], stop_words[j]) == 0) {
                is_stop_word = 1;
                break;
            }
        }

        if(is_stop_word) {
            continue;
        }

        /* Add word to summary */
        strcat(summary, unique_words[i]);
        strcat(summary, " ");

        if(strlen(summary) > MAX_SUMMARY_LEN) {
            break;
        }
    }

    printf("Summary:\n%s\n", summary);

    return 0;
}