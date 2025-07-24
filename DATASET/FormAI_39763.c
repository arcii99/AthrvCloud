//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    int i;
    char* theories[] = {"Aliens have infiltrated our government!", 
                        "The moon landing was fake!", 
                        "The Earth is flat!", 
                        "Birds aren't real, they're government drones!", 
                        "Chemtrails are turning us all into mindless robots!",
                        "The Illuminati is controlling our every move!",
                        "The government is hiding the cure for cancer!",
                        "The world is controlled by lizard people!"};
    char* locations[] = {"Area 51", "The Bermuda Triangle", "The Vatican", "Roswell, New Mexico", "Denver International Airport"};
    char* suspects[] = {"The Rothschilds", "The Freemasons", "The Bilderberg Group", "The New World Order", "The Deep State"};

    printf("Welcome to the Random Conspiracy Theory Generator!\n");

    while(1)
    {
        printf("Would you like a conspiracy theory? (Y/N): ");
        char response = getchar();

        if(response == 'N' || response == 'n')
        {
            printf("Thanks for visiting the Random Conspiracy Theory Generator!\n");
            break;
        }

        i = rand() % 8;
        printf("Conspiracy theory: %s\n", theories[i]);

        i = rand() % 5;
        printf("Suspected location: %s\n", locations[i]);

        i = rand() % 5;
        printf("Suspected culprits: %s\n", suspects[i]);

        printf("\n");
        getchar(); // to clear the input buffer
    }

    return 0;
}