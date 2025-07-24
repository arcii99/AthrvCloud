//FormAI DATASET v1.0 Category: Text Summarizer ; Style: sophisticated
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Define a struct to hold each sentence
typedef struct sentence {
    char * text;
    int score;
} sentence;

// Define a function to split the text into sentences and return an array of sentences
sentence * get_sentences(char * text, int * count) {
    // Count the number of sentences
    *count = 0;
    for (int i = 0; i < strlen(text); i++) {
        if (text[i] == '.' || text[i] == '?' || text[i] == '!') {
            (*count)++;
        }
    }

    // Allocate memory for the sentence array
    sentence * sentences = malloc((*count) * sizeof(sentence));
    int index = 0;

    // Iterate over the string and populate the sentence array
    char * sentence_start = text;
    for (int i = 0; i < strlen(text); i++) {
        if (text[i] == '.' || text[i] == '?' || text[i] == '!') {
            // Get the sentence
            char * sentence = malloc((i - (sentence_start-text) + 1) * sizeof(char));
            strncpy(sentence, sentence_start, i - (sentence_start-text) + 1);
            sentence[i - (sentence_start-text) + 1] = '\0';

            // Remove leading and trailing whitespace
            int start_index = 0;
            int end_index = strlen(sentence) - 1;
            while (isspace(sentence[start_index])) {
                start_index++;
            }
            while (isspace(sentence[end_index])) {
                end_index--;
            }
            sentence[end_index+1] = '\0';

            // Add the sentence to the array
            sentences[index].text = sentence;
            sentences[index].score = 0;

            index++;
            sentence_start = text + i + 1;
        }
    }

    // Return the sentence array
    return sentences;
}

// Define a function to score each sentence based on the frequency of its words in the text
void score_sentences(char * text, sentence * sentences, int count) {
    // Tokenize the text into words
    char * word;
    char * saveptr;
    char * copy = malloc((strlen(text) + 1) * sizeof(char));
    strcpy(copy, text);
    word = strtok_r(copy, " \t\n\r", &saveptr);
    int * word_counts = calloc(count, sizeof(int));
    while (word != NULL) {
        // Count the frequency of this word in each sentence
        for (int i = 0; i < count; i++) {
            if (strstr(sentences[i].text, word) != NULL) {
                word_counts[i]++;
            }
        }
        word = strtok_r(NULL, " \t\n\r", &saveptr);
    }

    // Score each sentence based on the frequency of its words
    for (int i = 0; i < count; i++) {
        char * sentence = sentences[i].text;
        char * word;
        char * saveptr;
        char * copy = malloc((strlen(sentence) + 1) * sizeof(char));
        strcpy(copy, sentence);
        word = strtok_r(copy, " \t\n\r", &saveptr);
        while (word != NULL) {
            sentences[i].score += word_counts[i];
            word = strtok_r(NULL, " \t\n\r", &saveptr);
        }
        free(copy);
    }

    free(copy);
    free(word_counts);
}

// Define a function to sort the sentences by their scores in descending order
void sort_sentences(sentence * sentences, int count) {
    for (int i = 0; i < count; i++) {
        for (int j = i+1; j < count; j++) {
            if (sentences[i].score < sentences[j].score) {
                sentence temp = sentences[i];
                sentences[i] = sentences[j];
                sentences[j] = temp;
            }
        }
    }
}

// Define a function to print the summary
void print_summary(sentence * sentences, int count) {
    int summary_length = count/5;

    // Print the top summary_length sentences
    printf("Summary:\n");
    for (int i = 0; i < summary_length; i++) {
        printf("%s\n", sentences[i].text);
    }
}

int main() {
    // Define the text to be summarized
    char * text = "This is a long example text that contains multiple sentences. "
                 "It is meant to test the functionality of the text summarizer. "
                 "The summarizer should be able to identify the most important sentences "
                 "in the text and generate a concise summary without losing the meaning. "
                 "Let's see if it can do the job!";

    // Get the sentences
    int count;
    sentence * sentences = get_sentences(text, &count);

    // Score the sentences
    score_sentences(text, sentences, count);

    // Sort the sentences
    sort_sentences(sentences, count);

    // Print the summary
    print_summary(sentences, count);

    // Free memory
    for (int i = 0; i < count; i++) {
        free(sentences[i].text);
    }
    free(sentences);

    return 0;
}