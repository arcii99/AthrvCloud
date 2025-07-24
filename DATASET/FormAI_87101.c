//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function declarations
void generateConspiracyTheory();
void chooseTopic();
void chooseSubject();
void chooseVerb();
void chooseObject();
void chooseMotive();
void chooseEvidence();

int main()
{
    srand(time(NULL)); // seeding random number generator

    generateConspiracyTheory(); // calling function to generate conspiracy theory

    return 0;
}

void generateConspiracyTheory()
{
    printf("Possible conspiracy theory: ");

    chooseTopic();
    chooseSubject();
    chooseVerb();
    chooseObject();
    chooseMotive();
    chooseEvidence();
}

void chooseTopic()
{
    int topicChoice = rand() % 5; // choosing random number between 0-4

    switch(topicChoice)
    {
        case 0:
            printf("The government ");
            break;
        case 1:
            printf("Aliens ");
            break;
        case 2:
            printf("The Illuminati ");
            break;
        case 3:
            printf("The pharmaceutical industry ");
            break;
        case 4:
            printf("Big Tech ");
            break;
        default:
            printf("Error: Invalid topic choice");
            exit(0);
    }
}

void chooseSubject()
{
    int subjectChoice = rand() % 4; // choosing random number between 0-3

    switch(subjectChoice)
    {
        case 0:
            printf("is hiding ");
            break;
        case 1:
            printf("is controlling ");
            break;
        case 2:
            printf("is manipulating ");
            break;
        case 3:
            printf("is experimenting on ");
            break;
        default:
            printf("Error: Invalid subject choice");
            exit(0);
    }
}

void chooseVerb()
{
    int verbChoice = rand() % 4; // choosing random number between 0-3

    switch(verbChoice)
    {
        case 0:
            printf("the truth about ");
            break;
        case 1:
            printf("the minds of ");
            break;
        case 2:
            printf("the weather patterns of ");
            break;
        case 3:
            printf("the technology used by ");
            break;
        default:
            printf("Error: Invalid verb choice");
            exit(0);
    }
}

void chooseObject()
{
    int objectChoice = rand() % 4; // choosing random number between 0-3

    switch(objectChoice)
    {
        case 0:
            printf("the general population ");
            break;
        case 1:
            printf("the economy ");
            break;
        case 2:
            printf("the environment ");
            break;
        case 3:
            printf("the food supply ");
            break;
        default:
            printf("Error: Invalid object choice");
            exit(0);
    }
}

void chooseMotive()
{
    int motiveChoice = rand() % 4; // choosing random number between 0-3

    switch(motiveChoice)
    {
        case 0:
            printf("in order to gain power and control.");
            break;
        case 1:
            printf("as part of a global conspiracy.");
            break;
        case 2:
            printf("to create a new world order.");
            break;
        case 3:
            printf("for financial gain.");
            break;
        default:
            printf("Error: Invalid motive choice");
            exit(0);
    }
}

void chooseEvidence()
{
    int evidenceChoice = rand() % 4; // choosing random number between 0-3

    switch(evidenceChoice)
    {
        case 0:
            printf("\nEvidence includes leaked documents and whistleblowers.");
            break;
        case 1:
            printf("\nEvidence is hidden and difficult to find.");
            break;
        case 2:
            printf("\nEvidence is in plain sight but ignored by the mainstream media.");
            break;
        case 3:
            printf("\nEvidence is fabricated by the government or other agencies.");
            break;
        default:
            printf("\nError: Invalid evidence choice");
            exit(0);
    }
}