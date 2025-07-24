//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random conspiracy theories
void generateTheory() {

    // Seed the random number generator
    srand(time(NULL));

    // Array of conspiracy theories
    char* theories[] = {
        "The moon landing was fake!",
        "The government is hiding the cure for cancer!",
        "Aliens are living among us!",
        "The Illuminati control the world!",
        "The Earth is flat!",
        "9/11 was an inside job!",
        "The government is spying on us through our phones!",
        "The Bermuda Triangle is a portal to another dimension!",
        "The Loch Ness Monster is real!",
        "The government is covering up the existence of Bigfoot!",
        "The Titanic wasn't sunk by an iceberg!",
        "The pyramids were built by aliens!",
        "The cure for AIDS already exists!",
        "The government is hiding evidence of time travel!",
        "The FBI killed JFK!",
        "Chemtrails are a form of mind control!",
        "The moon is a hologram!",
        "The government is hiding evidence of the existence of Sasquatch!",
        "The government is using HAARP to control the weather!",
        "The CIA is behind the rise of ISIS!"
    };

    // Get a random number between 0 and 19
    int randomIndex = rand() % 20;

    // Print a random conspiracy theory
    printf("Did you know? %s\n", theories[randomIndex]);

}

// Main function
int main() {

    // Call the generateTheory function 10 times
    for (int i = 0; i < 10; i++) {
        generateTheory();
    }

    return 0;

}