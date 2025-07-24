//FormAI DATASET v1.0 Category: Text Summarizer ; Style: intelligent
#include <stdio.h>
#include <string.h>

char* summarizeText(char* text, int summaryLength) {
    int textLength = strlen(text);
    int finalLength = summaryLength + 3;
    if (textLength <= finalLength) {
        return text;
    }
    char* summary = malloc(finalLength * sizeof(char));
    strncpy(summary, text, summaryLength);
    summary[summaryLength] = '.';
    summary[summaryLength + 1] = '.';
    summary[summaryLength + 2] = '.';
    summary[summaryLength + 3] = '\0';
    int lastWordIndex = summaryLength;
    while (lastWordIndex > 0 && summary[lastWordIndex] != ' ') {
        lastWordIndex--;
    }
    if (lastWordIndex > 0) {
        summary[lastWordIndex] = '.';
        summary[lastWordIndex + 1] = '.';
        summary[lastWordIndex + 2] = '.';
        summary[lastWordIndex + 3] = '\0';
    }
    return summary;
}

int main() {
    char* text = "It was the best of times, it was the worst of times, it was the age of wisdom, it was the age of foolishness";
    int summaryLength = 20;
    char* summary = summarizeText(text, summaryLength);
    printf("Original Text: %s\n", text);
    printf("Summarized Text: %s\n", summary); 
    free(summary);
    return 0;
}