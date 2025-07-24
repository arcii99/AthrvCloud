//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: random
#include <stdio.h>
#include <ctype.h>

int main() {
    char input[100];
    int i=0, positiveCount=0, negativeCount=0, neutralCount=0;
    float positivePercent, negativePercent, neutralPercent;
    
    printf("Enter the text you want to analyze:");
    fgets(input, 100, stdin);
    
    while(input[i]!='\0' && input[i]!='\n') {
        if(isalpha(input[i])) {
            if(tolower(input[i])=='g' && tolower(input[i+1])=='o' && tolower(input[i+2])=='o' && tolower(input[i+3])=='d') {
                positiveCount++;
            } else if(tolower(input[i])=='b' && tolower(input[i+1])=='a' && tolower(input[i+2])=='d') {
                negativeCount++;
            } else {
                neutralCount++;
            }
        }
        i++;
    }
    
    int totalWords = positiveCount + negativeCount + neutralCount;
    
    if(totalWords==0) {
        printf("No words found for analyzing.");
    } else {
        positivePercent = ((float)positiveCount/totalWords)*100;
        negativePercent = ((float)negativeCount/totalWords)*100;
        neutralPercent = ((float)neutralCount/totalWords)*100;

        printf("\nAnalysis Report:\n");
        printf("Total Words: %d\n", totalWords);
        printf("Positive Words: %d (%.2f%%)\n", positiveCount, positivePercent);
        printf("Negative Words: %d (%.2f%%)\n", negativeCount, negativePercent);
        printf("Neutral Words: %d (%.2f%%)\n", neutralCount, neutralPercent);

        if(positivePercent > negativePercent && positivePercent > neutralPercent) {
            printf("\nOverall Sentiment: Positive");
        } else if(negativePercent > positivePercent && negativePercent > neutralPercent) {
            printf("\nOverall Sentiment: Negative");
        } else {
            printf("\nOverall Sentiment: Neutral");
        }
    }
    return 0;
}