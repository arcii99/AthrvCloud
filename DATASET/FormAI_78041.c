//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the maximum number of variables
#define MAX_VAR 10

// Define the maximum length of conspiracy theories
#define MAX_LEN 100

int main() {
    char* variables[MAX_VAR] = {"the government", "aliens", "the Illuminati", "the Freemasons", "Big Pharma", "the media", 
                                "the deep state", "the lizard people", "the New World Order", "the elites"};
    char* actions[MAX_VAR] = {"is controlling", "is manipulating", "is brainwashing", "is surveilling", "is experimenting on", 
                              "is infiltrating", "is secretly funding", "is silencing", "is covering up", "is suppressing"};
    char* targets[MAX_VAR] = {"the population", "the internet", "the weather", "the food supply", "the elections", 
                              "the education system", "the healthcare system", "the entertainment industry", "the environment", "the economy"};
    
    srand(time(0)); // Use current time as seed for random number generator
    
    int num_conspiracies = 5 + rand() % 6; // Generate a random number of conspiracy theories between 5 and 10
    
    for (int i = 0; i < num_conspiracies; i++) {
        char conspiracy[MAX_LEN] = "";
        
        // Generate a random variable, action, and target for each conspiracy theory
        int var_idx = rand() % MAX_VAR;
        int act_idx = rand() % MAX_VAR;
        int tgt_idx = rand() % MAX_VAR;
        
        // Combine the three randomly selected elements into a conspiracy theory sentence
        sprintf(conspiracy, "%s %s %s", variables[var_idx], actions[act_idx], targets[tgt_idx]);
        
        printf("%d) %s\n", i+1, conspiracy); // Print the conspiracy theory with its number
    }
    
    return 0;
}