//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define constants */
#define MAX_SENTENCE_LENGTH 1000
#define POSITIVE_WORDS_FILE "positive.txt"
#define NEGATIVE_WORDS_FILE "negative.txt"

/* Function declarations */
int get_sentiment_score(char *sentence, char *positive_words[], int positive_words_count, char *negative_words[], int negative_words_count);
char **load_words_from_file(char *filename, int *count);
void free_memory(char *sentence, char **positive_words, int positive_words_count, char **negative_words, int negative_words_count);

/* Main function */
int main(void) {
    /* Declare variables */
    char *sentence = (char *)malloc(MAX_SENTENCE_LENGTH*sizeof(char));
    char **positive_words = NULL, **negative_words = NULL;
    int positive_words_count = 0, negative_words_count = 0, score = 0;

    /* Load positive and negative words from files */
    positive_words = load_words_from_file(POSITIVE_WORDS_FILE, &positive_words_count);
    negative_words = load_words_from_file(NEGATIVE_WORDS_FILE, &negative_words_count);
    if (positive_words == NULL || negative_words == NULL) {
        printf("Error: Could not load positive and negative words from files\n");
        free_memory(sentence, positive_words, positive_words_count, negative_words, negative_words_count);
        return 1;
    }

    /* Get input sentence from user */
    printf("Enter a sentence: ");
    fgets(sentence, MAX_SENTENCE_LENGTH, stdin);

    /* Remove newline character at the end of input sentence */
    sentence[strcspn(sentence, "\n")] = 0;

    /* Get sentiment score */
    score = get_sentiment_score(sentence, positive_words, positive_words_count, negative_words, negative_words_count);

    /* Print sentiment score */
    printf("Sentiment score: %d\n", score);

    /* Free allocated memory */
    free_memory(sentence, positive_words, positive_words_count, negative_words, negative_words_count);

    /* Return 0 to indicate success */
    return 0;
}

/* Function definitions */

/* This function takes a sentence, arrays of positive and negative words, and their respective counts as input.
It calculates the sentiment score of the sentence by counting the number of positive and negative words.
It returns the sentiment score. */
int get_sentiment_score(char *sentence, char *positive_words[], int positive_words_count, char *negative_words[], int negative_words_count) {
    int score = 0;
    char *word = NULL;

    /* Get first word in sentence */
    word = strtok(sentence, " ");

    /* Loop through all words in sentence */
    while (word != NULL) {
        /* Check if word is in list of positive words */
        for (int i = 0; i < positive_words_count; i++) {
            if (strcmp(word, positive_words[i]) == 0) {
                score++;
                break;
            }
        }

        /* Check if word is in list of negative words */
        for (int i = 0; i < negative_words_count; i++) {
            if (strcmp(word, negative_words[i]) == 0) {
                score--;
                break;
            }
        }

        /* Get next word in sentence */
        word = strtok(NULL, " ");
    }

    /* Return sentiment score */
    return score;
}

/* This function takes a filename and a pointer to an integer as input.
It loads all words from the file and stores them in an array of strings.
It returns the array of strings. */
char **load_words_from_file(char *filename, int *count) {
    FILE *file = fopen(filename, "r");
    char **words = NULL;
    char word[MAX_SENTENCE_LENGTH];

    /* Check if file can be opened */
    if (file == NULL) {
        printf("Error: Could not open file %s\n", filename);
        return NULL;
    }

    /* Count number of words in file */
    *count = 0;
    while (fgets(word, MAX_SENTENCE_LENGTH, file) != NULL) {
        /* Remove newline character at the end of word */
        word[strcspn(word, "\n")] = 0;
        (*count)++;
    }

    /* Allocate memory for array of strings */
    words = (char **)malloc(*count*sizeof(char *));
    if (words == NULL) {
        printf("Error: Could not allocate memory for words\n");
        return NULL;
    }

    /* Go back to beginning of file */
    rewind(file);

    /* Load words from file and store them in array of strings */
    for (int i = 0; i < *count; i++) {
        if (fgets(word, MAX_SENTENCE_LENGTH, file) == NULL) {
            printf("Error: Could not read word from file %s\n", filename);
            free(words);
            return NULL;
        }

        /* Remove newline character at the end of word */
        word[strcspn(word, "\n")] = 0;

        /* Allocate memory for word in array of strings */
        words[i] = (char *)malloc((strlen(word)+1)*sizeof(char));
        if (words[i] == NULL) {
            printf("Error: Could not allocate memory for word in array\n");
            free_memory(NULL, words, i, NULL, 0);
            return NULL;
        }

        /* Copy word to array of strings */
        strcpy(words[i], word);
    }

    /* Close file */
    fclose(file);

    /* Return array of strings */
    return words;
}

/* This function frees up all memory allocated for the program. */
void free_memory(char *sentence, char **positive_words, int positive_words_count, char **negative_words, int negative_words_count) {
    /* Free sentence */
    free(sentence);
    
    /* Free positive words */
    for (int i = 0; i < positive_words_count; i++) {
        free(positive_words[i]);
    }
    free(positive_words);

    /* Free negative words */
    for (int i = 0; i < negative_words_count; i++) {
        free(negative_words[i]);
    }
    free(negative_words);
}