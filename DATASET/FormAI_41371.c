//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Variable to store user's name
    char name[20];

    // Retrieve user's name
    printf("Welcome to the Automated Fortune Teller! Please enter your name:\n");
    scanf("%s", name);

    // Seed the random number generator with current time
    srand(time(NULL));

    // Generate random number between 1 and 5
    int rand_num = rand() % 5 + 1;

    // Use switch statement to output different fortunes
    switch(rand_num)
    {
        case 1:
            printf("\n%s, your fortune is:\n\nYour future looks bright. Keep working hard and success will come.\n", name);
            break;
        case 2:
            printf("\n%s, your fortune is:\n\nYou may have to make some tough decisions in the near future. Trust your instincts and you will make the right choices.\n", name);
            break;
        case 3:
            printf("\n%s, your fortune is:\n\nA surprise opportunity is coming your way. Be prepared to take advantage of it.\n", name);
            break;
        case 4:
            printf("\n%s, your fortune is:\n\nBeware of those who do not have your best interests at heart. Keep your guard up and trust only those who have proven themselves to be trustworthy.\n", name);
            break;
        case 5:
            printf("\n%s, your fortune is:\n\nYou may experience a setback in the near future, but it is only temporary. Keep pushing forward and you will come out stronger.\n", name);
            break;
        default:
            printf("\n%s, something went wrong. Please try again later.\n", name);
    }

    return 0;
}