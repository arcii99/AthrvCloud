//FormAI DATASET v1.0 Category: Text Summarizer ; Style: calm
#include <stdio.h>
#include <string.h>

#define MAX_INPUT_SIZE 1000
#define MAX_OUTPUT_SIZE 100

char* summarize(char* input) {
    // Tokenize the input string
    char* tokens = strtok(input, " ");
    
    // Initialize the output string
    char* output = malloc(MAX_OUTPUT_SIZE * sizeof(char));
    output[0] = '\0';
    
    // Loop through the tokens and add them to the output string
    while (tokens != NULL) {
        if (strlen(output) + strlen(tokens) < MAX_OUTPUT_SIZE) {
            strcat(output, tokens);
            strcat(output, " ");
        } else {
            break;
        }
        tokens = strtok(NULL, " ");
    }
    
    return output;
}

int main() {
    // Initialize the input string
    char input[MAX_INPUT_SIZE];
    printf("Enter some text to summarize: ");
    fgets(input, MAX_INPUT_SIZE, stdin);
    
    // Remove trailing newline from input string
    input[strcspn(input, "\n")] = 0;
    
    // Summarize the input string
    char* summary = summarize(input);
    printf("Summary: %s\n", summary);
    
    return 0;
}