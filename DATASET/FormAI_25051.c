//FormAI DATASET v1.0 Category: Text Summarizer ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SENTENCES 50
#define MAX_CHARACTERS 500

char* summarize(char* text) {

    // Variables
    int i, j, k, linesCount = 0;
    double averageLength = 0;
    char* summary = (char*)malloc(MAX_CHARACTERS * sizeof(char));
    char* lines[MAX_SENTENCES];
    
    // Splitting the text into a list of sentences
    lines[0] = strtok(text, ".\n\t");
    while (lines[linesCount] != NULL) {
        linesCount++;
        lines[linesCount] = strtok(NULL, ".\n\t");
    }
    
    // Calculating the average length of a sentence
    for (i = 0; i < linesCount; i++) {
        j = 0;
        while (lines[i][j] != '\0') j++;
        averageLength += (double) j / (double) linesCount;
    }
    
    // Generating the summary
    k = 0;
    for (i = 0; i < linesCount; i++) {
        j = 0;
        while (lines[i][j] != '\0') {
            if (lines[i][j] != ' ' && lines[i][j] != '\n' && lines[i][j] != '\t') {
                summary[k++] = lines[i][j];
            }
            j++;
        }
        if (j <= (int) (averageLength * 1.5)) {
            summary[k++] = '.';
            summary[k++] = ' ';
        }
    }
    
    // Adding a final period if there isn't one
    if (summary[k - 2] != '.') {
        summary[k++] = '.';
        summary[k++] = ' ';
    }
    summary[k] = '\0';
    
    // Returning the summary
    return summary;
}

// Main function
int main() {
    
    // Input text
    char* text = "I am a grateful chatbot. I always try to help you in any way I can. I am programmed to assist you with tasks, answer questions, and provide information. If you need anything, just ask me! I am a bot designed to serve you, and I take pride in being able to do so. Thank you for using my services!";
    
    // Generating the summary
    char* summary = summarize(text);
    
    // Printing the summary
    printf("%s", summary);
    
    // Freeing the memory
    free(summary);
    
    // Returning 0
    return 0;
}