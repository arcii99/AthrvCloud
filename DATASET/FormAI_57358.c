//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function declarations
void printIntro();
void generateConspiracy();

// Main function
int main() 
{
    printIntro(); // Print program introduction
    generateConspiracy(); // Generate a random conspiracy theory

    return 0;
}

// Function to print program introduction
void printIntro() 
{
    printf("Welcome to the Random Conspiracy Theory Generator!\n\n");
    printf("This program will generate a random conspiracy theory for your enjoyment.\n");
    printf("Please note that the theories produced by this program are entirely fictional and not based in reality.\n\n");
}

// Function to generate a random conspiracy theory
void generateConspiracy() 
{
    srand(time(NULL)); // Seed the random number generator with the current time

    // Conspiracy theory components
    char *groups[] = {"the government", "the Illuminati", "aliens", "Big Pharma", "the Deep State"};
    char *actions[] = {"is hiding", "is controlling", "is manipulating", "is experimenting on", "is monitoring"};
    char *targets[] = {"the American people", "the world's population", "certain ethnic groups", "the economy", "the environment"};

    // Generate random components, one from each array
    int groupIndex = rand() % 5;
    int actionIndex = rand() % 5;
    int targetIndex = rand() % 5;

    // Build conspiracy theory string
    char conspiracy[100];
    sprintf(conspiracy, "Did you know that %s %s %s?", groups[groupIndex], actions[actionIndex], targets[targetIndex]);

    // Print conspiracy theory
    printf("%s\n", conspiracy);
}