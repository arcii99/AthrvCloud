//FormAI DATASET v1.0 Category: Spam Detection System ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SPAM_COUNT 5

int main() {

    printf("Welcome to the Spam Detection System!\n");

    char input[500];
    char spamWords[MAX_SPAM_COUNT][20] = {"money", "offer", "prize", "win", "free"};
    int spamScores[MAX_SPAM_COUNT] = {5, 4, 3, 2, 1};
    int totalScore = 0;
    int wordCount = 0;
    int i, j;
    int isSpam = 0;

    printf("Enter your message (max 500 characters):\n");
    fgets(input, 500, stdin);
    input[strcspn(input, "\n")] = '\0';

    // Calculate spam score
    char* token = strtok(input, " ");    
    while (token != NULL) {
        for (i = 0; i < MAX_SPAM_COUNT; i++) {
            if (strstr(token, spamWords[i])) {
                totalScore += spamScores[i];
                isSpam = 1;
            }
        }
        wordCount++;
        token = strtok(NULL, " ");
    }

    // Check if message is spam
    if (isSpam) {
        printf("This message has been detected as spam! Score: %d\n", totalScore);
    } else {
        printf("This message is not spam. Word count: %d\n", wordCount);
    }

    return 0;
}