//FormAI DATASET v1.0 Category: Text Summarizer ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE 10000 // Maximum length of input text
#define MAXSENTS 1000 // Maximum number of sentences in input text
#define MAXWORDS 1000 // Maximum number of words in input text

char* summarize(char* text, int len, int summary_len) {

    // Initialize the sentence and word arrays
    char** sentences = (char**) malloc(MAXSENTS * sizeof(char*));
    char** words = (char**) malloc(MAXWORDS * sizeof(char*));
    int num_sentences = 0;
    int num_words = 0;

    // Split the text into sentences
    char* sentence = strtok(text, ".!?"); 
    while (sentence != NULL && num_sentences < MAXSENTS) {
        sentences[num_sentences++] = sentence;
        sentence = strtok(NULL, ".!?");
    }

    // Split each sentence into words
    for (int i = 0; i < num_sentences; i++) {
        int len = strlen(sentences[i]);
        char* sentence_copy = (char*) malloc(len + 1);
        strncpy(sentence_copy, sentences[i], len);
        sentence_copy[len] = '\0';
        char* word = strtok(sentence_copy, " ");
        while (word != NULL && num_words < MAXWORDS) {
            words[num_words++] = word;
            word = strtok(NULL, " ");
        }
        free(sentence_copy);
    }

    // Compute the frequency of each word
    char** unique_words = (char**) malloc(MAXWORDS * sizeof(char*));
    int* word_counts = (int*) malloc(MAXWORDS * sizeof(int));
    int num_unique_words = 0;

    for (int i = 0; i < num_words; i++) {
        int j;
        for (j = 0; j < num_unique_words; j++) {
            if (strcmp(words[i], unique_words[j]) == 0) {
                word_counts[j]++;
                break;
            }
        }
        if (j == num_unique_words) {
            unique_words[num_unique_words] = words[i];
            word_counts[num_unique_words++] = 1;
        }
    }

    // Sort the words by frequency
    for (int i = 0; i < num_unique_words - 1; i++) {
        int max_index = i;
        for (int j = i + 1; j < num_unique_words; j++) {
            if (word_counts[j] > word_counts[max_index]) {
                max_index = j;
            }
        }
        char* temp_word = unique_words[i];
        unique_words[i] = unique_words[max_index];
        unique_words[max_index] = temp_word;
        int temp_count = word_counts[i];
        word_counts[i] = word_counts[max_index];
        word_counts[max_index] = temp_count;
    }

    // Generate the summary
    char* summary = (char*) malloc(summary_len + 1);
    summary[0] = '\0';
    int summary_len_so_far = 0;

    for (int i = 0; i < num_unique_words && summary_len_so_far < summary_len; i++) {
        int num_chars_to_add = strlen(unique_words[i]) + 1;
        if (num_chars_to_add + summary_len_so_far > summary_len) {
            num_chars_to_add = summary_len - summary_len_so_far;
        }
        strncat(summary, unique_words[i], num_chars_to_add);
        strncat(summary, " ", 1);
        summary_len_so_far += num_chars_to_add;
    }

    // Clean up memory
    for (int i = 0; i < num_sentences; i++) {
        free(sentences[i]);
    }
    free(sentences);
    free(words);
    free(unique_words);
    free(word_counts);

    return summary;
}

int main() {
    char text[MAXLINE] = "The quick brown fox jumps over the lazy dog. The quick brown fox jumps over the lazy dog. The quick brown fox jumps over the lazy dog. The quick brown fox jumps over the lazy dog. The quick brown fox jumps over the lazy dog. The quick brown fox jumps over the lazy dog.";
    int len = strlen(text);
    char* summary = summarize(text, len, 20);
    printf("%s\n", summary);
    free(summary);
    return 0;
}