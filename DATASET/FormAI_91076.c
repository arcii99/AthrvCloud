//FormAI DATASET v1.0 Category: Text Summarizer ; Style: high level of detail
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main() {
    char text[1000], summary[1000], *token;
    int i, numOfWords = 0, numOfSentences = 0, summaryLength = 0;
    float avgSentenceLength;
    
    // Get user input
    printf("Enter the text to be summarized:\n");
    fgets(text, 1000, stdin);
    
    // Tokenize and count number of words and sentences
    token = strtok(text, " ,.<>/?;:\"'!@#$%^&*()_+=-[]{}\\|`~");
    while(token != NULL) {
        numOfWords++;
        if(strchr(".!?", token[strlen(token) - 1]) != NULL) {
            numOfSentences++;
        }
        token = strtok(NULL, " ,.<>/?;:\"'!@#$%^&*()_+=-[]{}\\|`~");
    }
    
    // Calculate average sentence length
    avgSentenceLength = (float) numOfWords / (float) numOfSentences;
    
    // Summarize the text based on average sentence length
    token = strtok(text, " .!?");
    while(token != NULL) {
        summaryLength += strlen(token);
        strcat(summary, token);
        strcat(summary, " ");
        if(summaryLength >= (int) (avgSentenceLength * 3)) {
            break;
        }
        token = strtok(NULL, " .!?");
    }
    
    // Print the summary
    printf("Summary:\n%s\n", summary);
    
    return 0;
}