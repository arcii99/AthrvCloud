//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char *conspiracies[] = {
        "The moon landing was faked by the government to win the space race.",
        "9/11 was an inside job orchestrated by the government.",
        "The Illuminati controls world governments and influences major events.",
        "Bigfoot exists and is being kept hidden by the government.",
        "The government is hiding the cure for cancer to make money off of treatments.",
        "Aliens exist and the government has been communicating with them in secret.",
        "The government is using chemtrails to control the population and change the climate.",
        "The Earth is flat and scientific evidence proving otherwise is a government conspiracy.",
        "The Freemasons are secretly controlling world events and pushing their own agenda.",
        "The government has created a secret database of all citizens for surveillance purposes.",
        "The Bermuda Triangle is a portal to another dimension.",
        "The assassination of JFK was planned by the government and carried out by multiple shooters.",
        "The Denver Airport houses a secret underground bunker for the elite to survive a global catastrophe.",
        "The government is responsible for creating and spreading viruses like HIV and Ebola.",
        "The Loch Ness Monster is actually a government experiment gone wrong.",
        "The pyramids were built by aliens and not by humans.",
    };

    srand(time(NULL)); // Seed the random number generator with the current time
    int num_conspiracies = sizeof(conspiracies) / sizeof(char *); // Get the number of conspiracy theories in the array

    printf("Welcome to the Random Conspiracy Theory Generator!\n");
    printf("Press ENTER to generate a new theory or type 'exit' to quit.\n\n");

    while (1) {
        char input[10];
        fgets(input, sizeof(input), stdin); // Get user input

        if (strncmp(input, "exit", 4) == 0) { // If user types 'exit', exit the program
            break;
        } else {
            int random_num = rand() % num_conspiracies; // Generate a random number between 0 and number of conspiracy theories
            printf("Conspiracy Theory: %s\n\n", conspiracies[random_num]); // Print the randomly generated conspiracy theory
        }
    }

    printf("Thank you for using the Random Conspiracy Theory Generator!\n");

    return 0;
}