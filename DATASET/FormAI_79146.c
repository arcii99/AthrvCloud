//FormAI DATASET v1.0 Category: Text Summarizer ; Style: Dennis Ritchie
#include <stdio.h>
#include <string.h>

#define MAX_SENTENCES 100
#define MAX_WORDS 1000

#define DEBUG 0 // set to 1 to print debug info

int index_of_max(int array[], int size);
void summarize_text(char *text, int sentence_count);

int main() {
    char text[1000] = "This is a text summarizer program. It takes in a piece of text and outputs a summary. The summary will consist of a specified number of sentences from the original text.";
    int sentence_count = 2;

    summarize_text(text, sentence_count);

    return 0;
}

/**
 * Returns the index of the max element in an array
 */
int index_of_max(int array[], int size) {
    int max_index = 0;
    int max_value = array[0];

    for (int i = 1; i < size; i++) {
        if (array[i] > max_value) {
            max_index = i;
            max_value = array[i];
        }
    }

    return max_index;
}

/**
 * Summarizes the input text down to the specified number of sentences
 */
void summarize_text(char *text, int sentence_count) {
    char sentences[MAX_SENTENCES][MAX_WORDS]; // 2D array to hold each sentence and its words
    int sentence_lengths[MAX_SENTENCES]; // array to hold the lengths of each sentence
    int sentence_scores[MAX_SENTENCES]; // array to hold the score of each sentence

    int num_sentences = 0;
    int word_count = 0;
    char *word;

    // split text into sentences and words
    for (int i = 0; i < strlen(text); i++) {
        if (text[i] == '.') {
            sentences[num_sentences][word_count] = '\0';
            sentence_lengths[num_sentences] = word_count;
            sentence_scores[num_sentences] = 0;
            num_sentences++;
            word_count = 0;
        } else if (text[i] == ' ') {
            sentences[num_sentences][word_count] = '\0';
            word_count++;
        } else {
            sentences[num_sentences][word_count] = text[i];
            word_count++;
        }
    }

    // calculate score for each sentence
    for (int i = 0; i < num_sentences; i++) {
        for (int j = 0; j < sentence_lengths[i]; j++) {
            // increase score if word is longer than average
            if (strlen(sentences[i][j]) > sentence_lengths[i] / 2) {
                sentence_scores[i]++;
            }
        }
        sentence_scores[i] /= sentence_lengths[i]; // divide by sentence length to get average score per word
    }

    // get top sentences
    int top_indices[sentence_count];
    for (int i = 0; i < sentence_count; i++) {
        top_indices[i] = index_of_max(sentence_scores, num_sentences);
        sentence_scores[top_indices[i]] = 0;
    }

    // print summary
    printf("Summary:\n");
    for (int i = 0; i < sentence_count; i++) {
        printf("%s. ", sentences[top_indices[i]]);
    }
}