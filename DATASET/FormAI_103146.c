//FormAI DATASET v1.0 Category: Word Count Tool ; Style: automated
#include <stdio.h>
#include <ctype.h>

int countWords(char sentence[]);

int main() {
    char sentence[100];
    
    printf("Enter a sentence: ");
    gets(sentence);
    
    printf("Number of words: %d\n", countWords(sentence));
    
    return 0;
}

int countWords(char sentence[]) {
    int wordCount = 0;
    int i;
    
    for (i = 0; sentence[i] != '\0'; i++) {
        if (isspace(sentence[i]) || sentence[i] == '\n') {
            wordCount++;
        }
    }
    
    return wordCount;
}