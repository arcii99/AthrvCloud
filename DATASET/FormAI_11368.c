//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: real-life
#include <stdio.h>
#include <string.h>

int main() {
    char catPhrases[9][50] = { // Initializing cat phrases array
        "Meow", "Purr", "Hiss", "Mrow", "Yowl", "Chirp", "Trill", "Growl", "Mew"
    };
    char englishPhrases[9][50] = { // Initializing English phrases array
        "Hello", "I am happy", "I am angry", "I am hungry", "I am bored", "I am playful", "I want attention", "I am scared", "I want food"
    };
    char userInput[50];
    int index = 0; // Initializing variable to hold phrase index

    printf("Welcome to the C Cat Language Translator!\n");
    while(strcmp(userInput, "exit") != 0) { // Keep looping until user enters "exit"
        printf("Enter a cat phrase to translate to English: ");
        scanf("%s", userInput);

        // Loop through cat phrases to find matching user input
        for(int i = 0; i < 9; i++) {
            if(strcmp(userInput, catPhrases[i]) == 0) {
                index = i; // Assign matching phrase index to variable
                break;
            }
        }

        // Check if user input has a matching phrase
        if(index >= 0 && index < 9) {
            printf("Translation: %s\n", englishPhrases[index]);
        } else { // Display error message if phrase is not found
            printf("Phrase not found. Try again or type 'exit' to quit.\n");
        }
    }
    printf("Exiting...\n");

    return 0;
}