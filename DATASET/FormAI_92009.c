//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: relaxed
#include <stdio.h>
#include <string.h>

int main() {
    char sentence[100];
    int happy = 0, sad = 0, total = 0;
    float happiness_percentage;

    printf("Enter the sentence you want to analyze: ");
    fgets(sentence, 100, stdin);

    // Remove newline character from the input
    sentence[strlen(sentence)-1] = '\0';

    for (int i = 0; i < strlen(sentence); i++) {
        if (sentence[i] == ':') {
            if (sentence[i+1] == ')') {
                happy++;
            } else if (sentence[i+1] == '(') {
                sad++;
            }
        }
    }

    total = happy + sad;
    happiness_percentage = ((float)happy / total) * 100;

    printf("The sentence has %d happy faces and %d sad faces.\n", happy, sad);

    if (happy > sad) {
        printf("The sentence has a positive sentiment.\n");
    } else if (happy < sad) {
        printf("The sentence has a negative sentiment.\n");
    } else {
        printf("The sentence has a neutral sentiment.\n");
    }

    printf("The happiness percentage of the sentence is %.2f%%.\n", happiness_percentage);

    return 0;
}