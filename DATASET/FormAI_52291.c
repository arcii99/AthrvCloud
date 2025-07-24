//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: genious
#include <stdio.h>
#include <string.h>

//Function to analyze the sentiment of input string
void analyze_sentiment(char input_string[]) {
    int happy_count = 0, sad_count = 0, neutral_count = 0;
    char* words = strtok(input_string, " ");
    while(words != NULL) {
        if (strstr(words, "good") || strstr(words, "happy") || strstr(words, "joy") || strstr(words, "excited")) {
            happy_count++;
        } else if (strstr(words, "bad") || strstr(words, "sad") || strstr(words, "unhappy") || strstr(words, "miserable")) {
            sad_count++;
        } else {
            neutral_count++;
        }
        words = strtok(NULL, " ");
    }
    if (happy_count > sad_count) {
        printf("The sentiment of input string is positive\n");
    } else if (happy_count < sad_count) {
        printf("The sentiment of input string is negative\n");
    } else {
        printf("The sentiment of input string is neutral\n");
    }
}

//Driver code
int main() {
    char input_string[100];
    printf("Enter the input string: ");
    fgets(input_string, 100, stdin);
    printf("\n");
    analyze_sentiment(input_string);
    return 0;
}