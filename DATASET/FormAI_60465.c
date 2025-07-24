//FormAI DATASET v1.0 Category: Text Summarizer ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_SIZE 1000
#define MAX_SENTENCES 30
#define MAX_SUMMARY_SIZE 200

void remove_punctuation(char *text);
int count_words(char *text);
int count_sentences(char *text);
int get_sentence_lengths(char **sentences, int num_sentences, int *sentence_lengths);
void summarize(char *text, char *summary);

int main() {
    char input_text[MAX_INPUT_SIZE];
    char summary[MAX_SUMMARY_SIZE];

    printf("Please enter the text you want to summarize:\n");
    fgets(input_text, MAX_INPUT_SIZE, stdin);

    // Remove any punctuation from the text
    remove_punctuation(input_text);

    // Count the number of words and sentences in the text
    int num_words = count_words(input_text);
    int num_sentences = count_sentences(input_text);

    // Split the text into sentences
    char *sentences[MAX_SENTENCES];
    char *token = strtok(input_text, ".!?");
    int i = 0;

    while (token != NULL && i < MAX_SENTENCES) {
        sentences[i++] = token;
        token = strtok(NULL, ".!?");
    }

    // Determine the length of each sentence
    int sentence_lengths[MAX_SENTENCES];
    get_sentence_lengths(sentences, num_sentences, sentence_lengths);

    // Summarize the text by selecting the longest sentences
    summarize(input_text, summary);

    printf("\nSummary:\n%s\n", summary);

    return 0;
}

void remove_punctuation(char *text) {
    for (int i = 0; i < strlen(text); i++) {
        if (ispunct(text[i])) {
            text[i] = ' ';
        }
    }
}

int count_words(char *text) {
    int count = 0;
    char *token = strtok(text, " ");

    while (token != NULL) {
        count++;
        token = strtok(NULL, " ");
    }

    return count;
}

int count_sentences(char *text) {
    int count = 0;

    for (int i = 0; i < strlen(text); i++) {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?') {
            count++;
        }
    }

    return count;
}

int get_sentence_lengths(char **sentences, int num_sentences, int *sentence_lengths) {
    for (int i = 0; i < num_sentences; i++) {
        sentence_lengths[i] = strlen(sentences[i]);
    }

    return 0;
}

void summarize(char *text, char *summary) {
    // Create an array to store the length of each sentence
    int sentence_lengths[MAX_SENTENCES];
    char *sentences[MAX_SENTENCES];
    char *token = strtok(text, ".!?");
    int i = 0;

    // Split the text into sentences and save their lengths in an array
    while (token != NULL && i < MAX_SENTENCES) {
        sentences[i++] = token;
        token = strtok(NULL, ".!?");
    }

    int num_sentences = i;
    get_sentence_lengths(sentences, num_sentences, sentence_lengths);

    // Select the longest sentences and append them to the summary until it reaches MAX_SUMMARY_SIZE characters
    int summary_length = 0;
    for (int i = 0; i < num_sentences; i++) {
        if (summary_length + sentence_lengths[i] < MAX_SUMMARY_SIZE) {
            strcat(summary, sentences[i]);
            strcat(summary, ". ");
            summary_length += sentence_lengths[i] + 2;
        } else {
            break;
        }
    }
}