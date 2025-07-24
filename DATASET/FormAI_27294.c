//FormAI DATASET v1.0 Category: Text Summarizer ; Style: artistic
#include <stdio.h>
#include <string.h>

int main() {
    char input[500]; // Maximum size of input text
    char summary[100]; // Maximum size of summary
    int i, j, count;
    char delimiter[] = ".,!?;"; // List of delimiters
    
    printf("Welcome to the Artistic Text Summarizer\n\n");
    printf("Please enter the text you want to summarize: ");
    fgets(input, sizeof(input), stdin); // Get user input
    
    strtok(input, "\n"); // Remove newline character
    
    for(i = 0, count = 0; i < strlen(input); i++) {
        if(input[i] == '.' || input[i] == '!' || input[i] == '?') {
            count++; // Count number of sentences
        }
    }
    
    if(count <= 1) { // Only one sentence
        strcpy(summary, input);
    }
    else { // Multiple sentences
        char sentences[count][100]; // Maximum size of sentence
        char *token = strtok(input, delimiter); // Tokenize input
        
        while(token != NULL) {
            for(i = 0; token[i] != '\0'; i++) {
                token[i] = tolower(token[i]); // Lowercase
            }
            strcpy(sentences[j], token);
            j++;
            token = strtok(NULL, delimiter);
        }
        
        for(i = 0; i < count; i++) {
            char *current_sentence = sentences[i];
            int word_count = 0;
            token = strtok(current_sentence, " ");
            
            while(token != NULL) {
                word_count++;
                token = strtok(NULL, " ");
            }
            
            if(word_count > 10) { // Greater than 10 words
                strcat(summary, sentences[i]);
                strcat(summary, ". "); // Add period
            }
        }
    }
    
    printf("\nArtistic Summary:\n\n%s\n\n", summary); // Print summary
    
    return 0;
}