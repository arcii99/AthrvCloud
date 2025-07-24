//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: interoperable
#include <stdio.h>
#include <string.h>

int main(){
    char input[500];
    int positiveWordsCount = 0, negativeWordsCount = 0;
    char positiveWords[][30] = {"happy", "love", "peace", "wonderful", "amazing", "excellent", "great", "good", "success", "awesome"};
    char negativeWords[][30] = {"hate", "angry", "kill", "war", "no", "fail", "bad", "terrible", "worst", "disgusting"};

    printf("Enter your text: ");
    fgets(input, sizeof(input), stdin); // read user input

    char *word = strtok(input, " "); // get first word

    // loop through all words in the user input text
    while (word != NULL) {
        int isPositive = 0, isNegative = 0;

        // check if the current word is a positive or negative word
        for (int i = 0; i < 10; i++) {
            if (strcmp(word, positiveWords[i]) == 0){
                isPositive = 1;
                break;
            }

            if (strcmp(word, negativeWords[i]) == 0){
                isNegative = 1;
                break;
            }
        }

        // increment the positive/negative word count depending on the current word
        if (isPositive){
            positiveWordsCount++;
        }

        if (isNegative){
            negativeWordsCount++;
        }

        word = strtok(NULL, " "); // get next word
    }

    // calculate overall sentiment score
    int sentimentScore = positiveWordsCount - negativeWordsCount;

    printf("\nSentiment analysis result:\n");
    printf("Positive words count: %d\n", positiveWordsCount);
    printf("Negative words count: %d\n", negativeWordsCount);

    if (sentimentScore > 0){
        printf("Overall sentiment score: %d (Positive)\n", sentimentScore);
    }
    else if (sentimentScore == 0){
        printf("Overall sentiment score: %d (Neutral)\n", sentimentScore);
    }
    else{
        printf("Overall sentiment score: %d (Negative)\n", sentimentScore);
    }

    return 0;
}