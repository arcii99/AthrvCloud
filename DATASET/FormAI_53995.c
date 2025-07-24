//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: cheerful
#include <stdio.h>

int main() {
    printf("Welcome to the Cheerful Sentiment Analysis Tool!\n");
    printf("Enter your text message to be analyzed: ");

    char input[1000];
    fgets(input, 1000, stdin);

    int sentiment_score = 0;

    for(int i = 0; input[i] != '\0'; i++) {
        if(input[i] == ':') {
            switch(input[i+1]) {
                case ')':
                    sentiment_score++;
                    break;
                case '(':
                    sentiment_score--;
                    break;
            }
        }
    }

    printf("\nYour message has a sentiment score of %d!\n", sentiment_score);

    if(sentiment_score > 0) {
        printf("Wow, you are feeling really happy! Keep smiling! :)\n");
    } else if(sentiment_score < 0) {
        printf("Oh no, you seem to be feeling a bit down. Don't worry, things will get better! :)\n");
    } else {
        printf("Looks like you are feeling pretty neutral right now. Keep on keeping on! :)\n");
    }

    return 0;
}