//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int randInt(int min, int max) {
    return rand() % (max - min + 1) + min;
}

int main() {
    srand(time(NULL));
    char *nouns[] = {"government", "Illuminati", "aliens", "Big Pharma", "CIA", "Masons"};
    char *verbs[] = {"control", "manipulate", "brainwash", "spy on", "experiment on", "form alliances with"};
    char *adjectives[] = {"secret", "powerful", "corrupt", "hidden", "shadowy", "mysterious"};
    char *theories[] = {
        "The %s is using mind control to manipulate the masses and maintain power.",
        "A cabal of %s-backed elites is secretly pulling the strings of world governments.",
        "The %s is hiding the truth about the existence of extraterrestrial life.",
        "Big Pharma is conspiring with the %s to suppress natural cures and maintain profits.",
        "The %s is behind a global surveillance network that monitors every aspect of our lives.",
        "Secret %s societies like the Masons are controlling the world's financial systems."
    };
    
    int numTheories = sizeof(theories) / sizeof(theories[0]);
    int numNouns = sizeof(nouns) / sizeof(nouns[0]);
    int numVerbs = sizeof(verbs) / sizeof(verbs[0]);
    int numAdjectives = sizeof(adjectives) / sizeof(adjectives[0]);
    
    printf("Welcome to the Random Conspiracy Theory Generator!\n");
    
    while (1) {
        printf("Press Enter to generate a conspiracy theory or Q to quit: ");
        char c = getchar();
        if (c == 'q' || c == 'Q') break;
        
        printf("Here's your theory: ");
        int theoryIndex = randInt(0, numTheories-1);
        int nounIndex = randInt(0, numNouns-1);
        int verbIndex = randInt(0, numVerbs-1);
        int adjIndex = randInt(0, numAdjectives-1);
        printf(theories[theoryIndex], adjectives[adjIndex], nouns[nounIndex], verbs[verbIndex]);
        printf("\n\n");
        
        // flush input buffer
        while (getchar() != '\n');
    }
    
    printf("Thanks for using the Random Conspiracy Theory Generator!\n");
    return 0;
}