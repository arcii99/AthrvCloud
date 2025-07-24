//FormAI DATASET v1.0 Category: Text Summarizer ; Style: Ada Lovelace
// Welcome to my Ada Lovelace-inspired Text Summarizer program in C!

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    // Declare variables
    char input_text[10000];
    char *word;
    char summary[500];
    int num_words = 0;

    // Get the input text from the user
    printf("Enter the text to summarize:\n");
    fgets(input_text, 10000, stdin);

    // Tokenize the input text into separate words
    word = strtok(input_text, " ,.\"()\n\r");

    // Loop through each word and count how many words there are
    while (word != NULL) {
        num_words++;
        word = strtok(NULL, " ,.\"()\n\r");
    }

    // Check if the text is too short to be summarized
    if (num_words < 10) {
        printf("Sorry, the text is too short to be summarized.");
        return 0;
    }

    // If the text has 10 or more words, generate a summary
    else {
        printf("Summary:\n");

        // Reset the variables for the loop through the words
        word = strtok(input_text, " ,.\"()\n\r");
        num_words = 0;
        summary[0] = '\0';

        // Loop through each word and add it to the summary until there are 10 words
        while (word != NULL && num_words < 10) {
            strcat(summary, word);
            strcat(summary, " ");
            num_words++;
            word = strtok(NULL, " ,.\"()\n\r");
        }

        // Print out the summary
        printf("%s", summary);

        // If there are more than 10 words in the input text, add an ellipsis to the summary
        if (word != NULL) {
            printf("...");
        }

        return 0;
    }
}