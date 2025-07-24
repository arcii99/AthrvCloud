//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: unmistakable
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    printf("Welcome to the C Random Conspiracy Theory Generator!\n\n");
    printf("Press enter to generate a new theory or enter 'exit' to quit\n");

    char input[10];

    while(1)
    {
        fgets(input, sizeof(input), stdin);

        if(input[0] == 'e' && input[1] == 'x' && input[2] == 'i' && input[3] == 't')
        {
            printf("\nGoodbye!\n");
            exit(0);
        }

        printf("\n");

        // Generate random theory
        srand(time(NULL));
        int randomNum = rand() % 10;

        switch(randomNum)
        {
            case 0:
                printf("The government is using chemtrails to brainwash us all into being obedient robots.\n\n");
                break;
            case 1:
                printf("The moon landing was faked to win the Cold War against the Soviet Union.\n\n");
                break;
            case 2:
                printf("The Illuminati is controlling world events from behind the scenes.\n\n");
                break;
            case 3:
                printf("The earth is flat and NASA is covering it up.\n\n");
                break;
            case 4:
                printf("The Loch Ness Monster is a government experiment gone wrong.\n\n");
                break;
            case 5:
                printf("The FBI is spying on us through our electronic devices.\n\n");
                break;
            case 6:
                printf("The Denver International Airport is a secret hub for the New World Order.\n\n");
                break;
            case 7:
                printf("The assassination of JFK was an inside job orchestrated by the CIA.\n\n");
                break;
            case 8:
                printf("The world is controlled by a small group of lizard people.\n\n");
                break;
            case 9:
                printf("The Titanic was sunk on purpose as part of an elaborate insurance fraud.\n\n");
                break;
            default:
                break;
        }

        printf("Press enter to generate a new theory or enter 'exit' to quit\n");
    }

    return 0;
}