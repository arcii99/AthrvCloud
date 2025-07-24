//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    char userInput, response[256];

    srand(time(NULL));

    printf("Welcome to the Automated Fortune Teller Program!\n");
    printf("Please enter your question:\n");

    scanf("%c", &userInput);

    // Compute a random number between 0 and 2 to select the response
    int randNum = rand() % 3;

    switch (randNum)
    {
        case 0:
            snprintf(response, 256, "Based on extensive deduction, your answer is... Yes!");
            break;
        case 1:
            snprintf(response, 256, "The evidence points to a negative... No!");
            break;
        case 2:
            snprintf(response, 256, "I'm afraid the answer is not clear, as if hidden by the fog. Try again later.");
            break;
        default:
            snprintf(response, 256, "Unforeseen error. Please try again later.");
            break;
    }

    // Output the response
    printf("The answer to your question, dear Watson: %s\n", response);

    return 0;
}