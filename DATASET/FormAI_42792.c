//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define function to generate random conspiracy theory
void generate_conspiracy_theory() {
    srand(time(NULL)); // Seed the random number generator with the current time
    int num = rand() % 5; // Generate a random number between 0 and 4

    // Use switch case to determine which conspiracy theory to output
    switch(num) {
        case 0: printf("The moon landing was faked!\n"); break;
        case 1: printf("The government is controlling our thoughts with chemtrails!\n"); break;
        case 2: printf("Aliens are living among us and controlling our world leaders!\n"); break;
        case 3: printf("The Illuminati is secretly ruling the world from behind the scenes!\n"); break;
        case 4: printf("The Earth is actually flat and the government is covering it up!\n"); break;
        default: printf("Something went wrong..."); break;
    }
}

int main() {
    // Print heading for program
    printf("Welcome to the Random Conspiracy Theory Generator! Are you ready to learn the truth?\n");

    // Run loop to allow user to generate multiple conspiracy theories
    while(1) {
        // Ask user if they want to generate a new conspiracy theory
        printf("\nDo you want to generate a new conspiracy theory? (y/n)\n");
        char answer = getchar();

        // Handle the case where the user wants to generate a new conspiracy theory
        if (answer == 'y' || answer == 'Y') {
            generate_conspiracy_theory();
        }
        // Handle the case where the user does not want to generate a new conspiracy theory
        else if (answer == 'n' || answer == 'N') {
            printf("Thanks for using the Random Conspiracy Theory Generator! Remember to always question everything...\n");
            break; // Exit loop and end program
        }
        // Handle the case where the user inputs an invalid answer
        else {
            printf("I'm sorry, I didn't understand your input. Please enter 'y' for yes or 'n' for no.\n");
        }

        // Clear input buffer to prevent errors
        while ((getchar()) != '\n');
    }

    return 0; // End program
}