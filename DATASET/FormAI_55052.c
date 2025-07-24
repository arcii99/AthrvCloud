//FormAI DATASET v1.0 Category: Word Count Tool ; Style: future-proof
#include <stdio.h>
#include <ctype.h>

int main() {
    
    char sentence[500];
    int wordCount = 0;
    int i;
    
    printf("Enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin);
    
    // Counting the words
    for (i = 0; sentence[i] != '\0'; i++) {
        if (isspace(sentence[i]) || sentence[i] == '\n') {
            wordCount++;
        }
    }
    
    // Displaying the result
    printf("The number of words in the sentence is: %d\n", wordCount);
    
    return 0;
}