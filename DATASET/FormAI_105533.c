//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: irregular
#include <stdio.h>
#include <string.h>

int main() {
    // Initializing dictionary
    char dictionary[10][20] = {
        "Meow", "Hello",
        "Purr", "Goodbye",
        "Hiss", "Yes",
        "Yowl", "No",
        "Scratch", "Please"
    };
    
    char phrase[100];
    printf("Enter a phrase in C Cat Language: ");
    
    // Scanning user input
    scanf("%[^\n]", phrase);
    
    char *token = strtok(phrase, " ");
    
    printf("Translation: ");
    
    while (token != NULL) {
        int found = 0;
        
        // Searching for matching words in dictionary
        for (int i = 0; i < 10; i++) {
            if (strcmp(token, dictionary[i]) == 0) {
                printf("%s ", dictionary[i+1]);
                found = 1;
                break; // Stop searching once a match is found
            }
            i++; // Skipping alternate indices (for pairing of words)
        }
        
        // If no match found, print original word
        if (found == 0) {
            printf("%s ", token);
        }
        
        token = strtok(NULL, " "); // Moving to next word
    }
    
    return 0;
}