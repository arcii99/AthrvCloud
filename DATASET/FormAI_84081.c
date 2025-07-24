//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random conspiracy theories
void generateConspiracyTheory() {
    srand(time(NULL)); // Seed the random number generator
    char* theories[10] = {"The moon landing was faked by the government",
                          "The Illuminati control the world's governments",
                          "The earth is flat and NASA is lying to us",
                          "9/11 was a planned inside job by the US government",
                          "Vaccines are a way for the government to control our minds",
                          "The Rothschild family secretly rules the world",
                          "Chemtrails are being used to poison the population",
                          "The Denver airport is a secret government base",
                          "Bigfoot is a government experiment gone wrong",
                          "The Bermuda Triangle is a portal to another dimension"};
    int index = rand() % 10; // Generate a random index to select a theory
    printf("Did you know that %s?\n", theories[index]); // Print the selected theory
}

int main() {
    printf("Welcome to the Random Conspiracy Theory Generator!\n\n");
    while (1) {
        printf("Press ENTER to generate a new conspiracy theory or 'q' to quit...\n");
        int c = getchar();
        if (c == 'q') { // Exit the program if 'q' is pressed
            printf("\nThanks for using the Random Conspiracy Theory Generator!\n");
            break;
        }
        generateConspiracyTheory(); // Generate a new conspiracy theory
    }
    return 0;
}