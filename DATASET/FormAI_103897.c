//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random number in a range
int getRandomNumberInRange(int min, int max)
{
    return (rand() % (max - min + 1)) + min;
}

// Function to generate a random conspiracy theory
void generateConspiracyTheory()
{
    // Array of conspiracy theories
    char* theories[10] = {"The moon landing was faked by NASA!",
                          "The Illuminati is controlling the world!",
                          "9/11 was an inside job by the US government!",
                          "The government is hiding evidence of alien life!",
                          "Elvis Presley faked his own death!",
                          "The Rothschild family is secretly running the world!",
                          "The earth is flat and NASA is lying to us!",
                          "The FDA is suppressing natural cures for diseases!",
                          "Chemtrails are being used for mind control!",
                          "The CIA is behind most global conflicts!"};

    // Array of possible subjects to blame the conspiracy on
    char* subjects[10] = {"The government", "The media", "The illuminati",
                        "Big Pharma", "The military-industrial complex",
                        "The FBI", "The CIA", "The Bilderberg Group",
                        "The New World Order", "The reptilian elite"};

    // Generate random numbers to pick a theory and subject
    int theoryIndex = getRandomNumberInRange(0, 9);
    int subjectIndex = getRandomNumberInRange(0, 9);

    // Print the generated conspiracy theory
    printf("Did you know that %s is behind the %s?\n", subjects[subjectIndex], theories[theoryIndex]);
}

// Main function
int main()
{
    // Seed the random number generator with current time
    srand(time(NULL));

    // Print the title of the program
    printf("Welcome to the Random Conspiracy Theory Generator!\n\n");

    // Generate 5 random conspiracy theories
    for(int i = 1; i <= 5; i++)
    {
        printf("Theory #%d:\n", i);
        generateConspiracyTheory();
        printf("\n");
    }

    return 0;
}