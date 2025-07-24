//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: authentic
#include <stdio.h>
#include <string.h>

// Function to determine sentiment score of each word in the sentence
int getScore(char *word) {
    int score = 0;
    
    // List of positive words
    char *positiveWords[] = {"happy", "excited", "love", "fun", "good", "great"};
    int positiveWordsCount = sizeof(positiveWords) / sizeof(positiveWords[0]);
    
    // List of negative words
    char *negativeWords[] = {"sad", "angry", "hate", "boring", "bad", "terrible"};
    int negativeWordsCount = sizeof(negativeWords) / sizeof(negativeWords[0]);
    
    // Check if given word is in positive words list
    for (int i=0; i<positiveWordsCount; i++) {
        if (strcmp(word, positiveWords[i]) == 0) {
            score = 1;
            break;
        }
    }
    
    // If word is not in positive words list, check if it is in negative words list
    if (score == 0) {
        for (int i=0; i<negativeWordsCount; i++) {
            if (strcmp(word, negativeWords[i]) == 0) {
                score = -1;
                break;
            }
        }
    }
    
    return score;
}

int main() {
    char sentence[100];
    printf("Enter a sentence: ");
    fgets(sentence, 100, stdin);
    sentence[strcspn(sentence, "\n")] = 0; // Remove newline character from input
    
    char *token = strtok(sentence, " "); // Tokenize sentence by space
    int totalScore = 0;
    
    // Loop through all tokens in the sentence
    while (token != NULL) {
        int tokenScore = getScore(token);
        totalScore += tokenScore;
        token = strtok(NULL, " ");
    }
    
    // Determine overall sentiment of the sentence based on totalScore
    if (totalScore > 0) {
        printf("The sentiment of the sentence is positive.\n");
    } else if (totalScore < 0) {
        printf("The sentiment of the sentence is negative.\n");
    } else {
        printf("The sentiment of the sentence is neutral.\n");
    }
    
    return 0;
}