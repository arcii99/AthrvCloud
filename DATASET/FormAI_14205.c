//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to calculate the sentiment score of a text
int calculate_sentiment_score(char* text) {
    int score = 0;
    char* word;
    const char delimiters[] = " .,?!-";
    word = strtok(text, delimiters);
    while (word != NULL) {
        if (strcmp(word, "happy") == 0 || strcmp(word, "cheerful") == 0 ||
            strcmp(word, "joyful") == 0 || strcmp(word, "delighted") == 0) {
            score += 5;
        }
        else if (strcmp(word, "sad") == 0 || strcmp(word, "depressed") == 0 ||
                 strcmp(word, "miserable") == 0 || strcmp(word, "gloomy") == 0) {
            score -= 5;
        }
        else if (strcmp(word, "good") == 0 || strcmp(word, "great") == 0 ||
                 strcmp(word, "fantastic") == 0 || strcmp(word, "excellent") == 0) {
            score += 2;
        }
        else if (strcmp(word, "bad") == 0 || strcmp(word, "awful") == 0 ||
                 strcmp(word, "terrible") == 0 || strcmp(word, "poor") == 0) {
            score -= 2;
        }
        word = strtok(NULL, delimiters);
    }
    return score;
}

// Main function
int main() {
    char text[1000];
    printf("Welcome to our cheerful sentiment analysis tool!\n");
    printf("Please enter the text for which you want to calculate the sentiment score:\n");
    fgets(text, sizeof(text), stdin);
    // Remove the trailing newline character from the input
    text[strcspn(text, "\n")] = 0;
    int score = calculate_sentiment_score(text);
    printf("The sentiment score of the text is: %d\n", score);
    if (score > 0) {
        printf("That's great! You seem to be feeling really positive today.\n");
    } else if (score < 0) {
        printf("Oh no! It looks like you're feeling a bit down today.\n");
    } else {
        printf("Hmm, it seems neutral. That's alright, we hope you have a good day!\n");
    }
    return 0;
}