//FormAI DATASET v1.0 Category: Text Summarizer ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUMMARY_SIZE 100

char* summarizeText(char* text) {
    int i, sentenceCount = 0, summaryLength = 0;
    char* summary = (char*) malloc(MAX_SUMMARY_SIZE * sizeof(char));
    char* token, *sentences[50];
    token = strtok(text, ".");
    
    while(token != NULL) {
        sentences[sentenceCount] = token;
        sentenceCount++;
        token = strtok(NULL, ".");
    }
    
    for(i=0; i< sentenceCount; i++) {
        summaryLength += strlen(sentences[i]);
        
        if(summaryLength > MAX_SUMMARY_SIZE) break;
        
        strcat(summary, sentences[i]);
        strcat(summary, ".");
    }
    
    return summary;
}

int main() {
    char text[500], *summary;
    printf("Enter the text to summarize: ");
    fgets(text, 500, stdin);
    
    summary = summarizeText(text);
    printf("Summary: %s", summary);
    free(summary);
    
    return 0;
}