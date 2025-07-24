//FormAI DATASET v1.0 Category: Table Game ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL)); // Seed the random number generator with time

    int num1, num2, sum, ans, tries = 0;
    char choice;

    do
    {
        num1 = rand() % 10; // Generate a random number between 0 and 9
        num2 = rand() % 10; // Generate a random number between 0 and 9
        sum = num1 + num2; // Calculate the sum

        printf("What is %d + %d?\n", num1, num2);
        scanf("%d", &ans); // Read the user's answer

        if (ans == sum) // If the answer is correct
        {
            printf("Congratulations! You got it right!\n");
            tries = 0; // Reset the number of tries
        }
        else // If the answer is incorrect
        {
            printf("Sorry, that's incorrect. Please try again.\n");
            tries++; // Increase the number of tries
        }

        if (tries == 3) // If the user has tried 3 times
        {
            printf("You have failed to answer the question 3 times. Game over!\n");
            break; // End the game
        }
        
        printf("Do you want to play again? (Y/N): ");
        scanf(" %c", &choice); // Read the user's choice

        if (choice == 'N' || choice == 'n') // If the user chooses to quit
        {
            printf("Thanks for playing! Goodbye!\n");
            break; // End the game
        }
    } while (choice == 'Y' || choice == 'y'); // If the user chooses to play again
    
    return 0;
}