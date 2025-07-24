//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: shape shifting
#include <stdio.h> 
#include <stdlib.h>
#include <time.h>

int main() {
    char *nouns[] = {"aliens", "government", "Illuminati", "Lizard People", "Big Pharma", "New World Order"};
    char *adjectives[] = {"secretly", "covertly", "surreptitiously", "stealthily", "furtively", "clandestinely"};
    char *verbs[] = {"manipulating", "brainwashing", "controlling", "influencing", "programming", "dominating"};
    char *targets[] = {"general population", "the media", "world leaders", "the internet", "subliminal advertising", "Harvard University"};

    // Seed the random number generator
    srand(time(NULL));
    
    // Generate 10 conspiracy theories
    for(int i = 0; i < 10; i++) {
        // Select a random noun, adjective, verb, and target
        int nounIndex = rand() % 6;
        int adjIndex = rand() % 6;
        int verbIndex = rand() % 6;
        int targetIndex = rand() % 6;
        
        // Print the conspiracy theory
        printf("The %s are %s %s %s to %s.\n", 
               nouns[nounIndex], adjectives[adjIndex], verbs[verbIndex], targets[targetIndex]);
    }
    
    return 0;
}