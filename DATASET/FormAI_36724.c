//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: retro
#include <stdio.h>
#include <string.h>

int main() {

    // Retro style sentiment analysis tool
    
    char userInput[1000];
    int sentimentScore = 0;

    printf("Enter a sentence to analyze: ");
    fgets(userInput, sizeof(userInput), stdin);

    // Remove newline character from user input
    userInput[strcspn(userInput, "\n")] = 0;

    // Convert all characters in user input to lowercase
    for (int i = 0; userInput[i]; i++) {
        userInput[i] = tolower(userInput[i]);
    }

    // Analyze user input and calculate sentiment score
    char *token = strtok(userInput, " ");
    while (token != NULL) {
        if (strcmp(token, "love") == 0) {
            sentimentScore += 5;
        } else if (strcmp(token, "like") == 0) {
            sentimentScore += 3;
        } else if (strcmp(token, "dislike") == 0) {
            sentimentScore -= 3;
        } else if (strcmp(token, "hate") == 0) {
            sentimentScore -= 5;
        } else {
            sentimentScore += 1;
        }
        token = strtok(NULL, " ");
    }

    // Determine sentiment based on sentiment score
    printf("\nSENTIMENT: ");
    if (sentimentScore >= 10) {
        printf("TOTALLY RAD\n");
    } else if (sentimentScore >= 5) {
        printf("PRETTY GOOD\n");
    } else if (sentimentScore >= 0) {
        printf("MIDDLE OF THE ROAD\n");
    } else if (sentimentScore >= -5) {
        printf("KINDA BAD\n");
    } else {
        printf("TOTALLY LAME\n");
    }

    return 0;
}