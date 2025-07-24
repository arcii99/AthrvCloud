//FormAI DATASET v1.0 Category: Spam Detection System ; Style: modular
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_TEXT_LENGTH 1000   // Maximum length of text
#define SPAM_THRESHOLD 0.8     // The threshold to classify a text as spam

// Function to calculate the percentage of spam words in a text
double calculateSpamPercentage(char text[MAX_TEXT_LENGTH]) {
    char *spamWords[] = {"buy", "discount", "money", "free", "offer", "guarantee", "credit", "click", "limited"};

    int spamCount = 0, totalWords = 0;

    // Tokenize the text into words
    char *word = strtok(text, " ");
    while (word != NULL) {
        // Convert word to lowercase for case-insensitive comparison
        for (int i = 0; word[i]; i++) {
            word[i] = tolower(word[i]);
        }

        // Check if the word exists in spamWords array
        for (int i = 0; i < sizeof(spamWords)/sizeof(spamWords[0]); i++) {
            if (strcmp(word, spamWords[i]) == 0) {
                spamCount++;
                break;
            }
        }

        totalWords++;
        word = strtok(NULL, " ");
    }

    return (double)spamCount/totalWords;
}

int main() {
    char text[MAX_TEXT_LENGTH];

    printf("Enter a text: ");
    fgets(text, MAX_TEXT_LENGTH, stdin);
    text[strcspn(text, "\n")] = '\0';    // Remove the newline character at the end of input

    double spamPercentage = calculateSpamPercentage(text);

    if (spamPercentage >= SPAM_THRESHOLD) {
        printf("This text is classified as SPAM (spam percentage: %.2f%%)\n", spamPercentage*100);
    } else {
        printf("This text is NOT classified as spam (spam percentage: %.2f%%)\n", spamPercentage*100);
    }

    return 0;
}