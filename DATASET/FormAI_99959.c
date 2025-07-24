//FormAI DATASET v1.0 Category: Text Summarizer ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SENTENCES 1000
#define MAX_LENGTH 1000

char *get_sentence(char *text);
void summarize(char *text);

int main() {
    char text[MAX_LENGTH];
    printf("Enter text to summarize: ");
    fgets(text, MAX_LENGTH, stdin);
    printf("\nSummary:\n");
    summarize(text);
    return 0;
}

/**
 * Function to get the next sentence from a given text
 * Returns the sentence as a string
 */
char *get_sentence(char *text) {
    static char sentence[MAX_LENGTH]; // static variable to store sentence
    int i = 0;
    while (*text) {
        if (*text == '.' || *text == '?' || *text == '!') {
            sentence[i++] = *(text++);
            sentence[i] = '\0';
            return sentence;
        }
        sentence[i++] = *(text++);
    }
    return NULL;
}

/**
 * Function to summarize a given text
 */
void summarize(char *text) {
    int sentence_count = 0;
    char *sentences[MAX_SENTENCES];
    char *word;
    char *summarized_text[MAX_LENGTH];
    int summarized_length = 0;
    int i;

    // Split the text into sentences
    sentences[sentence_count++] = strtok(text, ".?!");
    while ((sentences[sentence_count] = strtok(NULL, ".?!")) != NULL) {
        sentence_count++;
    }

    // Loop through each sentence and pick out important words
    for (i = 0; i < sentence_count; i++) {
        word = strtok(sentences[i], " ");
        while (word != NULL) {
            if (strcmp(word, "the") && strcmp(word, "a") && strcmp(word, "an") && strcmp(word, "and") && strcmp(word, "but") && strcmp(word, "or") && strcmp(word, "on") && strcmp(word, "at") && strcmp(word, "in") && strcmp(word, "of") && strcmp(word, "to") && strcmp(word, "with")) {
                strcat(summarized_text, word);
                strcat(summarized_text, " ");
                summarized_length += (strlen(word) + 1);
                if (summarized_length > (MAX_LENGTH / 2)) {
                    break;
                }
            }
            word = strtok(NULL, " ");
        }
        if (summarized_length > (MAX_LENGTH / 2)) {
            break;
        }
    }
    summarized_text[summarized_length] = '\0';

    // Print the summarized text
    printf("%s...\n", summarized_text);
}