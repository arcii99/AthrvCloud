//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: creative
// C Cat Translator

#include <stdio.h>
#include <string.h>

// Function to translate Cat language to English
void translate(char *phrase) {
    if (strcmp(phrase, "meow") == 0) {
        printf("I want food.\n");
    } else if (strcmp(phrase, "purr") == 0) {
        printf("I am happy.\n");
    } else if (strcmp(phrase, "hiss") == 0) {
        printf("I am angry.\n");
    } else if (strcmp(phrase, "sleep") == 0) {
        printf("I want to sleep.\n");
    } else {
        printf("I do not understand.\n");
    }
}

// Main function
int main() {
    char phrase[100];
    
    printf("Welcome to the C Cat Translator!\n");
    
    // Loop to keep translating until user inputs "exit"
    while (1) {
        printf("Please input a phrase in Cat language (or type 'exit' to close): ");
        scanf("%s", phrase);
        
        if (strcmp(phrase, "exit") == 0) {
            printf("Thank you for using the C Cat Translator!\n");
            break;
        }
        
        printf("Translation: ");
        translate(phrase);
    }
    
    return 0;
}