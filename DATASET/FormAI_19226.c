//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: surprised
#include <stdio.h>
#include <string.h>

// Function to calculate sentiment score of the input sentence
int sentimentScore(char sentence[]) {
    int len = strlen(sentence);
    int score = 0;
    for (int i = 0; i < len; i++) {
        if (sentence[i] == '!' || sentence[i] == '?') {
            score += 2;
        } else if (sentence[i] == '.') {
            score += 1;
        }
    }
    return score;
}

int main() {
    char sentence[100];
    printf("Hello! I am a sentiment analysis tool and I can help you determine the sentiment score of any sentence.\n");
    printf("Please enter a sentence (maximum length 100 characters):\n");
    scanf("%[^\n]s", sentence);

    int score = sentimentScore(sentence);
    printf("\nYour sentence \"%s\" has a sentiment score of %d.\n\n", sentence, score);
    if(score<0){
      printf("Oh no, seems like the sentence has negative sentiment..\n" );
    }else if(score==0){
      printf("Hmm, looks like the sentence has neutral sentiment..\n");
    }else{
      printf("Wow! This sentence looks so positive!\n");
    }
    return 0;
}