//FormAI DATASET v1.0 Category: Spam Detection System ; Style: secure
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SPAM_THRESHOLD 0.5

int main() {
    char input[1000];
    printf("Enter your text:\n");
    fgets(input, 1000, stdin);
    
    // Remove trailing newline character
    input[strcspn(input, "\n")] = 0;
    
    int total_words = 0;
    int spam_words = 0;
    
    char *word = strtok(input, " ");
    while (word != NULL) {
        total_words++;
        
        // Convert word to lowercase for comparison
        char lowercase_word[strlen(word)];
        for (int i = 0; i < strlen(word); i++) {
            lowercase_word[i] = tolower(word[i]);
        }
        
        if (strcmp(lowercase_word, "buy") == 0 || 
            strcmp(lowercase_word, "discount") == 0 || 
            strcmp(lowercase_word, "free") == 0) {
            spam_words++;
        }
        
        // Get next word
        word = strtok(NULL, " ");
    }
    
    double spam_ratio = (double)spam_words / (double)total_words;
    if (spam_ratio > SPAM_THRESHOLD) {
        printf("This text is likely spam\n");
    } else {
        printf("This text is probably not spam\n");
    }
    
    return 0;
}