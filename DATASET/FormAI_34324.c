//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char sentence[1000];
    int happyCount = 0, sadCount = 0;
    
    printf("Enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin); // Read input sentence
    
    char* token = strtok(sentence, " "); // Get first word
    while (token != NULL) {
        int happy = 0, sad = 0;
        
        for (int i = 0; i < strlen(token) - 2; i++) { // Check for happy emoticons
            if (token[i] == ':' && token[i+1] == '-' && token[i+2] == ')') {
                happy = 1;
            }
        }
        
        for (int i = 0; i < strlen(token) - 2; i++) { // Check for sad emoticons
            if (token[i] == ':' && token[i+1] == '-' && token[i+2] == '(') {
                sad = 1;
            }
        }
        
        if (happy) {
            happyCount++;
        }
        else if (sad) {
            sadCount++;
        }
        
        token = strtok(NULL, " "); // Get next word
    }
    
    if (happyCount > sadCount) {
        printf("Happy sentence.\n");
    }
    else if (sadCount > happyCount) {
        printf("Sad sentence.\n");
    }
    else {
        printf("Neutral sentence.\n");
    }
    
    return 0;
}