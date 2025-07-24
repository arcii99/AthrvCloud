//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // Seed the random number generator
    
    char *nouns[] = {"government", "aliens", "Illuminati", "big pharma", "the media", "the education system"};
    char *verbs[] = {"controls", "manipulates", "brainwashes", "poisons", "spies on", "silences"};
    char *adjectives[] = {"secret", "global", "corrupt", "powerful", "sinister", "unstoppable"};
    
    printf("Welcome to the Random Conspiracy Theory Generator!\n\n");
    while(1) {
        printf("Press enter to generate a new conspiracy theory, or type 'quit' to exit:\n");
        char input[10];
        fgets(input, 10, stdin); // get user input
        if(input[0] == 'q') { break; } // quit if user types 'quit'
        
        // Choose random values for the nouns, verbs, and adjectives
        int nounIndex = rand() % 6;
        int verbIndex = rand() % 6;
        int adjIndex = rand() % 6;
        
        // Print out the conspiracy theory sentence
        printf("The %s %s %s everything!\n\n", adjectives[adjIndex], nouns[nounIndex], verbs[verbIndex]);
    }
    return 0;
}