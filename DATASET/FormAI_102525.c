//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: Alan Touring
#include <stdio.h>
#include <string.h>

int main() {

    char sentence[100];
    int positiveWords = 0;
    int negativeWords = 0;
    int totalWords = 0;
    double positivityScore = 0;
    double negativityScore = 0;
    double overallScore = 0;

    printf("Enter a sentence to analyze: ");
    fgets(sentence, 100, stdin);

    char *word = strtok(sentence, " ");
    while (word != NULL) {
        totalWords++;

        if (strstr("good great excellent love like", word)) {
            positiveWords++;
            positivityScore += 0.5; // assign score of 0.5 to positive words
        } else if (strstr("bad terrible awful hate dislike", word)) {
            negativeWords++;
            negativityScore += 0.5; // assign score of 0.5 to negative words
        }
        word = strtok(NULL, " ");
    }

    overallScore = (positivityScore - negativityScore) / totalWords;

    if (overallScore > 0) {
        printf("The sentence is positive with a score of %.2f\n", overallScore);
    } else if (overallScore < 0) {
        printf("The sentence is negative with a score of %.2f\n", overallScore);
    } else {
        printf("The sentence is neutral with a score of 0\n");
    }

    return 0;
}