//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const char *adjectives[] = {"massive", "secret", "corrupt", "hidden", "sinister", "crazy", "mind-blowing", "shocking", "nefarious", "diabolical", "terrifying", "unnerving", "psycho", "demented", "insane", "weird"};
const char *nouns[] = {"government", "Illuminati", "aliens", "New World Order", "flat earth society", "zombies", "dragons", "simulations", "time travelers", "vampires", "werewolves"};
const char *actions[] = {"control", "manipulate", "brainwash", "destroy", "enslave", "usurp", "scheme", "conspire", "invade", "suppress", "imprison"};

int main(void) {
    srand(time(NULL)); // Seed the random number generator with current time
    
    printf("Welcome to the Random Conspiracy Theory Generator!\n");
    printf("Press enter to generate a new conspiracy theory or type 'exit' to quit.\n\n");
    
    char input[6]; // String to hold user input
    
    while (1) { // Infinite loop until user inputs "exit"
        getchar(); // Wait for user to press enter
        printf("Your random conspiracy theory is: ");
        
        // Randomly select a word from each category to construct the conspiracy theory
        int adj_index = rand() % 15;
        int noun_index = rand() % 11;
        int action_index = rand() % 11;
        
        printf("%s %s %s.\n\n", adjectives[adj_index], nouns[noun_index], actions[action_index]);
        
        printf("Press enter to generate a new conspiracy theory or type 'exit' to quit.\n\n");
        scanf("%s", input); // Get user input
        
        if (input[0] == 'e' && input[1] == 'x' && input[2] == 'i' && input[3] == 't') { // If user input is "exit"
            printf("Thank you for using the Random Conspiracy Theory Generator!\n");
            return 0; // Exit program
        }
    }
}