//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: configurable
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// Define some arrays to hold the words for our conspiracy theory
char* nouns[] = {"government", "aliens", "Illuminati", "New World Order", "chemtrails", "vaccines"};
char* verbs[] = {"control", "manipulate", "brainwash", "dominate", "enslave", "exterminate"};
char* adjectives[] = {"secret", "powerful", "dangerous", "diabolical", "evil", "sinister"};
char* objects[] = {"mind", "world", "populace", "media", "technology", "weather"};

// Function to generate a random integer between min and max (inclusive)
int randomNum(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

int main() {
    // Seed the random number generator with the current time
    srand((unsigned) time(NULL));
    
    // Ask the user how many conspiracy theories they want to generate
    int numTheories;
    printf("How many conspiracy theories do you want to generate? ");
    scanf("%d", &numTheories);
    
    // Loop through the number of theories requested and generate each one
    for (int i = 0; i < numTheories; i++) {
        // Choose a random word from each array to form the conspiracy theory
        char* noun = nouns[randomNum(0, 5)];
        char* verb = verbs[randomNum(0, 5)];
        char* adjective = adjectives[randomNum(0, 5)];
        char* object = objects[randomNum(0, 5)];
        
        // Print the conspiracy theory
        printf("%d. The %s %s the %s with their %s %s.\n", i+1, noun, verb, object, adjective, object);
    }
    
    return 0;
}