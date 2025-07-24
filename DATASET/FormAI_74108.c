//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: single-threaded
#include <stdio.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 20

int main() {
    char text[1000];
    int positiveCount = 0, negativeCount = 0;
    const char *positiveWords[MAX_WORDS] = 
        {"happy", "loved", "great", "awesome", "win", "success", "pleasure", "good"};
    const char *negativeWords[MAX_WORDS] = 
        {"hate", "angry", "bad", "fail", "disappointed", "worst", "pain", "sad"};

    // read input text
    printf("Enter text to analyze: ");
    fgets(text, 1000, stdin);

    // split input text into words
    int wordCount = 0;
    char *tempWord = strtok(text, " .,\n");
    char words[MAX_WORDS][MAX_WORD_LENGTH];
    while(tempWord != NULL) {
        strcpy(words[wordCount], tempWord);
        wordCount++;
        tempWord = strtok(NULL, " .,\n");
    }

    // analyze sentiments
    for(int i=0; i<wordCount; i++) {
        for(int j=0; j<MAX_WORDS; j++) {
            if(strcmp(words[i], positiveWords[j]) == 0) {
                positiveCount++;
            }
            if(strcmp(words[i], negativeWords[j]) == 0) {
                negativeCount++;
            }
        }
    }

    // print sentiment analysis
    printf("\nSentiment analysis:\n");
    printf("Positive words found: %d\n", positiveCount);
    printf("Negative words found: %d\n", negativeCount);
    if(positiveCount > negativeCount) {
        printf("Overall sentiment: Positive\n");
    }
    else if(negativeCount > positiveCount) {
        printf("Overall sentiment: Negative\n");
    }
    else {
        printf("Overall sentiment: Neutral\n");
    }

    return 0;
}