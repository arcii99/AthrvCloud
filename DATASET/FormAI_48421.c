//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Macro to calculate array size
#define ARR_SIZE(x) (sizeof(x) / sizeof(x[0]))

// Function to calculate sentiment score of a given word
int calc_sentiment_score(char* word) {
    int score = 0;
    int len = strlen(word);
    for (int i = 0; i < len; i++) {
        score += (int)word[i];
    }
    return score;
}

// Function to calculate overall sentiment score of a given sentence
int calc_sentence_sentiment_score(char* sentence) {
    int score = 0;
    char* word;

    // Split sentence into words using space as delimiter
    word = strtok(sentence, " ");
    while (word != NULL) {
        score += calc_sentiment_score(word);
        word = strtok(NULL, " ");
    }

    return score;
}

int main() {
    char sentences[][100] = {
        "I love coding",
        "Programming is difficult",
        "I hate bugs",
        "I am happy all the time",
        "This project is awesome",
        "I am feeling down today",
        "My computer crashed again",
        "I am so proud of myself",
        "I can't wait for the weekend",
        "This software is so buggy",
        "The weather is so nice today",
        "I am feeling so frustrated",
        "This meeting is going to be boring",
        "I am feeling so motivated",
        "I am having a bad day"
    };

    // Calculate sentiment score of each sentence and print result
    for (int i = 0; i < ARR_SIZE(sentences); i++) {
        int score = calc_sentence_sentiment_score(sentences[i]);
        printf("Sentence: %s \nScore: %d\n", sentences[i], score);
        printf("---------------------------\n");
    }

    return 0;
}