//FormAI DATASET v1.0 Category: Text Summarizer ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_SENTENCES 100
#define MAX_SENT_CHAR 200
#define MAX_INPUT_CHAR 5000


void print_summary(char summary[MAX_SENTENCES][MAX_SENT_CHAR], int n) {
    printf("\n\nSummary:\n");
    for(int i=0; i<n; i++) {
        printf("%s ",summary[i]);
    }
    printf("\n\n");
}

int main() {
    char input_text[MAX_INPUT_CHAR];
    char output_text[MAX_SENTENCES][MAX_SENT_CHAR] = {0}; 
    char *sentences[MAX_SENTENCES]; 
    int sentence_count = 0;
    int summary_count = 0;
    int sentence_index = 0;

    printf("Enter text to summarize: ");
    fgets(input_text, MAX_INPUT_CHAR, stdin);

    // Delimit the input text into sentences
    sentences[sentence_index] = strtok(input_text, ".!?");

    while( sentences[sentence_index] != NULL ) {
        sentence_index++;
        sentences[sentence_index] = strtok(NULL, ".!?");
        sentence_count++;
    }

    // count words in each sentence, use as a weighting factor to determine summary sentences
    int lengths[sentence_count];
    for(int i=0; i<sentence_count; i++) {
        lengths[i] = 0;
        for(int j=0; sentences[i][j] != '\0'; j++) {
            if( sentences[i][j] == ' ' ) lengths[i]++;
        }
    }

    // Summarize the input text using the following algorithm:
    // - identify MAX_SENTENCES number of sentences with the highest word count
    // - copy those sentences into a new array and print the result
    while( summary_count < MAX_SENTENCES ) {
        int max_index = -1;
        for(int i=0; i<sentence_count; i++) {
            if( lengths[i] == -1 ) continue;
            if( max_index < 0 || lengths[i] > lengths[max_index]) {
                max_index = i;
            }
        }

        if( max_index < 0 ) break;
        printf("%d",max_index);
        strncpy( output_text[summary_count], sentences[max_index], MAX_SENT_CHAR );
        summary_count++;
        lengths[max_index] = -1; 
    }

    print_summary(output_text,summary_count);

    return 0;
}