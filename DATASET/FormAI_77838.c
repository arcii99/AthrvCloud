//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char input[100];
    int sentiment = 0;
    int i;

    printf("Enter the text for sentiment analysis:\n");
    fgets(input, 100, stdin);

    for(i=0; i<strlen(input); i++) {
        char current = input[i];
        if(current == ' ') {
            continue;
        } else if(current == '.') {
            sentiment += 2;
        } else if(current == '!') {
            sentiment += 3;
        } else if(current == '?') {
            sentiment += 1;
        } else if(current == 'h') {
            if(input[i+1] == 'a' && input[i+2] == 't' && input[i+3] == 'e') {
                sentiment -= 5;
                i += 3;
            }
        } else if(current == 'l') {
            if(input[i+1] == 'o' && input[i+2] == 'v' && input[i+3] == 'e') {
                sentiment += 4;
                i += 3;
            }
        }
    }

    if(sentiment > 10) {
        printf("Overall sentiment is extremely positive!\n");
    } else if(sentiment > 5 && sentiment <= 10) {
        printf("Overall sentiment is positive.\n");
    } else if(sentiment >= 0 && sentiment <= 5) {
        printf("Overall sentiment is neutral.\n");
    } else if(sentiment >= -5 && sentiment < 0) {
        printf("Overall sentiment is negative.\n");
    } else if(sentiment < -5) {
        printf("Overall sentiment is extremely negative...\n");
    }

    return 0;
}