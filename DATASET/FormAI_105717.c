//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: happy
#include <stdio.h>
#include <string.h>

/* Function to determine sentiment of a string */
char* sentimentAnalysis(char *str) {
    int n = strlen(str);
    int positiveWords = 0, negativeWords = 0;
    /* List of positive and negative words */
    char positiveList[10][20] = {"good", "great", "awesome", "happy", "love", "excellent", "fantastic", "amazing", "fun", "nice"};
    char negativeList[10][20] = {"bad", "horrible", "terrible", "unhappy", "hate", "awful", "disappointing", "annoying", "dislike", "painful"};
    char *word;
    /* Splitting the string into words */
    word = strtok(str, " .,");
    while(word != NULL) {
        /* Checking if word is present in the positive or negative list */
        for(int i=0; i<10; i++) {
            if(strcasecmp(word, positiveList[i]) == 0) {
                positiveWords++;
                break;
            }
            else if(strcasecmp(word, negativeList[i]) == 0) {
                negativeWords++;
                break;
            }
        }
        word = strtok(NULL, " .,");
    }
    /* Determining the sentiment of the string */
    if(positiveWords > negativeWords)
        return "Positive";
    else if (positiveWords < negativeWords)
        return "Negative";
    else
        return "Neutral";
}

int main() {
    char str[100];
    printf("Enter a sentence: ");
    fgets(str, 100, stdin);
    /* Removing the newline character */
    str[strcspn(str, "\n")] = 0;
    char* sentiment = sentimentAnalysis(str);
    printf("The sentiment of the sentence is %s!", sentiment);
    return 0;
}