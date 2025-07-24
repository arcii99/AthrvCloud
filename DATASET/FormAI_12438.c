//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL)); // initialize the pseudorandom number generator

    char playAgain = 'Y'; // initialize the play again variable

    // array of possible fortunes
    char *fortunes[] = {
        "You will find true love soon.",
        "You will have great success in your career.",
        "You will inherit a large sum of money.",
        "You will travel to exotic places.",
        "You should be cautious with your investments."
    };
    
    // get the number of fortunes in the array
    int numFortunes = sizeof(fortunes) / sizeof(fortunes[0]);

    printf("Welcome to the Automated Fortune Teller!\n");

    // loop until the user chooses to quit
    while (playAgain == 'Y')
    {
        printf("Press enter to get your fortune...\n");
        getchar(); // wait for user input
        
        int randomIndex = rand() % numFortunes; // get a random fortune index

        printf("Your fortune is: %s\n", fortunes[randomIndex]);

        printf("Do you want to play again? (Y/N)\n");
        fflush(stdin); // clear input buffer 
        scanf("%c", &playAgain); // get user input
    }

    printf("Thank you for playing the Automated Fortune Teller! Goodbye.\n");

    return 0;
}