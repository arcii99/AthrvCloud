//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // seed the random number generator
    
    printf("Welcome to the Conspiracy Theory Generator!\n");
    printf("Press ENTER to generate a new theory, or CTRL-C to exit.\n\n");

    // arrays of words to use in theories
    char* noun[] = {"government", "aliens", "Illuminati", "Big Pharma", "lizard people", "time travelers", "freemasons"};
    char* verb[] = {"control", "manipulate", "secretly rule", "brainwash", "experiment on", "enslave", "corrupt"};
    char* loc[] = {"Area 51", "the Bermuda Triangle", "the moon", "underground bases", "the Vatican", "the White House", "Mt. Everest"};

    while (1) {
        printf("Theory: The %s are trying to %s the world from %s!\n", noun[rand() % 7], verb[rand() % 7], loc[rand() % 7]);
        getchar(); // wait for user to press enter
    }

    return 0;
}