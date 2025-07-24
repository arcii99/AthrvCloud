//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: light-weight
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// function to calculate the sentiment score of a sentence
int calculate_score(char sentence[]) {
    int score = 0;
    char *word;
    char *delim = " .,!?\n";
    
    // tokenize the sentence and calculate score for each word
    word = strtok(sentence, delim);
    while (word != NULL) {
        if (strcmp(word, "good") == 0 || strcmp(word, "great") == 0 || strcmp(word, "excellent") == 0) {
            score += 2;
        } else if (strcmp(word, "bad") == 0 || strcmp(word, "terrible") == 0 || strcmp(word, "awful") == 0) {
            score -= 2;
        } else if (strcmp(word, "not") == 0 || strcmp(word, "no") == 0 || strcmp(word, "neither") == 0) {
            score -= 1;
        } else if (strcmp(word, "very") == 0) {
            score += 1;
        }
        word = strtok(NULL, delim);
    }
    
    return score;
}

// function to make all characters lowercase
void strlwr(char str[]) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

int main() {
    char sentence[500];
    int sentiment_score;
    
    // prompt user for input sentence
    printf("Enter a sentence to analyze the sentiment: \n");
    fgets(sentence, 500, stdin);
    
    // make characters lowercase for easy comparison of words
    strlwr(sentence);
    
    // calculate sentiment score of the sentence
    sentiment_score = calculate_score(sentence);
    
    // print sentiment score and sentiment type
    if (sentiment_score > 0) {
        printf("Positive sentiment with score: %d\n", sentiment_score);
    } else if (sentiment_score < 0) {
        printf("Negative sentiment with score: %d\n", sentiment_score);
    } else {
        printf("Neutral sentiment\n");
    }
    
    return 0;
}