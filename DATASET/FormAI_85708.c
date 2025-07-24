//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store a word and its associated sentiment score
typedef struct {
    char word[20];
    int score;
} sentiment_word;

// Array of sentiment words and their scores
sentiment_word sentiment_dict[] = {
    {"awesome", 5},
    {"happy", 4},
    {"good", 3},
    {"neutral", 2},
    {"sad", 1},
    {"terrible", 0},
};

// Function to calculate the sentiment score of a given word
int get_word_score(char *word) {
    int i;
    for (i = 0; i < sizeof(sentiment_dict) / sizeof(sentiment_word); i++) {
        if (strcmp(word, sentiment_dict[i].word) == 0) {
            return sentiment_dict[i].score;
        }
    }
    return -1; // Word not found in sentiment dictionary
}

// Function to calculate the sentiment score of a given sentence
int get_sentence_score(char *sentence) {
    int score = 0;
    char *token = strtok(sentence, " "); // Split sentence into words
    while (token != NULL) {
        int word_score = get_word_score(token);
        if (word_score != -1) {
            score += word_score; // Add word's score to sentence's score
        }
        token = strtok(NULL, " ");
    }
    return score;
}

int main() {
    char sentence[100];
    printf("Enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin); // Read sentence from user

    int score = get_sentence_score(sentence);
    printf("Sentiment Score: %d\n", score);

    return 0;
}