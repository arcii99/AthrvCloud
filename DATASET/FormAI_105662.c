//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random integers
int getRandomInt(int max) {
    srand(time(NULL)); // Initialize the random number generator
    return (rand() % max) + 1; // Generate a random integer between 1 and the maximum value
}

// Function to generate a random conspiracy theory
char* generateConspiracy() {
    int index = getRandomInt(10); // Generate a random integer between 1 and 10
    char* conspiracy;
    switch(index) {
        case 1:
            conspiracy = "The moon landing was faked by the government to win the space race.";
            break;
        case 2:
            conspiracy = "The government is hiding the existence of extraterrestrial life from the public.";
            break;
        case 3:
            conspiracy = "The Illuminati controls the world's governments and economies.";
            break;
        case 4:
            conspiracy = "Chemtrails are being sprayed by the government to control people's minds.";
            break;
        case 5:
            conspiracy = "COVID-19 was deliberately created in a lab as a biological weapon.";
            break;
        case 6:
            conspiracy = "9/11 was an inside job orchestrated by the government.";
            break;
        case 7:
            conspiracy = "The earth is flat and the government is hiding this fact from the public.";
            break;
        case 8:
            conspiracy = "The Loch Ness monster is a real creature that the government is hiding from the world.";
            break;
        case 9:
            conspiracy = "The music industry is controlled by a secret society that uses subliminal messages to brainwash people.";
            break;
        case 10:
            conspiracy = "The existence of time travel has been discovered and is being kept secret by the government.";
            break;
        default:
            conspiracy = "Error: no conspiracy theory found.";
    }
    return conspiracy;
}

int main() {
    printf("Welcome to the Random Conspiracy Theory Generator!\n");
    printf("Press Enter to generate a new conspiracy theory, or type 'quit' to exit.\n");
    char input[100];
    while(1) {
        fgets(input, 100, stdin); // Get user input
        if(strcmp(input, "quit\n") == 0) { // If user enters 'quit', exit the program
            printf("Exiting program...\n");
            break;
        }
        printf("New conspiracy theory generated: %s\n", generateConspiracy()); // Generate and print a new conspiracy theory
    }
    return 0;
}