//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: recursive
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

// Function to generate random conspiracy theories recursively
void generate_conspiracy_theories(int iteration, int max_iteration, char* conspiracy_theory) {
    // Array of possible conspiracy theories
    char theories[10][100] = {"The moon landing was faked.", "The government is hiding evidence of extraterrestrial life.",
                              "The Illuminati control everything.", "Big Pharma is suppressing a cure for cancer.",
                              "The Earth is actually flat.", "9/11 was an inside job.",
                              "Chemtrails are poisoning us.", "The Denver International Airport is a secret bunker.",
                              "Vaccines are being used to control the population.", "Climate change is a hoax."};

    int random_index = rand() % 10; // Generate a random index to select a conspiracy theory

    if(iteration >= max_iteration) { // Base case: maximum iteration reached
        strcpy(conspiracy_theory, theories[random_index]); // Copy the selected conspiracy theory to the result string
        return;
    }

    char next_theory[100]; // Temporary string for the next iteration
    generate_conspiracy_theories(iteration+1, max_iteration, next_theory); // Recursively generate the next theory

    // Build the final conspiracy theory by combining the current theory with the next theory with a connecting phrase
    sprintf(conspiracy_theory, "%s %s because ", theories[random_index], next_theory);
}

int main() {
    srand(time(NULL)); // Seed the random number generator

    int iteration_limit = 4; // Maximum depth of recursion
    char conspiracy[100]; // Result string for the final conspiracy theory

    generate_conspiracy_theories(0, iteration_limit, conspiracy); // Generate the conspiracy theory

    printf("Random conspiracy theory:\n%s\n", conspiracy);

    return 0;
}