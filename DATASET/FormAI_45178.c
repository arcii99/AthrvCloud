//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: cheerful
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to count the number of words in a string
int countWords(char *str) {
    int count = 0;
    for(int i = 0; str[i]; i++) {
        if(!isspace(str[i + 1]) && isspace(str[i])) {
            count++;
        }
    }
    return count + 1;
}

// Function to convert a string to lowercase
char* tolowercase(char *str) {
    for(int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
    return str;
}

int main() {
    char sentence[1000];
    printf("Enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin);
    printf("\n");

    // Count the number of words in the sentence
    int numWords = countWords(sentence);
    printf("Number of words: %d\n", numWords);

    // Convert the sentence to lowercase
    tolowercase(sentence);

    // Analyze the sentiment of the sentence
    int happyCount = 0, sadCount = 0;
    char *happyWords[5] = {"happy", "joyful", "excited", "ecstatic", "glad"};
    char *sadWords[5] = {"sad", "depressed", "miserable", "upset", "heartbroken"};

    char *word = strtok(sentence, " ");
    while(word != NULL) {
        for(int i = 0; i < 5; i++) {
            if(strcmp(word, happyWords[i]) == 0) {
                happyCount++;
            }
            if(strcmp(word, sadWords[i]) == 0) {
                sadCount++;
            }
        }
        word = strtok(NULL, " ");
    }

    printf("\nSentiment Analysis Results:\n");
    printf("------------------------------\n");
    printf("Number of happy words: %d\n", happyCount);
    printf("Number of sad words: %d\n", sadCount);

    if(happyCount > sadCount) {
        printf("\nOverall Sentiment: Cheerful!\n");
    } else if(sadCount > happyCount) {
        printf("\nOverall Sentiment: Sad :(\n");
    } else {
        printf("\nOverall Sentiment: Neutral\n");
    }

    return 0;
}