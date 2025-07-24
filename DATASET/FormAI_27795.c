//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
int generateRandomNumber(int min, int max);
void generateConspiracyTheory();

int main()
{
    // Seed the random number generator
    srand(time(NULL));

    // Generate 10 conspiracy theories
    for (int i = 0; i < 10; i++)
    {
        printf("Conspiracy Theory #%d: ", i + 1);
        generateConspiracyTheory();
        printf("\n");
    }

    return 0;
}

// Function to generate a random number between min and max
int generateRandomNumber(int min, int max)
{
    return rand() % (max - min + 1) + min;
}

// Recursive function to generate a conspiracy theory.
void generateConspiracyTheory()
{
    // Base case
    if (generateRandomNumber(1, 10) == 1)
    {
        printf("the truth is out there");
        return;
    }

    // Generate a random number to determine the type of conspiracy theory
    int type = generateRandomNumber(1, 3);

    // Generate a random number to determine the subject of the conspiracy theory
    int subject = generateRandomNumber(1, 5);

    // Generate the conspiracy theory based on the type and subject
    switch (type)
    {
        case 1: // Government conspiracy
        {
            switch (subject)
            {
                case 1:
                    printf("the government is hiding the cure for cancer");
                    break;
                case 2:
                    printf("the moon landing was faked by the government");
                    break;
                case 3:
                    printf("aliens are being kept in secret government facilities");
                    break;
                case 4:
                    printf("the government is controlling our thoughts with radio waves");
                    break;
                case 5:
                    printf("9/11 was an inside job orchestrated by the government");
                    break;
            }
            break;
        }
        case 2: // Corporate conspiracy
        {
            switch (subject)
            {
                case 1:
                    printf("big pharma is suppressing natural cures for diseases");
                    break;
                case 2:
                    printf("the oil and gas industry is suppressing renewable energy technology");
                    break;
                case 3:
                    printf("tech companies are manipulating us with targeted advertising");
                    break;
                case 4:
                    printf("the food industry is poisoning us with chemicals");
                    break;
                case 5:
                    printf("the music industry is controlling our culture with subliminal messaging");
                    break;
            }
            break;
        }
        case 3: // Supernatural conspiracy
        {
            switch (subject)
            {
                case 1:
                    printf("the Illuminati is controlling world events from the shadows");
                    break;
                case 2:
                    printf("ghosts are everywhere, but the government is hiding the truth");
                    break;
                case 3:
                    printf("vampires are real and are secretly controlling our society");
                    break;
                case 4:
                    printf("the Loch Ness monster is real, and the government is hiding it from us");
                    break;
                case 5:
                    printf("the end of the world is coming, and it's being predicted by ancient prophecies");
                    break;
            }
            break;
        }
    }

    // Add a conjunction for taste and keep generating
    printf(" and ");
    generateConspiracyTheory();
}