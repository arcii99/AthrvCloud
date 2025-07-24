//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: rigorous
#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 1000  // Maximum length of input string

int main() {
    char input[MAX_LENGTH];  // String to hold user input
    char translated[MAX_LENGTH];  // String to hold translated output
    int i, j;
    int length;
    
    // Prompt user for input
    printf("Enter a sentence in C Cat Language: ");
    fgets(input, MAX_LENGTH, stdin);
    
    // Translate the sentence
    length = strlen(input);
    j = 0;
    for (i = 0; i < length; i++) {
        switch(input[i]) {
            case 'm':
                translated[j++] = 'c';
                break;
            case 'e':
                translated[j++] = 'a';
                break;
            case 'o':
                translated[j++] = 't';
                break;
            case 'w':
                translated[j++] = 'h';
                break;
            case 'p':
                translated[j++] = 'r';
                break;
            case 'c':
                translated[j++] = 'm';
                break;
            case 'a':
                translated[j++] = 'e';
                break;
            case 't':
                translated[j++] = 'o';
                break;
            case 'h':
                translated[j++] = 'w';
                break;
            case 'r':
                translated[j++] = 'p';
                break;
            default:
                // If character not in C Cat Language, leave it as-is
                translated[j++] = input[i];
                break;
        }
    }
    translated[j] = '\0';  // Add terminating null character
    
    // Print the translated sentence
    printf("Translated sentence: %s\n", translated);
    
    return 0;
}