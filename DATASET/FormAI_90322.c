//FormAI DATASET v1.0 Category: Text Summarizer ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SENTENCES 1000
#define MAX_WORDS 1000
#define BUFFER_SIZE 10000

// function prototypes
char** split_sentences(char* text, int* num_sentences);
char** tokenize_sentence(char* sentence, int* num_tokens);
char* strip_punctuation(char* word);
void print_summary(char** sentences, int* indices_of_summary_sentences, int num_sentences);

int main() {
    char text[BUFFER_SIZE];
    char** sentences;
    int num_sentences = 0;
    int* sentence_scores;
    int* indices_of_summary_sentences;
    int num_summary_sentences = 0;
    int max_score = 0;

    // read text from user
    printf("Enter the text to summarize: ");
    fgets(text, BUFFER_SIZE, stdin);

    // split text into sentences
    sentences = split_sentences(text, &num_sentences);

    // allocate memory for sentence scores
    sentence_scores = (int*) malloc(num_sentences * sizeof(int));

    // compute score for each sentence
    for (int i = 0; i < num_sentences; i++) {
        char** tokens = tokenize_sentence(sentences[i], NULL);
        int num_tokens = 0;

        // count number of non-stopwords in sentence
        for (int j = 0; tokens[j] != NULL; j++) {
            if (strcmp(tokens[j], "") != 0 && strcmp(tokens[j], " ") != 0 && strcmp(tokens[j], "\n") != 0) {
                num_tokens++;
            }
        }

        // compute sentence score (for now, we are simply counting non-stopwords)
        sentence_scores[i] = num_tokens;

        // free memory
        for (int j = 0; tokens[j] != NULL; j++) {
            free(tokens[j]);
        }
        free(tokens);
    }

    // determine how many sentences should be included in summary
    num_summary_sentences = (int) ((float) num_sentences * 0.25);
    indices_of_summary_sentences = (int*) malloc(num_summary_sentences * sizeof(int));

    // find sentences with highest scores and add them to summary
    for (int i = 0; i < num_summary_sentences; i++) {
        for (int j = 0; j < num_sentences; j++) {
            if (sentence_scores[j] > max_score) {
                max_score = sentence_scores[j];
                indices_of_summary_sentences[i] = j;
            }
        }

        // reset max_score to find next-highest rated sentence
        sentence_scores[indices_of_summary_sentences[i]] = -1;
        max_score = 0;
    }

    // print summary
    print_summary(sentences, indices_of_summary_sentences, num_summary_sentences);

    // free memory
    for (int i = 0; i < num_sentences; i++) {
        free(sentences[i]);
    }
    free(sentences);
    free(sentence_scores);
    free(indices_of_summary_sentences);

    return 0;
}

/**
 * Split text into sentences.
 *
 * @param text The text to be split
 * @param num_sentences Pointer to the number of sentences
 * @return An array of strings, where each string is a sentence
 */
char** split_sentences(char* text, int* num_sentences) {
    char** sentences = (char**) malloc(MAX_SENTENCES * sizeof(char*));
    int sentence_index = 0;

    // split text into sentences
    char* sentence = strtok(text, ".!?");
    while (sentence != NULL) {
        sentence = strip_punctuation(sentence);
        if (strlen(sentence) > 0) {
            sentences[sentence_index++] = sentence;
        }
        sentence = strtok(NULL, ".!?");
    }

    *num_sentences = sentence_index;

    return sentences;
}

/**
 * Tokenize sentence into words.
 *
 * @param sentence The sentence to be tokenized
 * @param num_tokens Pointer to the number of tokens
 * @return An array of strings, where each string is a token (word)
 */
char** tokenize_sentence(char* sentence, int* num_tokens) {
    char** tokens = (char**) malloc(MAX_WORDS * sizeof(char*));
    int token_index = 0;

    // tokenize sentence into words
    char* token = strtok(sentence, " ");
    while (token != NULL) {
        token = strip_punctuation(token);
        if (strlen(token) > 0) {
            for (int i = 0; i < strlen(token); i++) {
                token[i] = tolower(token[i]);
            }
            tokens[token_index++] = token;
        }
        token = strtok(NULL, " ");
    }

    if (num_tokens != NULL) {
        *num_tokens = token_index;
    }

    return tokens;
}

/**
 * Strip punctuation from a word.
 *
 * @param word The word to have punctuation stripped
 * @return The stripped word
 */
char* strip_punctuation(char* word) {
    // strip leading punctuation
    while (ispunct(*word)) {
        word++;
    }

    // strip trailing punctuation
    int len = strlen(word);
    while (ispunct(word[len-1])) {
        word[len-1] = '\0';
        len--;
    }

    return word;
}

/**
 * Prints the summary text composed of selected sentences.
 *
 * @param sentences The array of all sentences
 * @param indices_of_summary_sentences The array of indices of sumary sentences
 * @param num_summary_sentences The number of sentences to include in the summary
 * @return The summary text
 */
void print_summary(char** sentences, int* indices_of_summary_sentences, int num_summary_sentences) {
    for (int i = 0; i < num_summary_sentences; i++) {
        printf("%s. ", sentences[indices_of_summary_sentences[i]]);
    }
    printf("\n");
}