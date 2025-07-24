//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function declarations
void intro();
void generate_conspiracy();

// Main function
int main() {
    intro();
    generate_conspiracy();
    return 0;
}

// Function to print introduction message
void intro() {
    printf("Welcome to the Random Conspiracy Theory Generator!\n\n");
    printf("This program will generate a random conspiracy theory for you to ponder.\n\n");
    printf("Press Enter to continue...");
    getchar();
    system("clear");
}

// Function to generate conspiracy theory
void generate_conspiracy() {
    srand(time(0)); // Seed random number generator
    int rand_num = rand() % 10; // Generate random number between 0 and 9

    switch (rand_num) {
        case 0:
            printf("Did you know that the moon landing was faked and filmed in a movie studio?");
            break;
        case 1:
            printf("Have you ever heard of the lizard people? Some people believe that world leaders are actually shape-shifting reptilian aliens in disguise.");
            break;
        case 2:
            printf("The government is controlling our thoughts with mind-controlling chemicals in the water supply.");
            break;
        case 3:
            printf("Some believe that the world is actually flat and that NASA is part of a global conspiracy to cover it up.");
            break;
        case 4:
            printf("The Illuminati is a secret society that controls the world's governments, media, and financial systems.");
            break;
        case 5:
            printf("Contrails from airplanes are actually chemicals being sprayed into the air to control the population.");
            break;
        case 6:
            printf("The government is hiding evidence of extraterrestrial life from the public.");
            break;
        case 7:
            printf("The assassination of JFK was actually a conspiracy by the government to silence him.");
            break;
        case 8:
            printf("Some believe that the world is actually controlled by a small group of wealthy and powerful individuals known as the New World Order.");
            break;
        case 9:
            printf("9/11 was an inside job orchestrated by the government to justify going to war in the Middle East.");
            break;
    }

    printf("\n\nThanks for using the Random Conspiracy Theory Generator!");
}