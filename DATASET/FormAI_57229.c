//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: sophisticated
#include <stdio.h>

int main() {
    char input[1000]; // The input string from the user
    printf("Enter a sentence in C Cat Language: ");
    scanf("%[^\n]", input);
    
    char output[1000] = ""; // The translated output string
    int i = 0; // The index of the input string being evaluated
    
    // Start translating the input string
    while (input[i] != '\0') {
        // Identify the current word in the input string by finding the next space
        int start = i;
        while (input[i] != ' ' && input[i] != '\0') {
            i++;
        }
        int end = i - 1;
        
        // Translate the current word and add it to the output string
        char currentWord[1000] = "";
        for (int j = start; j <= end; j++) {
            if (input[j] == 'C') {
                strcat(currentWord, "Meow");
            } else if (input[j] == 'c') {
                strcat(currentWord, "meow");
            } else if (input[j] == 't') {
                strcat(currentWord, "purr");
            } else if (input[j] == 'T') {
                strcat(currentWord, "Purr");
            } else {
                strcat(currentWord, " ");
            }
        }
        strcat(output, currentWord);
        strcat(output, " ");
        
        // Skip any extra whitespace between words
        while (input[i] == ' ') {
            i++;
        }
    }
    
    // Print the translated output
    printf("The translation of your C Cat Language sentence is: %s\n", output);
    
    return 0;
}