//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: single-threaded
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SENTENCE_LENGTH 1000

typedef struct {
    char word[50];
    int score;
} WordScore;

WordScore word_scores[] = { // A list of words and their sentiment scores
    {"happy", 2},
    {"sad", -2},
    {"good", 1},
    {"bad", -1},
    {"love", 3},
    {"hate", -3},
};

int get_word_score(char *word) {
// Returns the sentiment score of a given word, or 0 if the word is not found in the list
    int i;
    for (i = 0; i < sizeof(word_scores) / sizeof(WordScore); i++) {
        if (strcmp(word, word_scores[i].word) == 0) {
            return word_scores[i].score;
        }
    }
    return 0;
}

int get_sentence_score(char *sentence) {
// Returns the sentiment score of a given sentence
    char *word = strtok(sentence, " ");
    int score = 0;
    while (word != NULL) {
        score += get_word_score(word);
        word = strtok(NULL, " ");
    }
    return score;
}

int main() {
    char sentence[MAX_SENTENCE_LENGTH];
    printf("Enter a sentence to analyze: ");
    fgets(sentence, MAX_SENTENCE_LENGTH, stdin);
    int score = get_sentence_score(sentence);
    if (score > 0) {
        printf("This sentence is positive with a score of %d.\n", score);
    } else if (score < 0) {
        printf("This sentence is negative with a score of %d.\n", score);
    } else {
        printf("This sentence is neutral with a score of %d.\n", score);
    }
    return 0;
}