//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char* conspiracies[] = {"The government is hiding the cure for cancer!", 
                            "Chemtrails are making us all sick!", 
                            "The moon landing was faked!", 
                            "The Illuminati is controlling our minds!", 
                            "Aliens are already living among us!"};
    int num_conspiracies = 5;

    // Seed the random number generator with the current time
    srand(time(NULL));

    // Generate a random conspiracy theory
    int random_index = rand() % num_conspiracies;
    char* conspiracy = conspiracies[random_index];

    // Print the conspiracy theory
    printf("Have you heard about the latest conspiracy theory?\n");
    printf("%s\n", conspiracy);
    printf("Spread the word!");

    return 0;
}