//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: grateful
#include <stdio.h>
#include <string.h>

int main() {
    char phrase[100];
    int happy_counter = 0, sad_counter = 0, neutral_counter = 0;

    printf("Enter a phrase to analyze: ");
    fgets(phrase, 100, stdin);

    char* token = strtok(phrase, " ,.!?\n");

    while(token != NULL) {
        if(strncmp(token, "happy", 5) == 0) {
            happy_counter++;
        } else if(strncmp(token, "sad", 3) == 0) {
            sad_counter++;
        } else {
            neutral_counter++;
        }

        token = strtok(NULL, " ,.!?\n");
    }

    printf("\nSentiment Analysis Results:\n");
    printf("Happy: %d\n", happy_counter);
    printf("Sad: %d\n", sad_counter);
    printf("Neutral: %d\n", neutral_counter);

    return 0;
}