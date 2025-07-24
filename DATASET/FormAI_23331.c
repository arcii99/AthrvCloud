//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: happy
#include <stdio.h>
#include <string.h>

int main() {
    char sentence[1000];
    int i, happyCount=0, sadCount=0;
    printf("Welcome to the Happy or Sad Sentiment Analysis Tool!\n");
    printf("Please enter a sentence: ");
    fgets(sentence, 1000, stdin);

    //Splitting the sentence by space to count happy or sad words
    char* word = strtok(sentence, " ");
    while (word != NULL) {
        //Checking if the word is indicative of happiness
        if (strcmp(word, "love") == 0 || strcmp(word, "happy") == 0 || strcmp(word, "joyful") == 0 || strcmp(word, "excited") == 0 || strcmp(word, "amazing") == 0) {
            happyCount++;
        }
        //Checking if the word is indicative of sadness
        else if (strcmp(word, "hate") == 0 || strcmp(word, "sad") == 0 || strcmp(word, "regret") == 0 || strcmp(word, "depressed") == 0 || strcmp(word, "alone") == 0) {
            sadCount++;
        }
        word = strtok(NULL, " ");
    }

    //Displaying the sentiment of the sentence
    printf("\n\nThe sentiment of the sentence is: ");
    if (happyCount > sadCount) {
        printf("Happy\n");
    }
    else if (happyCount < sadCount) {
        printf("Sad\n");
    }
    else {
        printf("Neutral\n");
    }
    return 0;
}