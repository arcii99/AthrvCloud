//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char input[1000]; // Set maximum input length
    printf("Enter text to analyze sentiment: ");
    fgets(input, sizeof(input), stdin); // Read user input

    int happiness = 0, sadness = 0, anger = 0, fear = 0; // Initialize sentiment scores

    // Define happy words
    char happyWords[20][20] = {"happy", "joyful", "excited", "thrilled", "delighted", "merry", "ecstatic", "content", "pleased", "glad", "elated", "enjoyment", "jubilant", "blissful", "grateful", "satisfied", "upbeat", "gleeful", "amused", "overjoyed"};
    int happyCount = sizeof(happyWords) / sizeof(happyWords[0]);

    // Define sad words
    char sadWords[20][20] = {"sad", "depressed", "unhappy", "miserable", "downhearted", "gloomy", "despair", "heartbroken", "blue", "bereaved", "tearful", "woeful", "melancholic", "sorrowful", "dejected", "crestfallen", "forlorn", "regretful", "disappointed", "ailing"};
    int sadCount = sizeof(sadWords) / sizeof(sadWords[0]);

    // Define angry words
    char angryWords[20][20] = {"angry", "furious", "outraged", "irritated", "outright", "infuriated", "annoyed", "exasperated", "fuming", "offended", "resentful", "aggravated", "irksome", "bothered", "enflamed", "maddened", "irritable", "indignant", "provoked", "bitter"};
    int angryCount = sizeof(angryWords) / sizeof(angryWords[0]);

    // Define fear words
    char fearWords[20][20] = {"fear", "scared", "anxious", "worried", "petrified", "uneasy", "nervous", "dreadful", "horrified", "frightened", "fearful", "terror", "spooky", "terrified", "jittery", "panicked", "intimidated", "shaken", "paranoid", "creeped"};
    int fearCount = sizeof(fearWords) / sizeof(fearWords[0]);

    // Tokenize input words
    char *token = strtok(input, " ,.\n");
    while (token != NULL) {
        // Check for happy words
        for (int i = 0; i < happyCount; i++) {
            if (strcasecmp(token, happyWords[i]) == 0) {
                happiness++;
                break;
            }
        }

        // Check for sad words
        for (int i = 0; i < sadCount; i++) {
            if (strcasecmp(token, sadWords[i]) == 0) {
                sadness++;
                break;
            }
        }

        // Check for angry words
        for (int i = 0; i < angryCount; i++) {
            if (strcasecmp(token, angryWords[i]) == 0) {
                anger++;
                break;
            }
        }

        // Check for fear words
        for (int i = 0; i < fearCount; i++) {
            if (strcasecmp(token, fearWords[i]) == 0) {
                fear++;
                break;
            }
        }

        token = strtok(NULL, " ,.\n"); // Move to next word
    }

    // Determine sentiment based on scores
    printf("\nSentiment analysis:\n");
    if (happiness > sadness && happiness > anger && happiness > fear) {
        printf("The sentiment of the text is Happy.");
    } else if (sadness > happiness && sadness > anger && sadness > fear) {
        printf("The sentiment of the text is Sad.");
    } else if (anger > happiness && anger > sadness && anger > fear) {
        printf("The sentiment of the text is Angry.");
    } else if (fear > happiness && fear > sadness && fear > anger) {
        printf("The sentiment of the text is Fearful.");
    } else {
        printf("The sentiment of the text is Neutral.");
    }

    return 0;
}