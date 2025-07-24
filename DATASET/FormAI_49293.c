//FormAI DATASET v1.0 Category: Text Summarizer ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SIZE 10000
#define MAX_SUMMARY_SIZE 1000

char input_text[MAX_INPUT_SIZE];
char summary_text[MAX_SUMMARY_SIZE];

int main() {
    printf("Welcome to the Text Summarizer Program\n");
    printf("Please enter your text:\n");

    fgets(input_text, MAX_INPUT_SIZE, stdin); // get input text from user

    printf("\nInput Text:\n%s", input_text);

    // tokenize the input text using spaces and punctuation marks as delimiters
    char* token = strtok(input_text, " ,.;:?!");

    int sentence_count = 0; // count of sentences in the input text
    int word_count = 0; // count of words in the input text

    while (token != NULL) {
        word_count++;

        // check if the current token is the end of a sentence
        if (strchr(".?!", token[strlen(token)-1])) {
            sentence_count++;
        }

        token = strtok(NULL, " ,.;:?!");
    }

    printf("\nInput Text Summary:\n");

    if (sentence_count == 0) {
        printf("Sorry, no sentences found in the input text.");
    }
    else if (word_count/sentence_count < 10) {
        printf("Sorry, input text is too short.");
    }
    else {
        // generate a summary of the input text
        token = strtok(input_text, " ,.;:?!");

        int summary_word_count = 0; // count of words in the summary text

        while (token != NULL) {
            // append the current token to the summary text
            strcat(summary_text, token);
            strcat(summary_text, " ");
            summary_word_count++;

            // check if the summary text is too long
            if (summary_word_count > word_count/sentence_count*0.3) {
                break;
            }

            // check if the current token is the end of a sentence
            if (strchr(".?!", token[strlen(token)-1])) {
                // add a new line after each sentence in the summary text
                strcat(summary_text, "\n");
            }

            token = strtok(NULL, " ,.;:?!");
        }

        printf("%s", summary_text);
    }

    return 0;
}