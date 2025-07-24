//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL)); // Seed random number generator

    printf("Welcome to the Medieval Fortune Teller!\n");

    // Prompt user for their name
    char name[20];
    printf("What is your name, traveller?\n");
    scanf("%s", name);

    printf("Greetings, %s! Let us divine your future...\n", name);

    // Generate a random number between 1 and 5
    int number = rand() % 5 + 1;

    printf("The spirits have spoken!\n");

    switch(number)
    {
        case 1:
            printf("You shall soon encounter a great fortune, %s!\n", name);
            break;
        case 2:
            printf("Alas, %s, your path will be filled with great danger.\n", name);
            break;
        case 3:
            printf("You will find true love on the morrow, %s!\n", name);
            break;
        case 4:
            printf("The gods will smile upon you, %s, and grant you many blessings.\n", name);
            break;
        case 5:
            printf("Beware the shadows, traveller. A great betrayal is afoot.\n");
            break;
        default:
            printf("The spirits are silent...try asking again later, %s.\n", name);
            break;
    }

    printf("May the gods bless your journey, %s!\n", name);

    return 0;
}