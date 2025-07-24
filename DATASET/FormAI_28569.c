//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Function Declarations
void printIntroduction();
void printFooter();
void generateRandomConspiracy();

int main() {
    printIntroduction();
    generateRandomConspiracy();
    printFooter();
    return 0;
}

// Print Introduction
void printIntroduction() {
    printf("\n\t*** Welcome to the Random Conspiracy Theory Generator ***\n\n");
    printf("Here you will witness the most bizarre theories that might make you question reality. Brace yourself.\n\n");
    printf("Generating conspiracy theories...\n\n");
    printf("--------------------------------------------------------------\n");
}

// Print Footer
void printFooter() {
    printf("\nThank you for being part of this experience.\n");
    printf("Keep questioning everything and never let your mind be controlled.\n");
    printf("--------------------------------------------------------------\n");
}

// Generate Random Conspiracy Theory
void generateRandomConspiracy() {

    // Seed random number generator with time
    srand(time(NULL));
    
    // Array of conspiracy theories
    char *conspiracyTheories[10] = {"The moon landing was faked by the government",
                                    "The earth is actually flat and round earth theory is a hoax",
                                    "The government is hiding the existence of aliens from us",
                                    "9/11 was an inside job orchestrated by the government",
                                    "Lizard people secretly rule the world",
                                    "The Illuminati controls everything in the world",
                                    "Chemtrails are a way for the government to control the population",
                                    "The Holocaust was a hoax",
                                    "COVID-19 was created in a laboratory and released intentionally",
                                    "The world is run by a secret society known as the New World Order"};

    // Array of organizations/governments involved in conspiracies
    char *conspiracyOrganizations[9] = {"the government", "the Illuminati", "the New World Order",
                                        "the CIA", "the FBI", "the NSA", "NASA", "the Rothschilds", "the Bilderberg Group"};
    
    // Array of actors involved in conspiracies
    char *conspiracyActors[7] = {"Elon Musk", "Kim Jong-un", "Vladimir Putin", "Donald Trump", "Barack Obama", 
                                    "Bill Gates", "Mark Zuckerberg"};

    // Generate a random conspiracy theory, organization and actor
    int randConspiracy = rand() % 10;
    int randOrganization = rand() % 9;
    int randActor = rand() % 7;

    // Create a sentence combining the random elements into a conspiracy theory
    char sentence[200];
    strcpy(sentence, conspiracyTheories[randConspiracy]);
    strcat(sentence, " by ");
    strcat(sentence, conspiracyOrganizations[randOrganization]);
    strcat(sentence, " with the help of ");
    strcat(sentence, conspiracyActors[randActor]);
    strcat(sentence, ".");

    // Print out the generated conspiracy theory
    printf("%s\n", sentence);
}