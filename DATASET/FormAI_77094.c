//FormAI DATASET v1.0 Category: Text Summarizer ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 100000
#define MAX_WORD_LENGTH 100

int main() {
    char input_text[MAX_WORDS][MAX_WORD_LENGTH];
    int word_count = 0;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    printf("Welcome to the Summarizer 3000!\n");
    printf("Please input your text below:\n");

    while ((read = getline(&line, &len, stdin)) != -1 && word_count < MAX_WORDS) {
        char *word = strtok(line, " ");
        while (word != NULL && word_count < MAX_WORDS) {
            strcpy(input_text[word_count], word);
            word_count++;
            word = strtok(NULL, " ");
        }
    }

    if (word_count == 0) {
        printf("Uh oh, it looks like you didn't input any text!\n");
        return 1;
    }

    printf("\nHere is your summarized text:\n");

    // Here is where the magic happens!
    // Our summarization algorithm just picks out the first and last words of the input text.
    printf("%s ... %s", input_text[0], input_text[word_count-1]);

    // Don't forget to free the memory allocated by getline for our input text!
    if (line) {
        free(line);
    }

    return 0;
}