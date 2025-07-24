//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Initialize random number generator with seed
    srand(time(NULL));
    int randomNumber = rand() % 10 + 1;

    // Print welcome message and ask for user input
    printf("Welcome to the Fortune Teller!\nEnter a number between 1 and 10 to receive your fortune: ");

    // Get user input for luckyNumber
    int luckyNumber;
    scanf("%d", &luckyNumber);

    // Compare user input with random number
    if(luckyNumber == randomNumber)
    {
        printf("\nCongratulations! You are destined for great things today!\n");
    }
    else if(luckyNumber < randomNumber)
    {
        printf("\nHmm... Your luck may not be on your side today. Be careful with your decisions.\n");
    }
    else // luckyNumber > randomNumber
    {
        printf("\nYou have a lot of potential today, but it may require some hard work.\n");
    }

    return 0;
}