//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the maximum number of conspiracy theories in the array
#define MAX_CONSPIRACY_THEORIES 10

// Function prototypes
void printIntro();
void generateRandomConspiracyTheories(char conspiracyTheories[MAX_CONSPIRACY_THEORIES][100]);
void displayConspiracyTheory(char conspiracyTheory[100]);
void printOutro();

int main()
{
    // Seed the random number generator
    srand(time(NULL));

    // Initialize the array of conspiracy theories
    char conspiracyTheories[MAX_CONSPIRACY_THEORIES][100] = {0};

    // Print the introduction
    printIntro();

    // Generate the conspiracy theories
    generateRandomConspiracyTheories(conspiracyTheories);

    // Display each conspiracy theory
    for (int i = 0; i < MAX_CONSPIRACY_THEORIES; i++)
    {
        // Display the conspiracy theory
        displayConspiracyTheory(conspiracyTheories[i]);
    }

    // Print the outro
    printOutro();

    return 0;
}

// Prints the introduction to the program
void printIntro()
{
    printf("==============================\n");
    printf(" C RANDOM CONSPIRACY THEORY GENERATOR\n");
    printf("==============================\n\n");
    printf("Welcome to the Random Conspiracy Theory Generator!\n");
    printf("This program will generate %d random conspiracy theories for you to enjoy.\n\n", MAX_CONSPIRACY_THEORIES);
}

// Generates random conspiracy theories and stores them in the given array
void generateRandomConspiracyTheories(char conspiracyTheories[MAX_CONSPIRACY_THEORIES][100])
{
    // Define an array of possible conspiracy theories
    char possibleTheories[][100] = {
        "The moon landing was faked.",
        "The government is hiding evidence of Bigfoot's existence.",
        "The world is run by reptilian aliens in disguise.",
        "Chemtrails are a mind control experiment.",
        "The Illuminati controls the world's governments.",
        "The Earth is actually flat.",
        "The government is hiding the cure for cancer.",
        "HAARP is a weapon that can control the weather.",
        "9/11 was an inside job.",
        "The government is covering up the existence of time travel.",
        "The coronavirus is a bioweapon created by the government.",
        "There is a secret group known as the Bilderberg Group that controls the world's economy.",
        "The government is hiding the true power of Tesla's inventions.",
        "The assassination of JFK was a government plot.",
        "The moon is actually a giant hologram.",
    };

    // Generate MAX_CONSPIRACY_THEORIES random conspiracy theories
    for (int i = 0; i < MAX_CONSPIRACY_THEORIES; i++)
    {
        // Generate a random index
        int index = rand() % (sizeof(possibleTheories) / sizeof(possibleTheories[0]));

        // Copy the conspiracy theory into the array
        strcpy(conspiracyTheories[i], possibleTheories[index]);
    }
}

// Displays a conspiracy theory
void displayConspiracyTheory(char conspiracyTheory[100])
{
    printf("- %s\n", conspiracyTheory);
}

// Prints the outro to the program
void printOutro()
{
    printf("\nThank you for using the Random Conspiracy Theory Generator! Don't forget to keep an open mind...\n");
}