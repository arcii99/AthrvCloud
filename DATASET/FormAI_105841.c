//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* Function to generate a random integer between min and max (inclusive) */
int random_int(int min, int max) {
    return min + rand() % (max - min + 1);
}

/* Main function */
int main() {
    
    srand(time(NULL)); // seed random number generator with current time
    
    // Arrays to hold conspiracy theories and related terms
    char* theories[] = {"The moon landing was faked", "Chemtrails are controlling our minds", "9/11 was an inside job", "The Illuminati control the world", "The Earth is flat", "Aliens are among us", "The government is hiding the cure for cancer"};
    char* individuals[] = {"the government", "large corporations", "a secret cabal of elites", "the military-industrial complex", "the New World Order"};
    char* methods[] = {"mind control", "mass surveillance", "weaponized weather", "genetic engineering"};
    char* evidence[] = {"leaked government documents", "whistleblower testimonies", "anomalies in official reports", "unexplained phenomena"};
    
    char user_input[100]; // variable to hold user input
    
    // Print welcome message and instructions
    printf("Welcome to the Random Conspiracy Theory Generator!\n");
    printf("Press enter to generate a conspiracy theory or type 'quit' to exit.\n\n");
    
    // Continue generating theories until user types 'quit'
    while (1) {
        fgets(user_input, 100, stdin); // get user input
        
        if (strcmp(user_input, "quit\n") == 0) { // check if user wants to quit
            printf("Thank you for using the Random Conspiracy Theory Generator!\n");
            break; // exit loop
        }
        
        int theory_index = random_int(0, 6); // generate random index for theory array
        int individual_index = random_int(0, 4); // generate random index for individual array
        int method_index = random_int(0, 3); // generate random index for method array
        int evidence_index = random_int(0, 3); // generate random index for evidence array
        
        // Print generated conspiracy theory
        printf("\n%s is using %s to implement %s and is covering it up with %s.\n", individuals[individual_index], methods[method_index], theories[theory_index], evidence[evidence_index]);
        printf("Press enter to generate another conspiracy theory or type 'quit' to exit.\n");
    }
    
    return 0; // exit program
}