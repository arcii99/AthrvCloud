//FormAI DATASET v1.0 Category: Text Summarizer ; Style: real-life
#include <stdio.h>
#include <string.h>

// function prototypes
void getText(char* text, int size);
int countSentences(char* text);
void summarize(char* text);

int main() {
    // initialize variables
    char text[1000];
    
    // get input text
    printf("Enter the text:\n");
    getText(text, sizeof(text));
    
    // summarize text
    summarize(text);
    
    return 0;
}

void getText(char* text, int size) {
    fgets(text, size, stdin);
}

int countSentences(char* text) {
    int count = 0;
    int length = strlen(text);
    
    for (int i = 0; i < length; i++) {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?') {
            count++;
        }
    }
    
    return count;
}

void summarize(char* text) {
    int numSentences = countSentences(text);
    int sentenceNum = 0;
    
    printf("\nSummary:\n");
    
    // loop through each sentence
    for (int i = 0; i < strlen(text); i++) {
        // print the sentence
        printf("%c", text[i]);
        
        if (text[i] == '.' || text[i] == '!' || text[i] == '?') {
            sentenceNum++;
            
            // add spacing after sentence
            printf("\n\n");
            
            // print sentence number
            printf("Sentence %d of %d:\n", sentenceNum, numSentences);
        }
    }
}