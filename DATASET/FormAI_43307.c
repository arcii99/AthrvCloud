//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char input[1000];
    int positiveWords = 0, negativeWords = 0, neutralWords = 0;

    // Open the sentiment dictionary file
    FILE *file = fopen("sentiments.txt", "r");
    if (file == NULL) {
        printf("Error opening sentiment dictionary file.\n");
        return 1;
    }

    // Read each line of the input text and check sentiment
    printf("Enter the text to analyze:\n");
    scanf("%[^\n]%*c", input);

    char *word = strtok(input, " ");
    while (word != NULL) {
        fseek(file, 0, SEEK_SET); // Reset file pointer to beginning
        char line[100];
        while (fgets(line, sizeof(line), file)) {
            line[strcspn(line, "\r\n")] = 0; // Remove new line character
            if (strstr(word, line) != NULL) {
                if (strstr(line, "Positive") != NULL) {
                    positiveWords++;
                } else if (strstr(line, "Negative") != NULL) {
                    negativeWords++;
                } else {
                    neutralWords++;
                }
            }
        }
        word = strtok(NULL, " ");
    }

    // Close the sentiment dictionary file
    fclose(file);

    // Print the sentiment analysis results
    printf("\nSentiment analysis results:\n");
    if (positiveWords + negativeWords == 0) {
        printf("Cannot determine sentiment from input.\n");
    } else if (positiveWords > negativeWords) {
        double positivePercentage = (double) positiveWords / (double) (positiveWords + negativeWords + neutralWords) * 100.0;
        printf("Positive sentiment detected. Positive words: %d, Negative words: %d, Neutral words: %d, Positive percentage: %.2f%%\n", positiveWords, negativeWords, neutralWords, positivePercentage);
    } else {
        double negativePercentage = (double) negativeWords / (double) (positiveWords + negativeWords + neutralWords) * 100.0;
        printf("Negative sentiment detected. Positive words: %d, Negative words: %d, Neutral words: %d, Negative percentage: %.2f%%\n", positiveWords, negativeWords, neutralWords, negativePercentage);
    }

    return 0;
}