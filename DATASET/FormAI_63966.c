//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to convert all the alphabets to lowercase
void convertToLowercase(char *str) {
    int i = 0;
    while(str[i]) {
        str[i] = tolower(str[i]);
        i++;
    }
}

// function to remove the punctuation marks from the string
void removePunctuationMarks(char *str) {
    int len = strlen(str), i = 0;
    for (i = 0; i < len; i++) {
        if (ispunct(str[i])) {
            int j = i;
            while (j < len) {
                str[j] = str[j + 1];
                j++;
            }
            len--;
            i--;
        }
    }
}

// function to get the sentiment score of the sentence
int getSentimentScore(char *str, char **positiveWords, char **negativeWords, int posCount, int negCount) {
    int score = 0, i = 0;

    // tokenize the string
    char *token = strtok(str, " ");
    while (token != NULL) {
        convertToLowercase(token);
        removePunctuationMarks(token);

        // check if the token is present in the positive or negative words list
        for (i = 0; i < posCount; i++) {
            if (strcmp(token, positiveWords[i]) == 0) {
                score++;
                break;
            }
        }

        for (i = 0; i < negCount; i++) {
            if (strcmp(token, negativeWords[i]) == 0) {
                score--;
                break;
            }
        }

        // move to the next token
        token = strtok(NULL, " ");
    }

    return score;
}

int main(void) {
    // positive and negative words list
    char *positiveWords[] = {"happy", "joy", "love", "excited", "wonderful"};
    char *negativeWords[] = {"sad", "angry", "hate", "disappointed", "terrible"};

    // input sentence
    char sentence[100];
    printf("Enter a sentence: ");
    fgets(sentence, 100, stdin);

    // get the sentiment score
    int posCount = sizeof(positiveWords) / sizeof(char *);
    int negCount = sizeof(negativeWords) / sizeof(char *);
    int score = getSentimentScore(sentence, positiveWords, negativeWords, posCount, negCount);

    // display the sentiment score to the user
    if (score > 0) {
        printf("The sentence is positive with a score of %d\n", score);
    } else if (score < 0) {
        printf("The sentence is negative with a score of %d\n", score);
    } else {
        printf("The sentence is neutral\n");
    }

    return 0;
}