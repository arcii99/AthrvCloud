//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: mind-bending
#include <stdio.h>

int main() {
    // Declare arrays of conspiracy theories
    char *conspiracies[] = {"The moon landing was faked", "Fluoride in the water is mind control", "Chemtrails are manipulating the weather", "The Illuminati control the world", "Aliens are among us"};
    char *who[] = {"The government", "The CIA", "The elites", "The corporations", "The lizard people"};

    // Generate random numbers
    int conspiracy_index = rand() % 5;
    int who_index = rand() % 5;

    // Print out the conspiracy theory
    printf("Did you know that %s is being controlled by %s?\n", conspiracies[conspiracy_index], who[who_index]);
    
    // Generate more random numbers for added effect
    int evidence_num = rand() % 10 + 1;
    int witness_num = rand() % 5 + 1;
    int coverup_num = rand() % 7 + 1;

    // Add some details to the conspiracy theory
    printf("There is %d pieces of evidence that %s is true.\n", evidence_num, conspiracies[conspiracy_index]);
    printf("%d people have witnessed the truth, but they are too afraid to speak out.\n", witness_num);
    printf("The %s is covering up the truth with %d levels of secrecy.\n", who[who_index], coverup_num);

    // Let the user know that they're in on the secret
    printf("But you don't have to worry. You're one of the few who know the truth.\n");

    return 0;
}