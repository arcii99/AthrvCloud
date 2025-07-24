//FormAI DATASET v1.0 Category: Text Summarizer ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DOC_LEN 1000
#define MAX_SUMMARY_LEN 200

// Function to check if a character is a sentence terminator
int isSentenceTerminator(char c) {
    if(c == '.' || c == '!' || c == '?') {
        return 1;
    }
    return 0;
}

int main() {
    char doc[MAX_DOC_LEN]; // Document to summarize
    char summary[MAX_SUMMARY_LEN] = ""; // Summary of the document
    int sentenceCount = 0, summaryCount = 0;
    int i, j;
    
    // Get the document from the user
    printf("Enter the document to summarize (max %d characters):\n", MAX_DOC_LEN);
    fgets(doc, MAX_DOC_LEN, stdin);
    
    // Loop through the document and count the number of sentences
    for(i = 0; i < strlen(doc); i++) {
        if(isSentenceTerminator(doc[i])) {
            sentenceCount++;
        }
    }

    // Determine the number of sentences to include in the summary
    int summarySentenceCount = sentenceCount/2;
    
    // Loop through the document again and extract the summary
    for(i = 0; i < strlen(doc); i++) {
        if(isSentenceTerminator(doc[i])) {
            // Add the sentence terminator to the summary
            summary[summaryCount++] = doc[i];
            
            // Count the number of sentences added to the summary so far
            int sentencesAdded = 0;
            for(j = i+1; j < strlen(doc); j++) {
                if(isSentenceTerminator(doc[j])) {
                    sentencesAdded++;
                }
                if(sentencesAdded == summarySentenceCount) {
                    // Add the remaining characters to the summary
                    strncat(summary, &doc[i+1], j-i-1);
                    summaryCount += j-i-1;
                    break;
                }
            }
            if(sentencesAdded == summarySentenceCount) {
                break;
            }
        }
    }
    
    // Print the summary
    printf("\nSummary:\n%s\n", summary);
    
    return 0;
}