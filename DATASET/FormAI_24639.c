//FormAI DATASET v1.0 Category: Random ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    printf("Welcome to the Random Number Generator!\n");
    
    // seed the random number generator
    srand(time(NULL));
    
    printf("Choose a number: ");
    int number;
    scanf("%d", &number);
    
    // generate a random number between 1 and the chosen number
    int random_num = rand() % number + 1;
    
    printf("Your random number is %d!\n", random_num);
    
    // play again option
    char play_again;
    printf("Would you like to play again? (y/n) ");
    scanf(" %c", &play_again);
    if (play_again == 'y' || play_again == 'Y')
    {
        // generate a new random number
        random_num = rand() % number + 1;
        printf("Your new random number is %d!\n", random_num);
    }
    else if (play_again == 'n' || play_again == 'N')
    {
        printf("Thanks for playing!\n");
    }
    else
    {
        printf("Invalid input.\n");
    }
    
    return 0;
}