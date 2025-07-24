//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: beginner-friendly
#include <stdio.h>
#include <string.h>

#define POSITIVE 1
#define NEGATIVE 0

int sentiment_analysis(char *input_text)
{
    int positive_score = 0, negative_score = 0;
    char *positive_words[] = {"good", "happy", "love", "awesome", "amazing"};
    char *negative_words[] = {"bad", "sad", "hate", "terrible", "awful"};

    char *token = strtok(input_text, " ");

    while (token != NULL) {
        for (int i = 0; i < 5; i++) {
            if (strcmp(token, positive_words[i]) == 0) {
                positive_score++;
            }
            if (strcmp(token, negative_words[i]) == 0) {
                negative_score++;
            }
        }

        token = strtok(NULL, " ");
    }

    if (positive_score > negative_score) {
        return POSITIVE;
    } else {
        return NEGATIVE;
    }
}

int main()
{
    char input_text[100];

    printf("Enter some text to analyze: ");
    fgets(input_text, 100, stdin);

    int result = sentiment_analysis(input_text);

    if (result == POSITIVE) {
        printf("The sentiment of the text is positive.\n");
    } else {
        printf("The sentiment of the text is negative.\n");
    }

    return 0;
}