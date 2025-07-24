//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: protected
#include <stdio.h>
#include <string.h>

char* get_sentiment(char* input) {
    char* sentiment;
    int positivity_count = 0;
    int negativity_count = 0;
    char* token = strtok(input, " ");

    while (token != NULL) {
        if (strcmp(token, "happy") == 0 || strcmp(token, "joyful") == 0 || strcmp(token, "excited") == 0 || strcmp(token, "pleased") == 0 || strcmp(token, "satisfied") == 0) {
            positivity_count++;
        } else if (strcmp(token, "upset") == 0 || strcmp(token, "disappointed") == 0 || strcmp(token, "angry") == 0 || strcmp(token, "frustrated") == 0 || strcmp(token, "sad") == 0) {
            negativity_count++;
        }

        token = strtok(NULL, " ");
    }

    if (positivity_count > negativity_count) {
        sentiment = "positive";
    } else if (negativity_count > positivity_count) {
        sentiment = "negative";
    } else {
        sentiment = "neutral";
    }

    return sentiment;
}

int main() {
    char input[1000];

    printf("Enter your sentence: ");
    fgets(input, sizeof(input), stdin);

    // Remove newline character at the end of input string
    input[strlen(input) - 1] = '\0';

    char* sentiment = get_sentiment(input);

    printf("Sentiment of the sentence is %s\n", sentiment);

    return 0;
}